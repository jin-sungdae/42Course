#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../User/UserManager.hpp"
#include "../Channel/ChannelManager.hpp"
#include "../Logger/Logger.hpp"

struct CommandChunk
{
	int fd;
	std::string prefix;
	std::string command;
	std::vector<std::string> parameters;
	std::string parameterLast;
};

class Network
{
public:
	Network();
	Network(const short port, const char* passWord, UserManager& userManager, ChannelManager& channelManager, Logger& argLogger);
	~Network();
	bool init();
	int IOMultiflexing();
	bool sendToUser(int fd, const std::string& message);
	bool sendToChannel(Channel& channel, const std::string& message);
	bool sendToOtherInChannel(Channel& channel, int fd, const std::string& message);
	void disconnectUser(User* user);
	CommandChunk getCommand();
private:
	Network(const Network& other);
	Network& operator=(const Network& other);
	bool AcceptUser();
	void pushCmdToQueue(int fd, string cmd);
	void prtCmd(int fd);
	void recvActionPerUser(map<int, User*>& users);
	void recvParsingAndLoadCommands(User* user, char* bufferRecv, size_t lenRecv);
	void sendActionPerSendQueue();
	void initFdSets();

	fd_set wSet;
	fd_set rSet;
	sockaddr_in addressServer;
	const short PORT;
	const std::string PASSWORD;
	UserManager& userManager;
	ChannelManager& channelManager;
	int fdServer;
	queue<CommandChunk> commandQueue;
	map<int, vector<string> > sendMap;
	bool exitFlag;
	Logger& logger;
};

#endif