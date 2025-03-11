CC = gcc
CFLAGS = -O3 -Wall
OBJS = main.o matrix.o trimatrix.o QRdecomp.o QRA.o Hessenberg.o GetShift.o FindZero.o

all: qr_eigenvalues

qr_eigenvalues: $(OBJS)
	$(CC) $(CFLAGS) -o qr_eigenvalues $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o qr_eigenvalues

