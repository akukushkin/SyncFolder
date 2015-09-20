#ifndef SOCKETRUNNABLE_H
#define SOCKETRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

class SocketRunnable : public QRunnable
{
public:
    SocketRunnable(quintptr handle);

    void run();

private:
    qintptr descriptor;
};

#endif // SOCKETRUNNABLE_H
