#include "counter.h"
#include "gpio.h"

Counter::Counter(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_counter = 0;
    Gpio::setup(); // setup GPIO hardware
    m_up = new Gpio(BUTTON1, INPUT); // configure pins
    m_reset = new Gpio(BUTTON2, INPUT);
    m_down = new Gpio(BUTTON3, INPUT);

    m_up->setTrigger(EDGE_FALLING); // arm trigger for GPIO state
    m_reset->setTrigger(EDGE_FALLING);
    m_down->setTrigger(EDGE_FALLING);

    connect(m_up, &Gpio::stateChanged, this, &Counter::on_pushButtonDown_clicked); // connect hardware buttons to GUI
    connect(m_reset, &Gpio::stateChanged, this, &Counter::on_pushButtonReset_clicked);
    connect(m_down, &Gpio::stateChanged, this, &Counter::on_pushButtonUp_clicked);
}

Counter::~Counter()
{
    delete m_up;
    delete m_reset;
    delete m_down;
}

// Connect GUI pushbuttons to GUI display
void Counter::on_pushButtonDown_clicked()
{
    m_counter--;
    lcdNumber->display(m_counter);
}

void Counter::on_pushButtonReset_clicked()
{
    m_counter = 0;
    lcdNumber->display(m_counter);
}

void Counter::on_pushButtonUp_clicked()
{
    m_counter++;
    lcdNumber->display(m_counter);
}



