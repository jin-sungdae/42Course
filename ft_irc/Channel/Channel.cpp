#include "Channel.hpp"
#include "../User/User.hpp"

Channel::Channel()
{
	this->channelName = "default";
	this->maxSizeUser = 10;
	this->curSizeUser = 0;
}

Channel::Channel(const std::string channelName) : channelName(channelName)
{}

Channel::~Channel()
{}

void Channel::setChannelName(const std::string channelName)	
{
	this->channelName = channelName;
}

void Channel::setCurSizeUser(const int size)
{
	this->curSizeUser = size;
}

void Channel::setChannelKey(const string channelKey)
{
	this->channelKey = channelKey;
}

void Channel::addOperator(int fd)
{
	this->operators.insert(fd);
}

string Channel::getChannelName() const
{
	return this->channelName;
}

string Channel::getChannelKey() const
{
	return this->channelKey;
}

int Channel::getCurSizeUser() const
{
	return this->curSizeUser;
}

int Channel::getMaxSizeUser() const
{
	return this->maxSizeUser;
}

void Channel::insertJoinUser(User* user) 
{	
	if (this->joinUser.count(user->getNickname()) == 0)
	{
		this->joinUser[user->getNickname()] = user;
		this->curSizeUser++;
	}
}

User* Channel::selectJoinUser(string userName)
{
	if (this->joinUser.count(userName) == 1)
	{
		return joinUser[userName];
	}
	return NULL;
}

void Channel::deleteJoinUser(User *user) 
{
	if (this->joinUser.count(user->getNickname()) == 1)
	{
		joinUser.erase(user->getNickname());
		this->curSizeUser--;
		this->deleteOperator(user->getFd());
	}
}

map<string, User *>& Channel::getJoinUser()
{
	return this->joinUser;
}

set<int> & Channel::getOperators()
{
	return this->operators;
}

void Channel::deleteOperator(int fd)
{
	if (operators.count(fd) == 1)
	{
		operators.erase(fd);
	}
}
