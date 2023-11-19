#ifndef listmapset_H
#define listmapset_H

#include "../mapset/set.h"
#include "../list/list.h"
// #include "../map & set/set.h"
// #include "../mesin/mesinkalimat.h"

#define MaxElAlbum 40
#define MaxElSinger 50
#define NOTFOUND -1

typedef struct{
	Sentence namaAlbum;
	Set setlagu;
} MapAlbum;

typedef struct{
	Sentence namaPenyanyi;
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

void AddPenyanyi(ListPenyanyi *penyanyi, Sentence nama);

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Sentence namaPenyanyi);

void AddAlbum(ListPenyanyi *penyanyi, Sentence namaPenyanyi, Sentence namaAlbum);

void AddLagu(ListPenyanyi *penyanyi, Sentence namaPenyanyi, Sentence namaAlbum, Sentence namaLagu);


#endif