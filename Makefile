# Declare some variables to help construct our compile command
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref

main: main.o
	$(CC) -o main main.o volimage.o -std=c++11

main.o: main.cpp volimage.o
	$(CC) -c main.cpp volimage.h -std=c++11
	
volimage.o: volimage.cpp volimage.h
		$(CC) -c volimage.cpp -std=c++11


run: main
	./main


