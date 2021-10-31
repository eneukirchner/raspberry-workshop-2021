#!/usr/bin/env python3
# 2021 nr@bulme.at

from gpiozero import LEDBoard
from PyQt5.QtCore import Qt, QObject
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QCheckBox,
    QVBoxLayout, QHBoxLayout, QApplication)

class Bin2Dec(QWidget):
    """Show binary values on LCD / LEDs"""
    def __init__(self):
        super().__init__()
        self.initUi()
        self.initGPIO()

    def initUi(self):
        """Setup GUI"""
        self.lcd = QLCDNumber()
        self.lcd.display(0)

        self.bits = []
        for b in range(3, -1, -1):
            self.bits.append(QCheckBox("Bit %d" % b))

        hbox = QHBoxLayout()
        hbox.setAlignment(Qt.AlignCenter)
        for bit in self.bits:
            hbox.addWidget(bit)
            bit.clicked.connect(self.display)

        vbox = QVBoxLayout()
        vbox.addWidget(self.lcd)
        vbox.addLayout(hbox)

        self.setLayout(vbox)
        self.setMinimumSize(400, 200)
        self.setWindowTitle('Binär-Dezimal-Rechner')
        self.show()


    def initGPIO(self):
        """Init gpiozero outputs"""
        self.leds = LEDBoard(18, 23, 24, 25)

    def display(self):
        self.showDec()
        self.showLeds()

    def showDec(self):
        """Show decimal representation on GUI LCD"""
        decimal = 0
        for bit in self.bits:
            decimal = 2*decimal + bit.isChecked()

        self.lcd.display(decimal)

    def showLeds(self):
        """Switch LEDs according to checkbox values"""
        for led, bit in zip(self.leds, self.bits):
            led.value =  bit.isChecked()


if __name__ ==  '__main__':
    app = QApplication([])
    win = Bin2Dec()
    app.exec_()
