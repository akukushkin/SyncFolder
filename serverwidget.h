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

private:
    void fillWidget() const;

public:
    explicit ServerWidget(int port, QWidget *parent = 0);
    ~ServerWidget();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::ServerWidget *ui;
    SyncServer* server;
};

#endif // SERVERWIDGET_H
