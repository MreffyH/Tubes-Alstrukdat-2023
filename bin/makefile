IDIR =../src/ADT
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj

_DEPS = list.h listlinier.h map.h mesinkarakter.h mesinkata.h queue.h set.h stack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = list.o listlinier.o map.o mesinkarakter.o mesinkata.o queue.o set.o stack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

wayangwave: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 