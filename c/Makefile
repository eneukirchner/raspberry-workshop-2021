all:	binary-die blink led0-blink-sysfs morse

binary-die:	binary-die.c
	gcc binary-die.c -o binary-die -lwiringPi -Wall

blink:	blink.c
	gcc blink.c -o blink -lwiringPi -Wall

led0-blink-sysfs: led0-blink-sysfs.c
	gcc led0-blink-sysfs.c -o led0-blink-sysfs -Wall

morse: morse.c
	gcc morse.c -o morse -Wall

clean:
	rm -f binary-die blink led0-blink-sysfs morse
