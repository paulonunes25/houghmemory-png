CC=gcc
CFLAGS=-I.
DEPS = rtable.h wset.h dump.h apriori.h byteType.h
OBJ = hough.o rtable.o wset.o dump.o apriori.o byteType.o
EXECUTABLE = hough

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ core $(EXECUTABLE)