# run:
# 	gcc wayangwave/Start/start.c ADT/list/list.c ADT/queue/queue.c ADT/mesin/mesinkarakter.c ADT/mesin/mesinkata.c ADT/mesin/mesinkalimat.c -o main
# 	./main
# tes:
# 	echo "Testing"

# belum ni : ADT/Inisialisasi/inisialisasi.c ADT/Playlist/Playlist.c ADT/Play/Play.c ADT/Load/Load.c ADT/Song/Song.c ADT/Save/save.c ADT/Help/help.c ADT/Status/Status.c ADT/Queue/queue.c ADT/Stack/RiwayatLagu.c ADT/LinkedList/linkedlist.c ADT/array/arraydinamis.c ADT/MapSetList/mapsetlist.c main.c
# IDIR =../src/ADT
# CC=gcc
# CFLAGS=-I$(IDIR)

# ODIR=obj

# _DEPS = list.h listlinier.h map.h mesinkarakter.h mesinkata.h queue.h set.h stack.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = list.o listlinier.o map.o mesinkarakter.o mesinkata.o queue.o set.o stack.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# wayangwave: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

# .PHONY: clean

# clean:
# 	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

CFLAGS = -Wno-implicit-function-declaration

final: test.o start.o listmapset.o list.o set.o mesinkalimat.o mesinkata.o mesinkarakter.o

test.o: test.c
	gcc $(CFLAGS) -c ../WayangWave/test.c

start.o: start.c
	gcc $(CFLAGS) -c ../WayangWave/start/start.c

listmapset.o: listmapset.c
	gcc $(CFLAGS) -c ../ADT/listmapset/listmapset.c

list.o: list.c
	gcc $(CFLAGS) -c ../ADT/list/list.c

map.o: map.o
	gcc $(CFLAGS) -c ../ADT/mapset/map.c

set.o: set.c
	gcc $(CFLAGS) -c ../ADT/mapset/set.c

mesinkalimat.o: mesinkalimat.c
	gcc $(CFLAGS) -c ../ADT/mesin/mesinkalimat.c

mesinkata.o: mesinkata.c
	gcc $(CFLAGS) -c ../ADT/mesin/mesinkata.c

mesinkarakter.o: mesinkarakter.c
	gcc $(CFLAGS) -c ../ADT/mesin/mesinkarakter.c

