#ifndef SAMUEL_H
#define SAMUEL_H

const int TDOT = 200; // ms
const int LED = 18; // GPIO LED pin for your board

#include <QMap>
#include <QString>
#include "ui_samuel.h"

// might be expanded to alphabet a...z
const QMap<QChar, QString> MORSECODE = {
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."}
};


class Samuel : public QMainWindow, private Ui::Samuel
{
    Q_OBJECT

public:
    explicit Samuel(QWidget *parent = nullptr);
private:       
    void morseBlink(const QString& message, int tdot);
    void mdelay(int millisecondsWait);
    int m_gpio_handle;

private slots:
    void on_sendButton_clicked();
    void on_actionAbout_triggered();
};

#endif // SAMUEL_H
