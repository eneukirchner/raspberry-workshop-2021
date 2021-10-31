#ifndef CAR_H
#define CAR_H
#include "window.h"

class Car {
    public:
        Car(coord winsize);
        void move(coord delta); // change member vars
        void draw(); // call mvaddch (curses)
        coord getpos(); // for collision detect
    private:
        coord m_pos;
};

#endif