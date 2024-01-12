#ifndef __CPING_HPP__
#define __CPING_HPP__

#include <string>

#include "ICommand.hpp"

class Cping : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif