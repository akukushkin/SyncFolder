#ifndef SYNCSERVER_H
#define SYNCSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>
#include "socketrunnable.h"

class SyncServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SyncServer(int port, QObject *parent = 0);
    ~SyncServer();

    bool start();
    void incomingConnection(qintptr handle);

signals:

public slots:

private:
    QThreadPool* threadPool;
    quint16 port;
};

#endif // SYNCSERVER_H
