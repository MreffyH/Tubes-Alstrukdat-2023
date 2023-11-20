#ifndef listmapset_H
#define listmapset_H

#include "set.h"
// #include "../map & set/set.h"
// #include "../mesin/mesinkalimat.h"

#define MaxElAlbum 40
#define MaxElSinger 50
#define NOTFOUND -1

typedef struct{
	Word namaAlbum;
	Set setlagu;
} MapAlbum;

typedef struct{
	Word namaPenyanyi;
	MapAlbum listalbum[MaxElAlbum];
	int countalbum;
} MapPenyanyi;

typedef struct{
	MapPenyanyi penyanyi_ke[MaxElSinger];
	int countpenyanyi;
} ListPenyanyi;

#define Jumlahpenyanyi(L) (L).countpenyanyi
#define Jumlahalbum(L) (L).countalbum

void CreateListPenyanyi(ListPenyanyi *penyanyi);

void AddPenyanyi(ListPenyanyi *penyanyi, Word nama);

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Word namaPenyanyi);

void AddAlbum(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum);

int SearchAlbum_ke(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum);

void AddLagu(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum, Word namaLagu);


#endif