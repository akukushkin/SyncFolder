#include "syncserver.h"

#include <QMessageBox>
#include <QHostInfo>

SyncServer::SyncServer(int port, QObject *parent) :
    QTcpServer(parent)
{
    bool isListening = this->listen(QHostAddress::Any, port);

    if (isListening) {
        QMessageBox::critical(0,
                              "Server error",
                              "Unable to start the server:"
                              + this->errorString()
                              );
        this->close();
        return;
    }

    connect(this, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection())
                       );
}

QList< QHostAddress > SyncServer::getIpAddresses() const {
    QList< QHostAddress > addresses;
    QString localhostName;

    localhostName = QHostInfo::localHostName();
    addresses = QHostInfo::fromName(localhostName).addresses();

    return addresses;
}

void SyncServer::slotNewConnection() {

}
