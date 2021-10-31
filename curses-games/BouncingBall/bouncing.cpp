// bouncing-oop.cpp
// Bouncing ball with ncurses
//
// needs libncurses-dev
// Compile: g++ bouncing-oop.cpp -o bouncing-oop -lncurses -Wall
//
// nr@bulme.at 2020
//

#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

typedef struct _coords {
    int x;
    int y; 
} coords;

class Window {
    public:
        Window();
        ~Window();
};

Window::Window()
{
    initscr();              // Start ncurses
    nodelay(stdscr, TRUE);  // Don't wait for \n for getch to parse input
    cbreak();               // Switch off input buffering
    curs_set(FALSE);        // Don't place a cursor on the screen
}

Window::~Window()
{
    nodelay(stdscr, FALSE);
    nocbreak();
    endwin();
    cout << "Bye" << endl;
}

class Ball {
    public:
        Ball();
        Ball(coords pos, coords speed, const string& shape = "*");
        void move();
        void setspeed(coords speed);
    private:
        string m_shape;
        coords m_pos;
        coords m_speed;
        coords m_window;
};

Ball::Ball()
{
    m_shape = "*";
    m_pos = {1, 1};
    m_speed = {1, 1};
    m_window = {0, 0};
    getmaxyx(stdscr, m_window.y, m_window.x);
}

Ball::Ball(coords pos, coords speed, const string& shape)
{
    m_shape = shape;
    m_pos = pos;
    m_speed = speed;
    m_window = {0, 0};
    getmaxyx(stdscr, m_window.y, m_window.x);
    
}

void Ball::move()
{
    mvprintw(m_pos.y, m_pos.x, m_shape.c_str());
    m_pos.x += m_speed.x;
    m_pos.y += m_speed.y;

     // Check for ball being outside of our window boundaries
    if (m_pos.x == m_window.x - 1 || m_pos.x == 0){
        // change direction
        m_speed.x *= -1;
        m_pos.x += m_speed.x;
    }
    if (m_pos.y ==  m_window.y - 1 || m_pos.y == 0){
       // change direction
        m_speed.y *= -1;
        m_pos.y += m_speed.y;
    } 

    refresh();
    clear();
}

void Ball::setspeed(coords speed)
{
    m_speed = speed;
}
int main()
{
    Window win;
    Ball ball;
    while (getch() == ERR) {      
        ball.move();
        usleep(50000);
    }
    return 0;
}
