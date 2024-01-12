#include "Cquit.hpp"

void Cquit::execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk)
{
	User *user = userManager.getUserByFd(commandChunk.fd);
	vector<string> param = commandChunk.parameters;
	(void)channelManager;
	
	if (user->getIsRegistered() == false)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOTREGISTERED, user->getNickname(), "You should register first");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	map<string, Channel*>::iterator iter = user->getChannelList().begin();
	map<string, Channel*>::iterator iterEnd = user->getChannelList().end();
	string last = commandChunk.parameterLast;
	string reason = ":" + (last.size() == 0 ? "Leaving..." : last);
	for (;iter != iterEnd; iter++)
	{
		string msg = UserManager::makeMessage(user, RPL_QUIT, reason, "");
		network.sendToOtherInChannel(*iter->second, user->getFd(), msg);
		iter->second->deleteJoinUser(user);
	}
	int fd = user->getFd();
	userManager.deleteUser(fd);
	close(fd);
}