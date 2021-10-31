#ifndef GPIO_H
#define GPIO_H
#include <wiringPi.h>
#include <QObject>
#include <QTimer>

class Gpio : public QObject
{
    Q_OBJECT
public:
    Gpio(int pin, int mode);
    ~Gpio();
    void write(int value);
    int read();
    void setTrigger(int edge, int timeout = 100, int initstate = 1);
    void removeTrigger();
    static void setup();

private:
    int m_pin;
    int m_pinstate;
    int m_edge;
    QTimer *m_timer = nullptr;

private slots:
    void checkPinState();

signals:
    void stateChanged();

};

#endif // GPIO_H
