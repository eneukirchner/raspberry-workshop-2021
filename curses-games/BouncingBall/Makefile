all: bouncing-oop bouncing

bouncing-oop: bouncing.cpp
	g++ bouncing.cpp -o bouncing-oop -lncurses -Wall

bouncing: bouncing.c
	gcc bouncing.c -o bouncing -lncurses -Wall

clean:
	rm -f bouncing bouncing-oop
