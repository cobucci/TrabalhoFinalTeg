all : ex1

ex1: main.o cartesiano.o
	g++ main.o cartesiano.o -o ex1

main.o: main.cpp
	g++ -c main.cpp

cartesiano.o: cartesiano.cpp cartesiano.h
	g++ -c cartesiano.cpp

clean:
	rm -rf *.o ex1
