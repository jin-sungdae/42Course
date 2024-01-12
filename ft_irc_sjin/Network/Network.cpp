#include "Network.hpp"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <fcntl.h>
#include "../defines.hpp"
#include "../User/User.hpp"
#include "../User/UserManager.hpp"
#include "../Channel/ChannelManager.hpp"
#include <cerrno>

using namespace std;


Network::Network(const short port, const char* passWord, UserManager& userManager, ChannelManager& channelManager, Logger& argLogger)
: PORT(port), PASSWORD(passWord), userManager(userManager), channelManager(channelManager), logger(argLogger)
{
	memset(&this->addressServer, 0, sizeof(this->addressServer));
};

bool isZero(void* data, size_t size)
{
	char c = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (*((char *)data + i) != c)
		{
			return false;
		}
	}
	return true;
}

Network::~Network()
{
	if (!isZero(&this->addressServer, sizeof(this->addressServer)))
	{
		close(this->fdServer);
	}
};

bool Network::init()
{
	int result = 1;

	if (this->logger.shouldServerDown())
	{
		fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
		fcntl(STDOUT_FILENO, F_SETFL, O_NONBLOCK);
		fcntl(STDERR_FILENO, F_SETFL, O_NONBLOCK);
		return false;
	}
	this->addressServer.sin_family = PF_INET;
	this->addressServer.sin_port = htons(this->PORT);
	this->addressServer.sin_addr.s_addr = htonl(INADDR_ANY);
	this->fdServer = socket(AF_INET, SOCK_STREAM, 0);
	if (this->fdServer < 0)
	{
		this->logger.errorLogging(string("\033[31m[socket]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	if (setsockopt(this->fdServer, SOL_SOCKET, SO_REUSEADDR, &result, sizeof(result)))
	{
		this->logger.errorLogging(string("\033[31m[setsockopt]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	if (fcntl(this->fdServer, F_SETFL, O_NONBLOCK) < 0 | fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK) < 0 |
		fcntl(STDOUT_FILENO, F_SETFL, O_NONBLOCK) < 0 | fcntl(STDERR_FILENO, F_SETFL, O_NONBLOCK) < 0)
	{
		this->logger.errorLogging(string("\033[31m[fcntl]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	this->logger.logging("\033[32mSocket init Success!\033[0m");
	if (::bind(this->fdServer, reinterpret_cast<sockaddr*>(&this->addressServer), sizeof(this->addressServer)) < 0)
	{
		this->logger.errorLogging(string("\033[31m[bind]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	this->logger.logging("\033[32mSocket binding Success!\033[0m");
	if(::listen(this->fdServer, 5) < 0)
	{
		this->logger.errorLogging(string("\033[31m[listen]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	this->logger.logging("\033[32mServer is listening!\033[0m");
	return true;
};

void Network::initFdSets()
{
	FD_ZERO(&this->rSet);
	FD_ZERO(&this->wSet);
	FD_SET(STDIN_FILENO, &this->rSet);
	if (!this->logger.isLogEmpty())
	{
		FD_SET(STDOUT_FILENO, &this->wSet);
	}
	if (!this->logger.isErrorLogEmpty())
	{
		FD_SET(STDERR_FILENO, &this->wSet);
	}
	map<int, User*>::iterator iter =  this->userManager.getUserListByFd().begin();
	map<int, User*>::iterator iterEnd =  this->userManager.getUserListByFd().end();
	FD_SET(this->fdServer, &this->rSet);
	for (; iter != iterEnd; iter++)
	{
		FD_SET(iter->first, &this->rSet);
	}
	map<int, vector<string> >::iterator iterMap = this->sendMap.begin();
	map<int, vector<string> >::iterator iterMapEnd = this->sendMap.end();
	for (; iterMap != iterMapEnd; iterMap++)
	{
		FD_SET(iterMap->first, &this->wSet);
	}
}

bool Network::AcceptUser()
{
	sockaddr_in addressClient;
	socklen_t lenClient = sizeof(addressClient);

	int fdClient = ::accept(this->fdServer, reinterpret_cast<sockaddr*>(&addressClient), &lenClient);
	if (fdClient < 0) 
	{
		this->logger.errorLogging(string("[setsockopt]") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	if (fcntl(fdClient, F_SETFL, O_NONBLOCK) < 0)
	{
		this->logger.errorLogging(string("\033[31m[fcntl]\033[0m") + strerror(errno));
		this->logger.setServerDown(true);
		return false;
	}
	this->userManager.makeUser(fdClient);
	return true;
}

bool Network::sendToUser(int fd, const std::string& message)
{
	map<int, vector<string> >::iterator iter = this->sendMap.find(fd);

	if (iter == this->sendMap.end())
	{
		vector<string> tempVec;
		tempVec.push_back(message);
		this->sendMap[fd] = tempVec;
	}
	else
	{
		iter->second.push_back(message);
	}
	return true;
}

bool Network::sendToChannel(Channel& channel, const std::string& message)
{
	map<std::string, User *>::iterator iter = channel.getJoinUser().begin();
	map<std::string, User *>::iterator iterEnd = channel.getJoinUser().end();

	while (iter != iterEnd)
	{
		this->sendToUser(iter->second->getFd(), message);
		++iter;
	}
	return true;
}

bool Network::sendToOtherInChannel(Channel& channel, int fd, const std::string& message)
{
	map<std::string, User *>::iterator iter = channel.getJoinUser().begin();
	map<std::string, User *>::iterator iterEnd = channel.getJoinUser().end();

	while (iter != iterEnd)
	{
		if (iter->second->getFd() != fd)
		{
			this->sendToUser(iter->second->getFd(), message);
		}
		++iter;
	}
	return true;
}

CommandChunk Network::getCommand()
{
	CommandChunk tempChunk;

	tempChunk.fd = -1;
	if (!this->commandQueue.empty())
	{
		tempChunk = this->commandQueue.front();
		this->commandQueue.pop();
	}
	return tempChunk;
}

void Network::pushCmdToQueue(int fd, string cmd)
{
	CommandChunk tempChunk;

	if (cmd.find("  ") != string::npos\
	|| cmd.find(9) != string::npos || cmd.find(11) != string::npos || cmd.find(12) != string::npos)
	{
		User *user = this->userManager.getUserByFd(fd);
		this->sendToUser(user->getFd(), string(UserManager::makeMessage(NULL, ERR_WRONGPROTOCOL, user->getNickname(), "Wrong protocol")));
		return ;
	} 
	tempChunk.fd = fd;
	if (cmd[0] == ':')
	{
		if (cmd.find(' ') == string::npos)
		{
			tempChunk.prefix.assign(cmd, 0, cmd.size());
			this->commandQueue.push(tempChunk);
			return;
		}
		else
		{
			tempChunk.prefix.assign(cmd, 0, cmd.find(' '));
			cmd.assign(cmd, cmd.find(' ') + 1, cmd.size() - cmd.find(' ') - 1);
		}
	}
	if (cmd.find(' ') == string::npos)
	{
		tempChunk.command.assign(cmd, 0, cmd.size());
		this->commandQueue.push(tempChunk);
		return;
	}
	else
	{
		tempChunk.command.assign(cmd, 0, cmd.find(' '));
		cmd.assign(cmd, cmd.find(' ') + 1, cmd.size() - cmd.find(' ') - 1);
	}
	while (1)
	{
		if (cmd.size() == 0)
		{
			break ;
		}
		else if (cmd[0] == ':')
		{
			tempChunk.parameterLast.assign(cmd, 1 , cmd.size() - 1);
			this->commandQueue.push(tempChunk);
			return;
		}
		else if (cmd.find(' ') == string::npos)
		{
			tempChunk.parameters.push_back(string(cmd, 0, cmd.size()));
			this->commandQueue.push(tempChunk);
			return;
		}
		else
		{
			tempChunk.parameters.push_back(string(cmd, 0, cmd.find(' ')));
			cmd.assign(cmd, cmd.find(' ') + 1, cmd.size() - cmd.find(' ') - 1);
		}
	}
	this->commandQueue.push(tempChunk);
}

void Network::disconnectUser(User* user)
{
	int userFd = user->getFd();
	map<string, Channel*>::iterator iter = user->getChannelList().begin();
	map<string, Channel*>::iterator iterEnd = user->getChannelList().end();

	for (;iter != iterEnd; iter++)
	{
		string msg = UserManager::makeMessage(user, RPL_QUIT, ":Leaving...", "");
		this->sendToOtherInChannel(*iter->second, userFd, msg);
		this->channelManager.getChannel(iter->second->getChannelName())->deleteJoinUser(user);
	}
	this->sendMap.erase(userFd);
	this->userManager.deleteUser(userFd);
	close(userFd);
}

void Network::recvParsingAndLoadCommands(User* user, char* bufferRecv, size_t lenRecv)
{
	user->appendBuffer(string(bufferRecv, lenRecv));
	while(1)
	{
		if (user->getBuffer().empty())
		{
			break;
		}
		size_t crlfIndex = user->getBuffer().find("\r\n");
		if (user->getIgnored())
		{
			if (crlfIndex == string::npos)
			{
				user->setBuffer("");
			}
			else
			{
				user->setBuffer(string(user->getBuffer().substr(crlfIndex + 2, user->getBuffer().size() - crlfIndex - 2)));
				user->setIgnored(false);
			}
		}
		else
		{
			if (user->getBuffer().size() <= BUFFERSIZE - 2 && crlfIndex == string::npos)
			{
				break;
			}
			else if (user->getBuffer().size() > BUFFERSIZE - 2 && crlfIndex > BUFFERSIZE - 2)
			{
				pushCmdToQueue(user->getFd(), string(user->getBuffer(), 0, BUFFERSIZE - 2).append("\r\n"));
				if (crlfIndex != string::npos)
				{
					user->setBuffer(string(user->getBuffer().substr(crlfIndex + 2, user->getBuffer().size() - crlfIndex - 2)));
				}
				else
				{
					user->setBuffer("");
					user->setIgnored(true);
				}
				break;
			}
			else
			{
				pushCmdToQueue(user->getFd(), string(user->getBuffer(), 0, crlfIndex));
				user->setBuffer(string(user->getBuffer().substr(crlfIndex + 2, user->getBuffer().size() - crlfIndex - 2)));
			}
		}
	}
}

void Network::recvActionPerUser(map<int, User*>& users)
{
	int lenRecv;
	char bufferRecv[BUFFERSIZE];

	for(map<int, User*>::iterator iter = users.begin(); iter != users.end();)
	{
		if (FD_ISSET(iter->first, &this->rSet))
		{
			User* user = this->userManager.getUserByFd(iter->first);
			lenRecv = ::recv(iter->first, bufferRecv, BUFFERSIZE, 0);
			if (lenRecv < 0)
			{
				++iter;
				this->logger.errorLogging(string("[recv]") + strerror(errno));
				disconnectUser(user); 
				continue;
			}
			else if (lenRecv == 0)
			{
				++iter;
				disconnectUser(user);
				continue ;
			}
			else
			{
				recvParsingAndLoadCommands(user, bufferRecv, lenRecv);
			}
		}
		++iter;
	}
}

void Network::sendActionPerSendQueue()
{
	for (map<int, vector<string> >::iterator iter = this->sendMap.begin(); iter != this->sendMap.end();)
	{
		map<int, vector<string> >::iterator tempMap = iter;
		if (FD_ISSET(iter->first, &this->wSet))
		{
			for (vector<string>::iterator iterVec = iter->second.begin(); iterVec != iter->second.end();)
			{
				if (::send(iter->first, iterVec->c_str(), iterVec->size(), 0) < 0)
				{
					User* user = this->userManager.getUserByFd(iter->first);
					this->logger.errorLogging(string("[send]") + strerror(errno));
					disconnectUser(user);
					break ;
				}
				++iterVec;
			}
			++iter;
			this->sendMap.erase(tempMap->first);
		}
		else
		{
			++iter;
		}
	}
}

int Network::IOMultiflexing()
{
	string tempBuffer;

	this->initFdSets();
	if (::select(FD_SETSIZE, &this->rSet, &this->wSet, NULL, NULL) < 0)
	{
		this->logger.errorLogging(string("[select]") + strerror(errno));
		this->logger.setServerDown(true);
	}
	if (FD_ISSET(STDIN_FILENO, &this->rSet))
	{
		while (getchar() != '\n');
		return SERVERDOWN;
	}
	if (FD_ISSET(this->fdServer, &this->rSet))
	{
		if (!this->AcceptUser())
		{
			return SERVERDOWN;
		}
	}
	if (FD_ISSET(STDOUT_FILENO, &this->wSet))
	{
		while (1)
		{
			if (this->logger.isLogEmpty())
			{
				break ;
			}
			string tempLog = this->logger.getLog();
			write(STDOUT_FILENO, tempLog.append("\n").c_str(), tempLog.size());
		}
	}
	if (FD_ISSET(STDERR_FILENO, &this->wSet))
	{
		while (1)
		{
			if (this->logger.isErrorLogEmpty())
			{
				break ;
			}
			string tempLog = this->logger.getErrorLog();
			write(STDERR_FILENO, tempLog.append("\n").c_str(), tempLog.size());
		}
		if (this->logger.shouldServerDown() == true)
		{
			return FALSE;
		}
	}
	this->recvActionPerUser(this->userManager.getUserListByFd());
	this->sendActionPerSendQueue();
	return SUCCESS;
}