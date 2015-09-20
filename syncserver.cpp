#include "syncserver.h"

SyncServer::SyncServer(int port, QObject *parent) :
    QTcpServer(parent),
    threadPool(new QThreadPool(this)),
    port(port)
{
    start();
}

SyncServer::~SyncServer() {
    this->close();
}

bool SyncServer::start() {
    bool isListening = listen(QHostAddress::Any, port);

    if (!isListening) {
        qDebug() << "Error while starting:" << serverError();
        close();
        return false;
    }
    qDebug() << "Listening on" << port << "port...";

    return true;
}

void SyncServer::incomingConnection(qintptr handle) {
    SocketRunnable* runnable = new SocketRunnable(handle);
    threadPool->start(runnable);
}
