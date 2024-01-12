#ifndef __CQUIT_HPP__
#define __CQUIT_HPP__

#include <string>
#include "./ICommand.hpp"

using namespace std;

class Cquit : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif