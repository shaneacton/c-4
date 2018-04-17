# Declare some variables to help construct our compile command
CC=g++         # the compiler

imageops: imageops.o
	$(CC) -o imageops imageops.o Image.o -std=c++11

imageops.o: imageops.cpp Image.o
	$(CC) -c imageops.cpp Image.h -std=c++11
	
Image.o: Image.cpp Image.h
		$(CC) -c Image.cpp -std=c++11


