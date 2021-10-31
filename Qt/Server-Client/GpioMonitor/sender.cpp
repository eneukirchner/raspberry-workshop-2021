// GpioMonitor/sender.cpp

#include "sender.h"
#include <wiringPi.h>
#include <QString>
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{
    wiringPiSetupGpio();
    for (auto pin : BUTTONS)
        pinMode(pin, INPUT);

    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &Sender::sendStatus);
    if (!m_server->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Server could not start";
        return;
    }
}

void Sender::sendStatus()
{
    QTcpSocket* socket = m_server->nextPendingConnection();
    connect(socket, &QTcpSocket::disconnected, socket, &QObject::deleteLater);

    uint n = 0;
    int value = 0;
    for (auto pin : BUTTONS)
        value += (1 - digitalRead(pin)) << n++;

    qDebug() << "connect from" << socket->peerAddress().toString() << socket->peerPort();;

    QByteArray buffer;
    socket->write(buffer.setNum(value));
    socket->disconnectFromHost();
}
