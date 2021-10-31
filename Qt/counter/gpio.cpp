// Wrapper Class for wiringPi library
#include "gpio.h"
#include <QDebug>
#include <QTimer>

Gpio::Gpio(int pin, int mode)
{
    m_pin = pin;
    pinMode(m_pin, mode);
}

Gpio::~Gpio()
{
    removeTrigger();
}

void Gpio::setup()  // to be called only once for all GPIOs, therefore static
{
    wiringPiSetupGpio(); // BCM numbering
}

void Gpio::write(int value)
{
    digitalWrite(m_pin, value);
}

int Gpio::read()
{
    return digitalRead(m_pin);
}

// watch GPIO state every TIMEOUT milliseconds
void Gpio::setTrigger(int edge, int timeout, int initstate)
{
    if (m_timer == nullptr) {
        m_pinstate = initstate;
        m_edge = edge;
        m_timer = new QTimer(this);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(checkPinState()));
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
    if ((m_edge == INT_EDGE_FALLING) && (newstate < m_pinstate))
            emit stateChanged();
    else if ((m_edge == INT_EDGE_RISING) && (newstate > m_pinstate))
            emit stateChanged();
    else if ((m_edge == INT_EDGE_BOTH) && (newstate != m_pinstate))
            emit stateChanged();
    m_pinstate = newstate;
}
