#include "ChannelManager.hpp"
#include "../User/User.hpp"

ChannelManager::ChannelManager()
{}

ChannelManager::~ChannelManager()
{
	map<string, Channel *>::iterator iter = this->channel_list.begin();
	map<string, Channel *>::iterator iterEnd = this->channel_list.end();
	for (; iter != iterEnd; iter++)
	{
		delete iter->second;
	}
}

Channel* ChannelManager::getChannel(const string channelName)
{
	if (this->channel_list.count(channelName) == 0)
		return NULL;
	return this->channel_list[channelName];
}

Channel* ChannelManager::createChannel(const string channelName, string passwd, User* user)
{
	Channel *channel = new Channel;
	channel->setChannelName(channelName.substr(0, min(static_cast<int>(channelName.size()), 50)));
	channel->setChannelKey(passwd);
	channel->insertJoinUser(user);
	this->channel_list[channel->getChannelName()] = channel;
	channel->addOperator(user->getFd());
	return channel;
}