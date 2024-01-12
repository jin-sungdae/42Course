#ifndef __USER_HPP__
#define __USER_HPP__
#include "../defines.hpp"
#include "../Channel/Channel.hpp"

class User
{
public:
	User();
	User(const string nickname, const string userName);
	~User();
	void setNickname(const string nickName);
	void setUserName(const string userName);
	void setFd(const int fd);
	void setRealName(const string realName);
	void setPasswd(const string passwd);
	void setBuffer(const string buffer);
	void setPassOK(const bool passOK);
	void setNickOK(const bool nickOK);
	void setUserOK(const bool nickOK);
	void setIsRegistered(const bool isRegistered);
	void setIgnored(const bool ignore);
	void addChannel(Channel *channel);
	string getNickname() const;
	string getUserName() const;
	string getPasswd() const;
	string getBuffer() const;
	string getRealName() const;
	Channel* getChannel(const string channelName);
	map<string, Channel*>& getChannelList();
	bool getPassOK() const;
	bool getNickOK() const;
	bool getUserOK() const;
	bool getIsRegistered() const;
	int getFd() const;
	bool getIgnored() const;
	void appendBuffer(string buffer);
	void deleteChannel(const string channelName);

private:
	string nickname;
	string userName;
	string realName;
	string passwd;
	int	fd;
	string buffer;
	map<string, Channel *> channelList;
	bool passOK;
	bool nickOK;
	bool userOK;
	bool isRegistered;
	bool ignored;
};

#endif