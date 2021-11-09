#include "samuel.h"
#include <lgpio.h>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QMessageBox>

Samuel::Samuel(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    m_gpio_handle = lgGpiochipOpen(0);
    if (m_gpio_handle < 0) {
        qDebug() << "Cannot open GPIO chip";
        QApplication::quit();
    }
    lgGpioWrite(m_gpio_handle, LED, 0);
}

void Samuel::on_sendButton_clicked()
{
    QString message = textInput->text();
    for (auto character : message) {
        QString morse = MORSECODE.value(character);
        morseBlink(morse, TDOT);
    }
}

void Samuel::morseBlink(const QString& message, int tdot)
{
    for (auto symbol : message) {
        lgGpioWrite(m_gpio_handle, LED, 1);
        if (symbol == "-") {
            mdelay(tdot * 3);
        }
        else {
            mdelay(tdot);
        }

        lgGpioWrite(m_gpio_handle, LED, 0);
        mdelay(tdot);
    }
    mdelay(tdot * 2);
}

void Samuel::on_actionAbout_triggered()
{
    QMessageBox mbox;
    mbox.setText("BULME Morse Encoder nr@bulme.at 2021");
    mbox.exec();
}

void Samuel::mdelay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}


