#include "Ckick.hpp"

void Ckick::execute(ChannelManager &channelManager,
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
	if (param.size() != 2)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NEEDMOREPARAMS, user->getNickname(), "Not Proper parameters");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	string channelName = param[0];
	string targetUser = param[1];
	Channel *channel = channelManager.getChannel(channelName);
	if (!channel)
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOSUCHCHANNEL, user->getNickname(), "No Such Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (!user->getChannel(channelName))
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOTONCHANNEL, user->getNickname(), "User is Not in Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (channel->getOperators().count(user->getFd()) == 0)
	{
		string msg = UserManager::makeMessage(NULL, ERR_CHANOPRIVSNEEDED, user->getNickname(), "Need Operation");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	User *target = channel->selectJoinUser(targetUser);
	if (!target)
	{
		string msg = UserManager::makeMessage(NULL, ERR_USERNOTINCHANNEL, user->getNickname(), "Target User is Not in Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	string msg = UserManager::makeMessage(user, RPL_KICK, channel->getChannelName() + " " + targetUser, "");
	network.sendToChannel(*channel, msg);
	target->deleteChannel(channel->getChannelName());
	channel->deleteJoinUser(target);
}
