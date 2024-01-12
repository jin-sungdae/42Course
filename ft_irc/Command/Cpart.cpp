#include "Cpart.hpp"

void Cpart::execute(ChannelManager &channelManager,
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
	string channelName = param[0];
	if (channelName[0] != '#')
	{
		channelName = "#" + channelName;
	}
	Channel *channel = channelManager.getChannel(channelName);
	if (!channel) 
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOSUCHCHANNEL, user->getNickname(), "No Such Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	if (!user->getChannel(channelName)) 
	{
		string msg = UserManager::makeMessage(NULL, ERR_NOTONCHANNEL, user->getNickname(), "Not On Channel");
		network.sendToUser(user->getFd(), msg);
		return;
	}
	string msg = UserManager::makeMessage(user, RPL_PART, channelName, "");
	network.sendToChannel(*channel, msg);
	channel->deleteJoinUser(user);
	user->deleteChannel(channelName);
}