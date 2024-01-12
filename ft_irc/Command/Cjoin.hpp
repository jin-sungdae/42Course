#ifndef __CJOIN_HPP__
#define __CJOIN_HPP__


#include <string>
#include "./ICommand.hpp"

using namespace std;

class Cjoin : public ICommand
{
public:
	void execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk);
};

#endif