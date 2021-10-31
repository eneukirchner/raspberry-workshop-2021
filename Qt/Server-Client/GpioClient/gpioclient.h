// GpioClient/cpioclient.h

#ifndef GPIOCLIENT_H
#define GPIOCLIENT_H

#include "ui_gpioclient.h"
#include <QString>
#include <QTcpSocket>
#include <QMainWindow>
#include <QTimer>

const int PORT = 9999;
const QString HOSTNAME = "localhost";
const int REFRESH = 200;

class GpioClient : public QMainWindow, private Ui::GpioClient
{
    Q_OBJECT

public:
    explicit GpioClient(QWidget *parent = nullptr);

private slots:
    void showState();
    void requestData();

private:
    QTcpSocket* m_socket;
    QTimer* m_timer;
};

#endif // GPIOCLIENT_H
