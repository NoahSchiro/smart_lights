CC = gcc
CFLAGS =
OBJ = main.o network.o 

%.o: %.c  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

clean:
	rm server
