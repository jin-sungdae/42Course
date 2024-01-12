#ifndef __CPART_HPP__
#define __CPART_HPP__


#include <string>
#include "./ICommand.hpp"

using namespace std;

class Cpart : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
				UserManager &userManager,
				Network &network,
				struct CommandChunk commandChunk);
};

#endif