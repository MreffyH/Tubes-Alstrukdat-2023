#ifndef playlist_H
#define playlist_H


#include "../../RIvaldi/arraydin.h"
#include "../FUNGSI_LIST/ladt.h"
#include "../../../src/ADT/list/listlinier.h"
#include "../../REVISI_TOTAL_MESIN_KATA/mesinkata.h"
#include <stdio.h>



/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info_P(P) (P)->info
#define Next_P(P) (P)->next
#define First_P(L) ((L).First)

void CreatePlaylist(ArrayDin *PLY);

void PlaylistADDSong(ArrayDin *PLY, ListPenyanyi penyanyi);

void PlaylistADDAlbum(ArrayDin *PLY, ListPenyanyi penyanyi);

void PlaylistRemove(ArrayDin *PLY, int id, int n);

void PlaylistSwap(ArrayDin *PLY, int id, int x, int y);

void PlaylistDelete(ArrayDin *PLY);

#endif