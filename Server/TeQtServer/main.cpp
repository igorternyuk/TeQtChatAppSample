#include <QCoreApplication>
#include "teserver.hpp"
#include <sstream>
#include <iostream>
#include <functional>
#include <signal.h>

#define DEFAULT_PORT 33333

static void cleanup(int sig)
{
    std::cout << "Server is shutting down..." << std::endl;
    if (sig == SIGINT)
    {
        qApp->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    

    quint16 port = DEFAULT_PORT;

    if(argc > 1)
    {
        std::stringstream ss;
        ss << argv[1];
        quint16 port;
        ss >> port;
    }

    TeServer server;

    if(server.startServer(port))
    {
        std::cout << "Server started..." << std::endl;
    }
    else
    {
       std::cout << "Error: " << server.errorString().toStdString() << std::endl;
    }

    signal(SIGINT, cleanup);
    return a.exec();
}
