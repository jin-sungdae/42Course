#include "Cprivmsg.hpp"

void Cprivmsg::execute(ChannelManager &channelManager,
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
	if (param.size() < 1)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Not enough parameters");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	string target = param[0];
	string message;
	vector<string>::iterator iter = param.begin();
	vector<string>::iterator iterEnd = param.end();
	iter++;
	for (; iter != iterEnd; iter++)
	{
		message += *iter + " ";
	}
	if (commandChunk.parameterLast.size() != 0)
	{
		message += (message.size() == 0 ? "" : ":") + commandChunk.parameterLast;
	}
	if (target[0] == '#')
	{
		Channel *targetChannel = channelManager.getChannel(target);
		if (!targetChannel)
		{
			string msg = UserManager::makeMessage(NULL, ERR_NOSUCHCHANNEL, user->getNickname(), "No such channel");
			network.sendToUser(user->getFd(), msg);
		}
		else if (targetChannel->getJoinUser().count(user->getNickname()) == 0)
		{
			string msg = UserManager::makeMessage(NULL, ERR_USERNOTINCHANNEL, user->getNickname(), "User Not In Channel");
			network.sendToUser(user->getFd(), msg);
		}
		else
		{
			string msg = UserManager::makeMessage(user, RPL_PRIVMSG, targetChannel->getChannelName(), message);
			network.sendToOtherInChannel(*targetChannel, user->getFd(), msg);
		}
	}
	else
	{
		User *targetUser = userManager.getUserByNickname(target);
		if (!targetUser)
		{
			string msg = UserManager::makeMessage(NULL, ERR_NOSUCHNICK, user->getNickname(), "No Such Nick");
			network.sendToUser(user->getFd(), msg);
		}
		else
		{
			string msg = UserManager::makeMessage(user, RPL_PRIVMSG, targetUser->getNickname(), message);
			network.sendToUser(targetUser->getFd(), msg);
		}
	}
}