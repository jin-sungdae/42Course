#include "UserManager.hpp"

UserManager::UserManager()
{}

UserManager::~UserManager()
{
	map<int, User *>::iterator iter = this->userListByFd.begin();
	map<int, User *>::iterator iterEnd = this->userListByFd.end();
	for (; iter != iterEnd; iter++)
	{
		int fd = iter->second->getFd();
		delete iter->second;
		close(fd);
	}
}

User* UserManager::getUserByNickname(const string nickname)
{
	const  string nick = nickname;
	int fd = this->userFdByName[nick];
	return this->getUserByFd(fd);
}

User* UserManager::getUserByFd(int fd)
{
	if (this->userListByFd.count(fd) == 0)
	{
		return NULL;
	}
	return this->userListByFd[fd];
}

map<int, User *> &UserManager::getUserListByFd()
{
	return this->userListByFd;
}

map<string, int> &UserManager::getUserFdByName()
{
	return this->userFdByName;
}

void UserManager::addUser(User *user)
{
	this->userListByFd[user->getFd()] = user;
}

void UserManager::addUserFdByName(User *user)
{
	this->userFdByName[user->getNickname()] = user->getFd();
}

void UserManager::makeUser(int fd)
{
	User *user = new User;
	user->setFd(fd);
	addUser(user);
}

void UserManager::deleteUser(int fd)
{
	User *user = this->getUserByFd(fd);
	if (user != NULL)
	{
		this->userFdByName.erase(user->getNickname());
		this->userListByFd.erase(fd);
		delete user;
		close(fd);
	}
}

string UserManager::makeMessage(User *user, string code, string target, string message)
{
	string prefix;
	string buffer;
	string colon = message.size() == 0 ? "" : " :";

	prefix = user == NULL ? string(":") + SERVERNAME + " " : ":" + user->getNickname() + "!" + user->getUserName() + "@" + SERVERNAME + " ";
	buffer =  prefix + code + (code.size() ? " " : "") + target + colon + message + "\r\n";
	return buffer;
}

bool UserManager::hasNickname(const string nickname)
{
	for(map<int, User *>::iterator iter = userListByFd.begin(); iter != userListByFd.end(); iter++)
	{
		if (iter->second->getNickname() == nickname)
		{
			return true;
		}
	}
	return false;
}