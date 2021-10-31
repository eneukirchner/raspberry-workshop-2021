#ifndef WINDOW_H
#define WINDOW_H

struct coord {
    coord() {};
    // constructor initializes members x, y
    coord(int _x, int _y) : x(_x), y(_y) {}  
    // operator overloading
    coord& operator+=(const coord& c)
    {
        x += c.x;
        y += c.y;
        return *this;
    }
    int x;
    int y;
};

class Window {
    public:
        Window();
        ~Window();
        coord getsize();
};


#endif