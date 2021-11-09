# Program examples and utilities for Raspberry Pi 

## Programming (Directories c, Qt, Python)

For compiling / running the code examples, the following software packages are needed - most of them
are part of Raspberry Pi OS bullseye distribution and can be installed with ```sudo apt install <package name>```.

- Qt Widget 
```qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qtcreator```

- QML  
```sudo apt install qml-module-qtquick-controls2 qtquickcontrols2* qtdeclarative5-dev```

- PyQt
```python3-pyqt5*  pyqt5-dev-tools```

## BULME Hat hardware (Directory hardware)

![Board](board.jpg)

Board Dimensions: 65 x 56 mm

(TOP) *Name-Layer and Value Layer*  -> *Silkscreen*

*Important Notice:* Unless otherwise specified,  Eagle Files
use  layer 21 and 25 for silkscreen

## Shell scripts etc. for Raspberry Pi setup (Directory tools)

- find-raspi.php
Run this in a webserver to find ip address of Raspberry in subnet (if zeroconf is unavailable)

- klabu
Ping all hostnames.local from list in subnet



