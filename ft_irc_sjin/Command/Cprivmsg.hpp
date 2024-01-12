#ifndef __CPRIVMSG_HPP__
#define __CPRIVMSG_HPP__

#include <string>

#include "ICommand.hpp"

class Cprivmsg : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif