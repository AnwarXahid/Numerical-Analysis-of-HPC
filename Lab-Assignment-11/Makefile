# Makefile for Linked List Assignment
# Written by Anwar Hossain Zahid
# Department of Computer Science, Iowa State University

CC = gcc
CFLAGS = -O3 -Wall
OBJECTS = main.o GenerateList.o Print.o GetKey.o SearchList.o DeleteList.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe

help:
	@echo "Valid targets:"
	@echo " main.exe  -> Build the program"
	@echo " clean     -> Remove .o and .exe files"

