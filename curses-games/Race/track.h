#ifndef TRACK_H
#define TRACK_H
#include <vector>
#include "window.h"

class Track {
    public:
        Track(coord winsize); // constructor
        void move(); // change coordinate values
        void draw(); // write coordinates into ncurses buffer
        bool collision(coord pos);
    private:
        coord m_winsize;
        std::vector<int> m_border; // only one for left and right border
        int m_step;
};

#endif