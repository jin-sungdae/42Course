#ifndef __ICOMMAND_HPP__
#define __ICOMMAND_HPP__

#include "../defines.hpp"
#include "../User/UserManager.hpp"
#include "../Channel/ChannelManager.hpp"
#include "../Network/Network.hpp"

class ICommand
{
public:
	virtual void execute(ChannelManager &channelManager, UserManager &userManager, Network &network, struct CommandChunk commandChunk) = 0;
	
	virtual ~ICommand() {}
};

#endif