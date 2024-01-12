#include "./Cuser.hpp"

void Cuser::execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk)
{
	User *user = userManager.getUserByFd(commandChunk.fd);
	vector<string> param = commandChunk.parameters;
	(void)channelManager;

	if (user->getPassOK() == false)
	{		
		string msg = UserManager::makeMessage(NULL, ERR_NOTCONNECTED, "*", "User should be connected first");
		network.sendToUser(user->getFd(), msg);
	}
	else if (user->getIsRegistered())
	{
		string msg = UserManager::makeMessage(NULL, ERR_ALREADYREGISTERED, user->getNickname(), "User is already registered");
		network.sendToUser(user->getFd(), msg);
	}
	else if (param.size() < 3)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Not enough parameters");
		network.sendToUser(user->getFd(), msg);
	}
	else
	{
		user->setUserName(param[0]);
		if (commandChunk.parameterLast.size() == 0 && param.size() == 4)
		{
			user->setRealName(param[3]);
		}
		else if (commandChunk.parameterLast.size() != 0)
		{
			user->setRealName(commandChunk.parameterLast);
		}
		user->setUserOK(true);
	}
}

