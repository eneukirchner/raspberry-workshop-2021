#!/usr/bin/env python3
# 2021 nr@bulme.at

from PyQt5.QtCore import Qt, QObject, QTimer, QTime
from PyQt5.QtWidgets import (QWidget, QLabel,
    QVBoxLayout, QHBoxLayout, QApplication)

red_color = 'background-color: rgb(255, 0, 0)'
green_color = 'background-color: rgb(0, 255, 0)'
blue_color = 'background-color: rgb(0, 180, 255)'
gray_color = 'background-color: rgb(140, 140, 140)'

class BinClock(QWidget):
    """Binary Clock"""
    def __init__(self):
        super().__init__()
        self.initUi()

    def initUi(self):
        """Setup GUI"""
        self.setStyleSheet("background-color: black")
        self.hbox = QHBoxLayout()
        self.hours = self.binaryDisplay(5)
        self.minutes = self.binaryDisplay(6)
        self.seconds = self.binaryDisplay(6)

        self.setLayout(self.hbox)
        self.setMinimumSize(400, 200)
        self.setWindowTitle('Binary Clock')
        self.show()

        self.timer = QTimer()
        self.timer.timeout.connect(self.updateTime)
        self.timer.start(1000)

    def binaryDisplay(self, nbits):
        """Draw column of nbits labels and return list"""
        bits = []
        for b in range(nbits-1, -1, -1):
            bits.append(QLabel(" %2d " % 2**b))
        vbox = QVBoxLayout()
        vbox.setAlignment(Qt.AlignCenter)
        for label in bits:
            vbox.addWidget(label)
            label.setStyleSheet(gray_color)
        self.hbox.addLayout(vbox)
        return bits


    def setBits(self, value, labels, color):
        """Show binary representation on GUI Bits"""
        for n, bitlabel in enumerate(reversed(labels)):
            if (value >> n & 1):
                bitlabel.setStyleSheet(color)
            else:
                bitlabel.setStyleSheet(gray_color)

    def updateTime(self):
        """Get hours / minutes / seconds from actual time"""
        t = QTime.currentTime()
        self.setBits(t.hour(), self.hours, red_color)
        self.setBits(t.minute(), self.minutes, green_color)
        self.setBits(t.second(), self.seconds, blue_color)

if __name__ ==  '__main__':
    app = QApplication([])
    win = BinClock()
    app.exec_()
