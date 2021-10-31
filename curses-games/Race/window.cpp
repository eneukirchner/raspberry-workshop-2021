// Curses Window
#include "window.h"
#include "curses.h"

// curses window setup
Window::Window()
{
    initscr();
    nodelay(stdscr, TRUE);
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE); // control with <- -> keys
}

// cleanup terminal at end
Window::~Window()
{
    nodelay(stdscr, FALSE);
    nocbreak();
    endwin();
}

coord Window::getsize()
{
    int height, width;
    getmaxyx(stdscr, height, width); // order: y, x !
    /*
    coord temp = {width, height};
    return(temp); // x, y
    */
    return(coord(width, height)); // x, y
}