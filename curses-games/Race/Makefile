race: car.o window.o track.o main.o
	g++ car.o window.o track.o main.o -lncurses -o race

car.o: car.cpp car.h
	g++ -c car.cpp -Wall

window.o: window.cpp window.h
	g++ -c window.cpp -Wall

track.o: track.cpp track.h
	g++ -c track.cpp -Wall

main.o: main.cpp
	g++ -c main.cpp -Wall

clean:
	rm -f *.o race