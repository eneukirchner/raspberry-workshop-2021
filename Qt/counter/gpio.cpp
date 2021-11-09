// Wrapper Class for lgpio library
#include "gpio.h"

#include <QDebug>
#include <QApplication>
#include <QTimer>

int Gpio::m_gpio_handle = 0;

Gpio::Gpio(int pin, int mode)
{
    m_pin = pin;
    if (mode == OUTPUT)
        lgGpioClaimOutput(m_gpio_handle, 0, m_pin, 0);
    else
        lgGpioClaimInput(m_gpio_handle, 0, m_pin);
}

Gpio::~Gpio()
{
    removeTrigger();
    lgGpioFree(m_gpio_handle, m_pin);

}

void Gpio::setup()  // to be called only once for all GPIOs, therefore static
{
    Gpio::m_gpio_handle = lgGpiochipOpen(0);
    if (Gpio::m_gpio_handle < 0) {
        qDebug() << "Could not open GPIO chip\n";
        QApplication::quit();
    }
}

void Gpio::write(int value)
{
    lgGpioWrite(m_gpio_handle, m_pin, value);
}

int Gpio::read()
{
    return lgGpioRead(m_gpio_handle, m_pin);
}

// watch GPIO state every TIMEOUT milliseconds. we use QTimer instead of lgGpioClaimAlert
void Gpio::setTrigger(int edge, int timeout, int initstate)
{
    if (m_timer == nullptr) {
        m_pinstate = initstate;
        m_edge = edge;
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &Gpio::checkPinState);
        m_timer->start(timeout);
    }
}

void Gpio::removeTrigger()
{
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
}

// we dont read gpio pin's state but the transitions
// initial state is hi when using pull-up R
void Gpio::checkPinState()
{
    int newstate = read();
    if ((m_edge == EDGE_FALLING) && (newstate < m_pinstate))
            emit stateChanged();
    else if ((m_edge == EDGE_RISING) && (newstate > m_pinstate))
            emit stateChanged();
    else if ((m_edge == EDGE_BOTH) && (newstate != m_pinstate))
            emit stateChanged();
    m_pinstate = newstate;
}
