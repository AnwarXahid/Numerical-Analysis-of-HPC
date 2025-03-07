CC = gcc
CFLAGS = -O3 -Wall
OBJS = main.o matrix_utils.o power_iteration.o inverse_iteration.o rayleigh_quotient.o

all: main.exe

main.exe: $(OBJS)
	$(CC) $(CFLAGS) -o main.exe $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main.exe

