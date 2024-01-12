#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__

#include "../defines.hpp"

class User;

class Channel
{
public:
	Channel();
	~Channel();
	Channel(const std::string channelName);
	void setChannelName(const string channelName);
	void setChannelKey(const string channelKey);
	void addOperator(int fd);
	void setCurSizeUser(const int size);
	string getChannelName() const;
	string getChannelKey() const;
	int getCurSizeUser() const;
	int getMaxSizeUser() const;
	void insertJoinUser(User *user);
	User* selectJoinUser(string userName);
	void deleteJoinUser(User *user);
	map<string, User *>& getJoinUser();
	set<int> & getOperators();
	void deleteOperator(int fd);

private:
	string channelName;
	string channelKey;
	map<string, User *> joinUser;
	set<int> operators;
	int maxSizeUser;
	int curSizeUser;
};

#endif