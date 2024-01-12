#ifndef __CPASS_HPP__
#define __CPASS_HPP__

#include "./ICommand.hpp"

class Cpass: public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif