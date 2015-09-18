#ifndef SYNCSERVER_H
#define SYNCSERVER_H

#include <QTcpServer>
#include <QList>

class SyncServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SyncServer(int port, QObject *parent = 0);
    QList< QHostAddress > getIpAddresses() const;

signals:

public slots:
    void slotNewConnection();
};

#endif // SYNCSERVER_H
