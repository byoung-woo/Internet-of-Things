.SUFFIXES = .c .o
TARGET = main
OBJECTS = main.o led.o
CC = gcc
LDFLAGS = -lwiringPi -lpthread -lm
CFLAGS = -Wall -O2

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS) $(LDFLAGS)

clean :
	$(RM) *.o $(TARGET)
