#include "dec2led.h"
#include <QVector>
#include <lgpio.h>
#include <QDebug>

Dec2Led::Dec2Led(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this); // Setup graph. Oberflaeche
    m_gpio_handle = lgGpiochipOpen(0);
    if (m_gpio_handle < 0) {
        qDebug() << "could not open GPIO chip";
        QApplication::quit();
    }

    // jedes Element des Vektors LEDS -> led
    for (auto &led : LEDS)
        lgGpioClaimOutput(m_gpio_handle, 0, led, 0);

}

Dec2Led::~Dec2Led()
{
    // LEDS der Reihe nach ausschalten
    for (auto &led : LEDS)
        lgGpioWrite(m_gpio_handle, led, 0);
}

void Dec2Led::on_decimalValue_valueChanged(int value)
{
    // Dezimalwert im Label anzeigen
    // number: Umwandlung int value nach QString
    showdec->setText(QString::number(value));

    // Dualwert
    // QVector: Containerklasse (mit bits aus dem Formular)
    QVector<QLabel *> bits = {bit0, bit1, bit2, bit3};
    int level; // ein/aus
    int n = 0;

    for (auto &bit : bits) { // auto erkennt Datentyp von bits automatisch
        level = value % 2; // Umrechnung Dezimal -> Dual
        value /= 2;

        if (level == 1)
            bit->setStyleSheet("background-color: red");
        else
            bit->setStyleSheet("background-color: black");

        // Wert auf den LEDs ausgeben
        // andere Moeglichkeit: lgGroupWrite
        lgGpioWrite(m_gpio_handle, LEDS[n++], level);
    }
}
