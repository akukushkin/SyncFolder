#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(int port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    server = new SyncServer(port, this);
}

ServerWidget::~ServerWidget() {
    delete ui;
}
