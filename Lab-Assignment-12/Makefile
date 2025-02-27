# Makefile for Stack Assignment 12
# Written by Anwar Hossain Zahid
# Department of Computer Science, Iowa State University

CC = gcc
CFLAGS = -O3 -Wall
OBJS = main.o DisplayOptions.o ExecuteOption.o Push.o Pop.o Peek.o DisplayStack.o GetStackSize.o DeleteStack.o

main.exe: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main.exe

