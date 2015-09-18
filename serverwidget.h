#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include "syncserver.h"

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(int port, QWidget *parent = 0);
    ~ServerWidget();

private:
    Ui::ServerWidget *ui;
    SyncServer* server;
};

#endif // SERVERWIDGET_H
