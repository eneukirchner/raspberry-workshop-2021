#ifndef DEC2LED_H
#define DEC2LED_H

#include "ui_dec2led.h"

// GPIO Pins
const int LED1 = 18, LED2 = 23, LED3 = 24, LED4 = 25;
// QVector ... Container Class
const QVector<int> LEDS = {LED1, LED2, LED3, LED4};

class Dec2Led : public QWidget, private Ui::Dec2Led
{
    Q_OBJECT

public:
    explicit Dec2Led(QWidget *parent = nullptr);
    // Destruktor zum Abschalten der LEDs beim Schliessen des Fensters
    ~Dec2Led();
private slots:
    void on_decimalValue_valueChanged(int value);
};

#endif // DEC2LED_H
