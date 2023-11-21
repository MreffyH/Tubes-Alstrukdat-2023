#ifndef listmapset_H
#define listmapset_H

#include "../src/ADT/mapset/set.h"
// #include "../map & set/set.h"
// #include "../mesin/mesinkalimat.h"
#include <stdlib.h>

#define MaxElAlbum 20
#define MaxElSinger 20
#define NOTFOUND -1

// typedef struct
// {
//     infotypeSet Elements[MaxElSet];
//     addrSer Count;
// } Set;

typedef struct{
	Word namaAlbum;
	Set setlagu;
} MapAlbum;

typedef struct{
	Word namaPenyanyi;
	MapAlbum mapalbum[MaxElAlbum];
	int countalbum;
} MapPenyanyi;

typedef struct{
	MapPenyanyi penyanyi_ke[MaxElSinger];
	int countpenyanyi;
} ListPenyanyi;

#define Jumlahpenyanyi(L) (L).countpenyanyi
#define Jumlahalbum(L) (L).countalbum

void CreateMapAlbum(MapAlbum *mapalbum, Set S);

void CreateMapPenyanyi(MapPenyanyi *mappenyanyi, MapAlbum listalbum);

void CreateListPenyanyi(ListPenyanyi *penyanyi, MapPenyanyi mappenyanyi);

void AddPenyanyi(ListPenyanyi *penyanyi, Word nama);

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Word namaPenyanyi);

void AddAlbum(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum);

int SearchAlbum_ke(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum);

void AddLagu(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum, Word namaLagu);


#endif