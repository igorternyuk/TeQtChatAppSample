#include "teserver.hpp"
#include "tesocket.hpp"
#include <QTextStream>
#include <QDebug>

TeServer::TeServer(QObject *parent):
    QTcpServer(parent)
{

}

bool TeServer::startServer(quint16 port)
{
    return this->listen(QHostAddress::Any, port);
}

void TeServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle " << handle;
    auto socket = new TeSocket(handle, this);
    mSockets << socket;

    connect(socket, &TeSocket::TeReadyRead, [&](TeSocket *socket){
        qDebug() << "TeReadyRead";
        QTextStream stream(socket);
        auto msg = stream.readAll();
        for(auto &socket: mSockets)
        {
            QTextStream currStream(socket);
            currStream << msg;
        }
    });

    connect(socket, &TeSocket::TeStateChanged, [&](TeSocket *socket, int state){
        qDebug() << "TeStateChanged";
        if(state == QTcpSocket::UnconnectedState)
        {
            qDebug() << "Unconnected state";
            mSockets.removeOne(socket);
            for(auto &socket: mSockets)
            {
                QTextStream stream(socket);
                stream << "Server: Client " << socket->socketDescriptor() << " disconnected...";
                socket->flush();
            }
        }
        else if(state == QTcpSocket::ConnectedState)
        {
            qDebug() << "Connected state";
            for(auto &socket: mSockets)
            {
                QTextStream stream(socket);
                stream << "Server: Client " << socket->socketDescriptor() << " connected...";
                socket->flush();
            }
        }
    });
}
