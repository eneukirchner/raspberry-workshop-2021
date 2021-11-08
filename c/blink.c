// Blink with lgpio
// build: gcc blink.c -o blink -Wall -llgpio
#include <stdio.h>
#include <lgpio.h>
#define OUT 18

int main(int argc, char *argv[])
{
    int h;
    int lFlags = 0; /* default line flags */

    /* get a handle to the GPIO */
    h = lgGpiochipOpen(0);
    lgGpioClaimOutput(h, lFlags, OUT, 0); /* initial level 0 */

    while (1)
    {
        lgGpioWrite(h, OUT, 1);
        lguSleep(0.5); /* sleep for 0.1 seconds */
        lgGpioWrite(h, OUT, 0);
        lguSleep(0.5); /* sleep for 0.1 seconds */
    }
}
