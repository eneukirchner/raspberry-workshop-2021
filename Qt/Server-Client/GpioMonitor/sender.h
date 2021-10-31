// GpioMonitor/sender.h

#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

const QVector<int> BUTTONS = {22, 27, 17};
const int PORT = 9999;
const int TIMEOUT = 1000;

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);

public slots:
    void sendStatus();

private:
    QTcpServer* m_server;
};

#endif // SENDER_H
