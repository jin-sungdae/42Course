#ifndef __CNICK_HPP__
#define __CNICK_HPP__

#include "./ICommand.hpp"

class Cnick: public ICommand
{
public:
	bool checkValidNickname(const string nickName);
	void execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk);
					
};

#endif