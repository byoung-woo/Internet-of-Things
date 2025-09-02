TARGET = main
OBJECTS = main.o photo.o
CC = gcc
LDFLAGS = -lwiringPi

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

clean:
    rm -f *.o
    rm -f $(TARGET)
