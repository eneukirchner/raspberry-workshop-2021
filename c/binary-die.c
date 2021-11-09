/*  Pushing of a button makes LEDs display a
    random binary pattern 
    Edgar Neukirchner 2021
*/
   
// adjust this to match your hat
// Pin numbers refer to MakerPhat for Raspberry
const int BUTTONS[] = {21, 20}; // start, end buttons
const int LEDS[] = {17, 18, 27, 22, 25, 12, 13, 19};

#include <stdio.h>
#include <stdlib.h>
#include <lgpio.h>

#define BITCOUNT(x) (sizeof(x) / sizeof(x[0])) 
#define MASK(x) (unsigned int)((1 << BITCOUNT(x)) - 1)

#define TBOUNCE 200000 // us

void rollDice(int e, lgGpioAlert_p evt, void* data); 
void finish(int e, lgGpioAlert_p evt, void* data); 
int gpio_handle = 0;

void finish(int e, lgGpioAlert_p evt, void* data) 
{
    lgGroupWrite(gpio_handle, LEDS[0], 0x00, MASK(LEDS)); // all LEDs off
    lgGroupFree(gpio_handle, LEDS[0]);
    for (int n = 0; n < BITCOUNT(BUTTONS); n++)
        lgGpioFree(gpio_handle, BUTTONS[n]);
    printf("Bye\n");
    exit(0);
    
}
void rollDice(int e, lgGpioAlert_p evt, void* data) 
{
    int t = 200;
    while(t > 0) {
        // value 1...15 for 4 LEDs
        unsigned int value = 1 + rand() % ((1 << BITCOUNT(LEDS)) - 1);
        // group starts at 1st LED, values 0001...1111, mask 0x0f 
        lgGroupWrite(gpio_handle, LEDS[0], value, MASK(LEDS));
        lguSleep(t/1000.0);
        t -= 10;
    }
}

int main(void)
{
    srand(time(NULL));
    static int userdata = 0;
   
    // init GPIO
    gpio_handle = lgGpiochipOpen(0);
    if (gpio_handle < 0) {
        fprintf(stderr, "could not open GPIO chip\n");
        return 1;
    }

    // init LED outputs
    if(lgGroupClaimOutput(gpio_handle, 0, BITCOUNT(LEDS), LEDS, 0) != LG_OKAY) {
        fprintf(stderr, "could not claim GPIO outputs\n");
        return 1;
    }
    lgGroupWrite(gpio_handle, LEDS[0], 0x00, MASK(LEDS)); // all LEDs off

    // init BUTTON inputs
    // connect to interrupt service routine:start
    if(lgGpioSetAlertsFunc(gpio_handle, BUTTONS[0], rollDice, &userdata) != LG_OKAY) {
        fprintf(stderr, "could not connect to isr\n");
        return 1;
    }

    // finish
    if(lgGpioSetAlertsFunc(gpio_handle, BUTTONS[1], finish, &userdata) != LG_OKAY) {
        fprintf(stderr, "could not connect to isr\n");
        return 1;
    }

    for (int n = 0; n < BITCOUNT(BUTTONS); n++) {
        // debounce
        lgGpioSetDebounce(gpio_handle, BUTTONS[n], TBOUNCE);

        // prepare inputs for interrupt
        if(lgGpioClaimAlert(gpio_handle, 0, LG_FALLING_EDGE, BUTTONS[n], -1) != LG_OKAY) {
            fprintf(stderr, "could not claim GPIO input alert\n");
            return 1;
        }
    }

    for(;;)
	    lguSleep(0.1);
    return 0;
}



