// GpioClient/gpioclient.cpp

#include "gpioclient.h"
#include <QMessageBox>

GpioClient::GpioClient(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, &GpioClient::requestData);
    m_timer->start(REFRESH);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::readyRead, this, &GpioClient::showState);
}

void GpioClient::requestData()
{
    m_socket->connectToHost(HOSTNAME, PORT);
    if(!m_socket->waitForConnected(5000)) {
        QMessageBox::critical(nullptr, "Error", "Connect failed");
        exit(1);
    }
}

void GpioClient::showState()
{
    QByteArray data = m_socket->readAll();
    uint pin = data.simplified().toUInt();
    QString on_color = "background-color: rgb(255, 0, 0)";
    QString off_color = "background-color: rgb(131, 131, 131)";

    if (pin & 1)
        gpio22->setStyleSheet(on_color);
    else
        gpio22->setStyleSheet(off_color);

    if (pin & 1 << 1)
        gpio27->setStyleSheet(on_color);
    else
        gpio27->setStyleSheet(off_color);

    if (pin & 1 << 2)
        gpio17->setStyleSheet(on_color);
    else
        gpio17->setStyleSheet(off_color);

}
