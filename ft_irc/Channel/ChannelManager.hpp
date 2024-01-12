#ifndef __CHANNELMANAGER_HPP__
#define __CHANNELMANAGER_HPP__


#include "../defines.hpp"
#include "./Channel.hpp"

class User;

class ChannelManager
{
public:
	ChannelManager();
	~ChannelManager();
	Channel* getChannel(const string channelName);
	Channel *createChannel(const string channelName, const string passwd, User *user);

private:
	map<string, Channel *> channel_list;
};

#endif