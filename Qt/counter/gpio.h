#ifndef GPIO_H
#define GPIO_H
#include <lgpio.h>
#include <QObject>
#include <QTimer>

enum {INPUT, OUTPUT};
enum {EDGE_FALLING, EDGE_RISING, EDGE_BOTH};

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
    static int m_gpio_handle;
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
