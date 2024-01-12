#include "Cmode.hpp"

void Cmode::execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk)
{
    User *user = userManager.getUserByFd(commandChunk.fd);
	vector<string> param = commandChunk.parameters;

    if (user->getIsRegistered() == false)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOTREGISTERED, user->getNickname(), "You should register first");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (param.empty())
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Not enough parameters");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (param.size() == 2 || param.size() == 1)
	{
		return;
	}
	if (param.size() != 3)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Need Three parameters");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (param[1] != "+o" && param[1] != "-o")
	{
		string msg = UserManager::makeMessage(NULL, ERR_UMODEUNKNOWNFLAG, user->getNickname(), "UNKNOWN FLAG ERROR");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	const string channelName = param[0];
	Channel *channel = channelManager.getChannel(channelName);
	if (!channel)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOSUCHCHANNEL, user->getNickname(), "No Such Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (channel->getJoinUser().count(user->getNickname()) == 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_USERNOTINCHANNEL, user->getNickname(), "User Not In Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (channel->getJoinUser().count(param[2]) == 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_USERNOTINCHANNEL, user->getNickname(), "Target Not In Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (channel->getOperators().count(user->getFd()) == 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_CHANOPRIVSNEEDED, user->getNickname(), "Need Operation");
		network.sendToUser(user->getFd(), msg);
		return;
	}

	if (param[1] == "+o")
	{
		map<string, User *> userList = channel->getJoinUser();
		User *tempUser = userList[param[2]];
		channel->addOperator(tempUser->getFd());
		string msg = UserManager::makeMessage(NULL, RPL_MODE, channel->getChannelName() + " +o " + tempUser->getNickname(),  "");
		network.sendToChannel(*channel, msg);
	}
	else
	{
		map<string, User *> userList = channel->getJoinUser();
		User *tempUser = userList[param[2]];
		channel->getOperators().erase(tempUser->getFd());
		string msg = UserManager::makeMessage(NULL, RPL_MODE, channel->getChannelName() + " -o " + tempUser->getNickname(),  "");
		network.sendToChannel(*channel, msg);
	}
}