# Makefile
# Written by Anwar Hossain Zahid
# Department of Computer Science, Iowa State University

CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
TARGET = quadrilateral

all: $(TARGET)

$(TARGET): main.o quadrilateral.o
	$(CC) $(CFLAGS) main.o quadrilateral.o -o $(TARGET) $(LDFLAGS)

main.o: main.c quadrilateral.h
	$(CC) $(CFLAGS) -c main.c

quadrilateral.o: quadrilateral.c quadrilateral.h
	$(CC) $(CFLAGS) -c quadrilateral.c

clean:
	rm -f *.o $(TARGET)
