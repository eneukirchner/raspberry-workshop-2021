#include "window.h"
#include "car.h"
#include "track.h"
#include <curses.h>
#include <unistd.h>

const int TFRAME = 40000; // us
const int TWAIT = 2000000; // us


int main()
{
    Window gamewindow;
    Car car(gamewindow.getsize());
    Track track(gamewindow.getsize());
    int key;

    // game loop
    while((key = getch()) != 'q') {
        car.draw();
        track.move();
        track.draw();
        
        if (track.collision(car.getpos())) {
            clear();
            mvprintw(gamewindow.getsize().y/2, gamewindow.getsize().x/3,  "*********** BOOOOM! ***********");
            refresh();
            usleep(TWAIT);
            break;
            // game over!
        }

        refresh();
        usleep(TFRAME);
        clear();

        if (key == KEY_LEFT)
            car.move(coord(-1, 0));
        else if (key == KEY_RIGHT)
            car.move(coord(1, 0));
        else
            continue;
    }        
    return 0;
}
