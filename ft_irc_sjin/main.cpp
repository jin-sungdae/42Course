#include "./defines.hpp"
#include "./Server/Server.hpp"
#include "./Logger/Logger.hpp"

Server* makeServer(int ac, char **av, Logger& logger)
{
    Server* server;

    if (ac != 3)
    {
        logger.errorLogging("YOU NEED 2 PARAMETERS");
        logger.setServerDown(true);
        server = new Server(logger);
    }
    else
    {
        
        if (string(av[1]).find_first_not_of("0123456789") != string::npos)
        {
            logger.errorLogging("PORT SHOULD BE NUMBER");
            logger.setServerDown(true);
            server = new Server(logger);
        }
        else
        {
            const int port = atoi(av[1]);
            if (port < 0 || port > 65535)
            {
                logger.errorLogging("PORT SHOULD BE 0 - 65535");
                logger.setServerDown(true);
                server = new Server(logger);
            }
            else
            {
                const char* password = av[2];
                server = new Server(port, password, logger);
            }    
        }
    }
    return server;
}

int main(int ac, char **av)
{
    int rtValue;
    Logger logger;
    Server* server = makeServer(ac, av, logger);

    server->init();
    rtValue = server->run();
    delete server;
    if (rtValue == FALSE)
    {
        return 1;
    }
    return 0;
}