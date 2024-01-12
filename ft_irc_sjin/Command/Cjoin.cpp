#include "Cjoin.hpp"

void Cjoin::execute(ChannelManager &channelManager,
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
	const string channelName = param[0];
	string password = param.size() > 1 ? param[1] : "";
	Channel *channel = user->getChannel(channelName);

	if (channel)
	{
		string msg = UserManager::makeMessage(NULL, ERR_USERONCHANNEL, user->getNickname(), "Already in the channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	channel = channelManager.getChannel(channelName);
	if (!channel)
	{
		channel = channelManager.createChannel(param[0], password, user);
	}
	if (channel->getCurSizeUser() >= channel->getMaxSizeUser())
	{
		string msg = UserManager::makeMessage(NULL, ERR_CHANNELISFULL , user->getNickname(), "channel is full");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (channel->getChannelKey() != password)
	{
		string msg = UserManager::makeMessage(NULL, ERR_BADCHANNELKEY , user->getNickname(), "no match password error");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	channel->insertJoinUser(user);
	user->addChannel(channel);
	string msg = UserManager::makeMessage(user, RPL_JOIN, channel->getChannelName(), "");
	network.sendToChannel(*channel, msg);
	string list = "";
	map<string, User *> users = channel->getJoinUser();
	map<string, User *>::iterator iter = users.begin();
	map<string, User *>::iterator iterEnd = users.end();
	for (; iter != iterEnd; iter++)
	{
		if (iter != users.begin())
		{
			list += " ";
		}
		if (channel->getOperators().count(iter->second->getFd()) == 1)
		{
			list += "@";
		}
		list += iter->second->getNickname();
	}
	string msg2 = UserManager::makeMessage(NULL, RPL_NAMREPLY, user->getNickname()+ " = " + channel->getChannelName(), list);
	network.sendToUser(user->getFd(), msg2);
	string msg3 = UserManager::makeMessage(NULL, RPL_ENDOFNAMES, user->getNickname() + " " + channel->getChannelName(), "End of /NAMES list.");
	network.sendToUser(user->getFd(), msg3);
}