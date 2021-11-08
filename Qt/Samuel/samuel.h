#ifndef SAMUEL_H
#define SAMUEL_H

#include <QMap>
#include <QString>
#include "ui_samuel.h"

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

const int TDOT = 100; // ms
const int LED = 26; // GPIO pin

class Samuel : public QMainWindow, private Ui::Samuel
{
    Q_OBJECT

public:
    explicit Samuel(QWidget *parent = nullptr);
private:       
    void morseBlink(const QString& message, int tdot);
    void mdelay(int millisecondsWait);

private slots:
    void on_sendButton_clicked();
    void on_actionAbout_triggered();
    void on_pushButton_clicked();
};

#endif // SAMUEL_H
