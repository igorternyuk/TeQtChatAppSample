#pragma once

#include <QTcpSocket>

class TeSocket: public QTcpSocket
{
    Q_OBJECT
public:
    explicit TeSocket(qintptr handle, QObject *parent = nullptr);
signals:
    void TeReadyRead(TeSocket*);
    void TeStateChanged(TeSocket*, int);
};
