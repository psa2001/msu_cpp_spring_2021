CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra

all: main.o allocator.o
	$(CC) $(FLAGS) main.o allocator.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

allocator.o: allocator.hpp allocator.cpp
	$(CC) $(FLAGS) allocator.cpp -c

test: test.o allocator.o
	$(CC) $(FLAGS) test.o allocator.o -o test
	./test

test.o: test.cpp 
	$(CC) $(FLAGS) test.cpp -c

clean:
	rm -f *.o main test