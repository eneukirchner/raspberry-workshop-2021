#include "car.h"
#include <curses.h>

Car::Car(coord winsize)
{
    // initial position in middle of terminal
    m_pos = coord(winsize.x / 2, winsize.y / 2);
}

void Car::move(coord delta)
{
/*    
    m_pos.x += delta.x;
    m_pos.y += delta.y;
*/
    m_pos += delta;
}

void Car::draw()
{
    mvaddch(m_pos.y, m_pos.x, 'X'); // write into curses buffer
}

coord Car::getpos()
{
    return(m_pos);
}