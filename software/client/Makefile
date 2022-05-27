CC = gcc
CFLAGS =
OBJ = main.o network.o lightbulb.o 

%.o: %.c  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

clean:
	rm client