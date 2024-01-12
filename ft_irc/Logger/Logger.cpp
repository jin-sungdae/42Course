#include "./Logger.hpp"

Logger::Logger():serverDown(false) { ;}
Logger::~Logger() { ;}

void Logger::logging(const string& log)
{
    this->logQueue.push(log);
}

void Logger::errorLogging(const string& errorLog)
{
    this->errorLogQueue.push(errorLog);
}

bool Logger::shouldServerDown()
{
    return this->serverDown;
}

void Logger::setServerDown(bool shouldServerDown)
{
    this->serverDown = shouldServerDown;
}

bool Logger::isLogEmpty()
{
    return this->logQueue.empty();
}

bool Logger::isErrorLogEmpty()
{
    return this->errorLogQueue.empty();
}

string Logger::getLog()
{
    string tempLog = this->logQueue.front();

    this->logQueue.pop();
    return tempLog;
}

string Logger::getErrorLog()
{
    string tempLog = this->errorLogQueue.front();

    this->errorLogQueue.pop();
    return tempLog;
}
