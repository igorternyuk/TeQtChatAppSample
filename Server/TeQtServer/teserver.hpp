#pragma once

#include <QTcpServer>

class TeSocket;

class TeServer: public QTcpServer
{
    Q_OBJECT
public:
    explicit TeServer(QObject* parent = nullptr);
    bool startServer(quint16 port);

protected:
    void incomingConnection(qintptr handle);

private:
    QList<TeSocket*> mSockets;
};
