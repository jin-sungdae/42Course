#ifndef __CPONG_HPP__
#define __CPONG_HPP__

#include <string>

#include "ICommand.hpp"

class Cpong : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif