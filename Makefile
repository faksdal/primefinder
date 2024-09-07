#	Makefile to build raw from primefinder.cpp
TARGET=raw
CC=g++
CFLAGS=-I.

$(TARGET): primefinder.o	
	$(CC) $(CFLAGS) -o $(TARGET) primefinder.cpp

clean:
	rm *.o
	rm $(TARGET)

