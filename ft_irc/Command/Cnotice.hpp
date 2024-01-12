#ifndef __CNOTICE_HPP__
#define __CNOTICE_HPP__

#include <string>

#include "ICommand.hpp"

class Cnotice : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif