#ifndef __CMODE_HPP__
#define __CMODE_HPP__

#include "./ICommand.hpp"

class Cmode: public ICommand
{
public:
	void execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk);
					
	bool checkUserValidNickname(const string nickName);
};

#endif