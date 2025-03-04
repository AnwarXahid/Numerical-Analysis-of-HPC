CC = gcc
CFLAGS = -O3 -Wall -std=c99
OBJS = main.o interpolation.o least_squares.o utils.o

all: main.exe

main.exe: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main.exe -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main.exe data.txt interpolation_plot.png

