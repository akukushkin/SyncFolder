#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QList>
#include <QHostInfo>
#include <QNetworkInterface>

void ServerWidget::fillWidget() const {
    QList< QHostAddress > addresses;
    quint16 port;
    QString strPort;

    addresses = QNetworkInterface::allAddresses();
    foreach (const QHostAddress& addr, addresses) {
        ui->addrTextBrowser->append(addr.toString());
    }
    port = server->serverPort();
    strPort = QString::number(port);
    ui->portLabel->setText(strPort);
    ui->startButton->setDisabled(true);
}

ServerWidget::ServerWidget(int port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    server = new SyncServer(port, this);
    fillWidget();
}

ServerWidget::~ServerWidget() {
    delete ui;
    delete server;
}

void ServerWidget::on_startButton_clicked() {
    bool isOpenning = server->start();
    if (isOpenning) {
        ui->startButton->setDisabled(true);
        ui->stopButton->setDisabled(false);
    }
}

void ServerWidget::on_stopButton_clicked() {
    ui->stopButton->setDisabled(true);
    server->close();
    ui->startButton->setDisabled(false);
}
