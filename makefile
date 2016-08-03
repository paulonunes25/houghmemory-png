CC=gcc
CFLAGS=-I.
DEPS = rtable.h dump.h apriori.h byteType.h
OBJ = hough.o rtable.o dump.o apriori.o byteType.o
EXECUTABLE = hough

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ core $(EXECUTABLE)
