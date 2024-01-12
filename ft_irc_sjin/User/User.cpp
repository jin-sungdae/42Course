#include "User.hpp"

User::User()
{
	this->nickname = "*";
	this->userName = "";
	this->realName = "";
	this->passwd = "";
	this->fd = 0;
	this->buffer = "";
	this->isRegistered = false;
	this->nickOK = false;
	this->passOK = false;
	this->userOK = false;
	this->ignored = false;
}

User::User(const std::string nickname, const std::string userName) : nickname(nickname), userName(userName)
{}

User::~User()
{}

void User::setNickname(const std::string nickname)
{
	this->nickname = nickname;
}

void User::setUserName(const std::string userName)
{
	this->userName = userName;
}

void User::setRealName(const std::string realName)
{
	this->realName = realName;
}

void User::setFd(const int fd)
{
	this->fd = fd;
}

void User::setBuffer(const string buffer)
{
	this->buffer = buffer;
}

void User::setIsRegistered(const bool isRegistered)
{
	this->isRegistered = isRegistered;
}

void User::setPassOK(const bool passOK)
{
	this->passOK = passOK;
}

void User::setNickOK(const bool nickOK)
{
	this->nickOK = nickOK;
}

void User::setUserOK(const bool userOK)
{
	this->userOK = userOK;
}

void User::setIgnored(const bool ignore)
{
	this->ignored = ignore;
}

void User::setPasswd(const string passwd)
{
	this->passwd = passwd;
}

void User::addChannel(Channel *channel)
{
	this->channelList[channel->getChannelName()] = channel;
}

std::string User::getNickname() const
{
	return this->nickname;
}

std::string User::getUserName() const
{
	return this->userName;
}

int User::getFd() const
{
	return this->fd;
}

string User::getBuffer() const
{
	return this->buffer;
}

bool User::getIsRegistered() const
{
	return this->isRegistered;
}

bool User::getPassOK() const
{
	return this->passOK;
}

bool User::getNickOK() const
{
	return this->nickOK;
}

bool User::getUserOK() const
{
	return this->userOK;
}

bool User::getIgnored() const
{
	return this->ignored;
}

string User::getRealName() const
{
	return this->realName;
}

string User::getPasswd() const
{
	return this->passwd;
}

Channel* User::getChannel(const string channelName)
{
	if (this->channelList.count(channelName) == 0)
		return NULL;
	return this->channelList[channelName];
}

map<string, Channel*>& User::getChannelList()
{
	return this->channelList;
}

void User::appendBuffer(string buffer)
{
	this->buffer.append(buffer);
}

void User::deleteChannel(const string channelName)
{
	this->channelList.erase(channelName);
}