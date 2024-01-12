#ifndef __CUSER_HPP__
#define __CUSER_HPP__

#include "../Network/Network.hpp"
#include "./ICommand.hpp"

class Cuser: public ICommand
{
public:
	void execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk);
};


#endif