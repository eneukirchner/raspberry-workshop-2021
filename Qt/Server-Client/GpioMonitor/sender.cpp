// GpioMonitor/sender.cpp

#include "sender.h"
#include <wiringPi.h>
#include <lgpio.h>
#include <QString>
#include <QDebug>
#include <QCoreApplication>

Sender::Sender(QObject *parent) : QObject(parent)
{
    m_gpio_handle = lgGpiochipOpen(0);
    if (m_gpio_handle < 0) {
        qDebug() << "could not open GPIO chip";
        QCoreApplication::quit();
    }

    for (auto pin : BUTTONS)
        lgGpioClaimInput(m_gpio_handle, 0, pin);

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
        value += (1 - lgGpioRead(m_gpio_handle, pin)) << n++;

    qDebug() << "connect from" << socket->peerAddress().toString() << socket->peerPort();;

    QByteArray buffer;
    socket->write(buffer.setNum(value));
    socket->disconnectFromHost();
}
