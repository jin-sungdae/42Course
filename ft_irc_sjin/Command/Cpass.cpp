#include "./Cpass.hpp"

void Cpass::execute(ChannelManager &channelManager, UserManager &userManager, Network &network, struct CommandChunk commandChunk)
{
	User *user = userManager.getUserByFd(commandChunk.fd);
	vector<string> param = commandChunk.parameters;
	(void)channelManager;
	
	if (user->getIsRegistered())
	{
		string msg = UserManager::makeMessage(NULL, ERR_ALREADYREGISTERED, user->getNickname(), "User is already registered");
		network.sendToUser(user->getFd(), msg);
	}
	else if (user->getPassOK())
	{
		string msg = UserManager::makeMessage(NULL, ERR_ALREADYCONNECTED, "*", "User doesn't need password anymore");
		network.sendToUser(user->getFd(), msg);
	}
	else if (param.size() == 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Not enough parameters");
		network.sendToUser(user->getFd(), msg);
	}
	else if (param.size() != 1 || commandChunk.parameterLast.size() != 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_TOOMANYPARAM, user->getNickname(), "Too Many Parameters");
		network.sendToUser(user->getFd(), msg);
	}
	else
	{
		string password = param[0];
		user->setPasswd(password);
	}
}