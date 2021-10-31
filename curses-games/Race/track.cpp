#include "track.h"
#include <curses.h>
#include <cmath>

// constructor
Track::Track(coord winsize) : m_winsize(winsize)
{
    // init vector of size window height with 0
    // e.g. 40 lines -> vector size = 40
    m_border.assign(m_winsize.y, 0);
    m_step = 0;
}

//  generate moving sine wave for track border
void Track::move()
{
    // (1) generate sine wave:
    //  A*sin(pi/180*n) 
    // with n in °

    // adapt ampitude to terminal width
    float amplitude = m_winsize.x * 0.25;
    int speed = 2; // frequency
    // e.g. m_winsize.x = 100 -> curve = -25 .... +25 (character positions)
    int curve = std::round(amplitude * std::sin(3.14/180.0 * m_step * speed));
    if (++m_step >= 360) // period of sine wave in °
        m_step = 0;

    // (2) // add new track element at begin of vector
    m_border.insert(m_border.begin(),curve);
    m_border.pop_back(); // remove last element of vector -> vector size stays constant
}

void Track::draw()
{
    int y = 0; // lines in terminal
    // read x values from vector m_border
    for (int x: m_border) {
        // left and right border in parallel
        int leftx = x + std::round(m_winsize.x * 0.3); // zero line at 30% terminal width
        int rightx = x + std::round(m_winsize.x * 0.7); // zero line at 70% terminal width

        // write values in ncurses buffer
        mvaddch(y, leftx, '|');
        mvaddch(y, rightx, '|');

        // next line (repeat m_border.size() times)
        y++;
    }
}

bool Track::collision(coord pos)
{
    int x = m_border.at(m_border.size()/2); // middle of border vector
    // borders x at middle
    int leftx = x + std::round(m_winsize.x * 0.3); // zero line at 30% terminal width
    int rightx = x + std::round(m_winsize.x * 0.7); // zero line at 70% terminal width

    return ((pos.x <= leftx) || (pos.x >= rightx)); // car at pos touches left or right border

}