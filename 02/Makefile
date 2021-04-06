CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra

all: main.o parser.o
	$(CC) $(FLAGS) main.o parser.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

parser.o: parser.h parser.cpp
	$(CC) $(FLAGS) parser.cpp -c


clean:
	rm -f *.o main
