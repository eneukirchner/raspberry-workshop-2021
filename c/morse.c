// morse 
// steuert GPIO LED0 via sysfs zum Senden von Morsezeichen
// Aufruf sudo ./morse

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define LED0_TRIGGER "/sys/class/leds/led0/trigger"
#define LED0_BRIGHTNESS "/sys/class/leds/led0/brightness"

#define TDOT 100000
#define BUFSIZE 1024

const char *code[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

int led0_init(void);
int send_morse(char *pmessage);
void getout(int sig);
void error(const char *msg);

int led0_init(void)
{
	FILE *fh;
	// Funktion der LED0 einstellen
	fh = fopen(LED0_TRIGGER, "w");
	if (NULL == fh)
        error("Fehler beim Oeffnen von Trigger");

	fprintf(fh, "none");
	fclose(fh);
    return EXIT_SUCCESS;
}

int send_morse(char* pmessage)
{
    FILE *fh;
    fh = fopen(LED0_BRIGHTNESS, "w");
    if (NULL == fh)
        error("Fehler beim Oeffnen von Brightness");

    int character;
    char symbol;

    while ((character = *pmessage++)) {
        if ((character < '0') || (character > '9'))
            break;
        int i = 0;
        while ((symbol = code[character - '0'][i++])) {
            int tdash =  (symbol == '.') ? 1 : 3;

            fprintf(fh, "1");
      		fflush(fh);
      		usleep(TDOT * tdash);

            fprintf(fh, "0");
      		fflush(fh);
      		usleep(TDOT);
        }
        usleep(TDOT * 3);
    }


    fclose(fh);
    return EXIT_SUCCESS;
}

// error - wrapper for perror
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(void)
{
    printf("Send morse code via LED0\n");
    if (led0_init() != EXIT_SUCCESS)
        error("Cannot init led0");

    char buf[BUFSIZE];

    while(1) {
        printf("Enter message...\n");
        fflush(stdout);
        scanf("%s", buf);
        send_morse(buf);
    }
}
