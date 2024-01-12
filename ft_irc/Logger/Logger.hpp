#ifndef __LOGGER_HPP_
#define __LOGGER_HPP_

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include "../defines.hpp"
class Logger
{
public:
    Logger();
    ~Logger();
    void logging(const string& log);
	void errorLogging(const string& errorLog);
    bool shouldServerDown();
    void setServerDown(bool serverDown);
    bool isLogEmpty();
    bool isErrorLogEmpty();
    string getLog();
    string getErrorLog();
private:
    queue<string> errorLogQueue;
	queue<string> logQueue;
    bool serverDown;
};

#endif