#ifndef __CKICK_HPP__
#define __CKICK_HPP__


#include <string>
#include "./ICommand.hpp"

using namespace std;

class Ckick : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif