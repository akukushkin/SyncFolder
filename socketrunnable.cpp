#include "socketrunnable.h"

SocketRunnable::SocketRunnable(quintptr handle) :
    descriptor(handle)
{
}

void SocketRunnable::run() {
    QTcpSocket* socket = new QTcpSocket();
    socket->setSocketDescriptor(descriptor);

    socket->waitForReadyRead();
    qDebug() << socket->readAll();

    // response
    socket->waitForBytesWritten();

    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}
