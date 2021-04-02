CC=g++
CFLAGS=-std=c++14 -c -O3
OUTPUT = snake

all: snake

snake: main.o func.o snake.o fruit.o
	$(CC) main.o func.o snake.o fruit.o -o $(OUTPUT)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp

snake.o: snake.cpp
	$(CC) $(CFLAGS) snake.cpp
	
fruit.o: fruit.cpp
	$(CC) $(CFLAGS) fruit.cpp

clean:
	rm -rf *.o $(OUTPUT)
