#include "tesocket.hpp"

TeSocket::TeSocket(qintptr handle, QObject *parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &TeSocket::readyRead, [&](){
        emit TeReadyRead(this);
    });

    connect(this, &TeSocket::stateChanged, [&](int state){
        emit TeStateChanged(this, state);
    });
}
