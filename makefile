CC=gcc
CFLAGS=-I.
DEPS = rtable.h wset.h
OBJ = hough.o rtable.o wset.o
EXECUTABLE = hough

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ core $(EXECUTABLE)