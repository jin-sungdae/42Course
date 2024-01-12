#include "Cping.hpp"

void Cping::execute(ChannelManager &channelManager,
					UserManager &userManager,
					Network &network,
					struct CommandChunk commandChunk)
{
	User *user = userManager.getUserByFd(commandChunk.fd);
	string message = commandChunk.parameterLast;
	(void)channelManager;

	string msg = "PONG" + string(message.size() == 0 ? "" : " ") + message  + "\r\n";
	network.sendToUser(user->getFd(), msg);
}