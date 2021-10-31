#!/usr/bin/env python3

import warnings
warnings.filterwarnings('ignore')

from gpiozero import LED
from signal import pause
from time import sleep
import sys

CODE = {"0" : "-----", 
        "1" : ".----",
        "2" : "..---",
        "3" : "...--",
        "4" : "....-",
        "5" : ".....",
        "6" : "-....",
        "7" : "--...",
        "8" : "---..",
        "9" : "----."}

class MorseLED(LED):
    def __init__(self, ledpin, tdot = 0.1):
        super().__init__(ledpin)
        self.tdot = tdot

    def send_char(self, character):
        for n in CODE[character]:
            if n == ".":
                self.blink(self.tdot, self.tdot, 1, False)
            else:
                self.blink(3 * self.tdot, self.tdot, 1, False)
        sleep(2 * self.tdot) 

    def send_string(self, string):
        for c in string:
            self.send_char(c)


if __name__ == "__main__":
    STATUS_LED = 42
    TDOT = 0.2 # in Sekunden

    led = MorseLED(STATUS_LED, TDOT) # constructor

    print("Enter numbers 0...9 or CTRL-C to end!")
    while True:
        try:
            inp = input("> ")
            led.send_string(inp) 
        except KeyError as err:
            print("Not in code table:", err.args[0])
        except KeyboardInterrupt:
            print("\nBye!")
            sys.exit()
        
            
