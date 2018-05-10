#include <QCoreApplication>
#include "teserver.hpp"
#include <sstream>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(argc < 2)
    {
        std::cout << "Please, specify the port number " <<
                     "as a second command line parameter" << std::endl;
    }
    else
    {
        std::stringstream ss;
        ss << argv[1];
        quint16 port;
        ss >> port;
        TeServer server;
        if(server.startServer(port))
        {
            std::cout << "Server started..." << std::endl;
        }
        else
        {
           std::cout << "Error: " << server.errorString().toStdString() << std::endl;
        }
    }
    return a.exec();
}
