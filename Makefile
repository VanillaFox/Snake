CC=g++

CFLAGS=--std=c++14 -c -O3

all: snake

snake: main.o func.o
	$(CC) main.o func.o -o snake

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp
	
clean:
	rm -rf *.o solution
