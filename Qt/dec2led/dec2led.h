#ifndef DEC2LED_H
#define DEC2LED_H

#include "ui_dec2led.h"

// GPIO Pins BULME Hat
const QVector<int> LEDS = {18, 23, 24, 25};

// GPIO Pins MakerPhat
// const QVector<int> LEDS = {17, 18, 27, 22};

class Dec2Led : public QWidget, private Ui::Dec2Led
{
    Q_OBJECT

public:
    explicit Dec2Led(QWidget *parent = nullptr);
    // Destruktor zum Abschalten der LEDs beim Schliessen des Fensters
    ~Dec2Led();
private:
    int m_gpio_handle;

private slots:
    void on_decimalValue_valueChanged(int value);
};

#endif // DEC2LED_H
