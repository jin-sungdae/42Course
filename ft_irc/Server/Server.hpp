#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include "../defines.hpp"
#include "../User/UserManager.hpp"
#include "../Channel/ChannelManager.hpp"
#include "../Network/Network.hpp"
#include "../Command/ICommand.hpp"
#include "../Logger/Logger.hpp"

class Server
{
public:
    Server(Logger& argLogger);
    Server(const short port, const char* passWord, Logger& argLogger);
    bool init();
    void checkRegister(User* user);
    int run();
    ~Server();

private:
    Server();
    UserManager userManager;
    ChannelManager channelManager;
    map<string, ICommand *> commands;
    Network network;
    Logger& logger;
    const string PASSWORD;
};

#endif