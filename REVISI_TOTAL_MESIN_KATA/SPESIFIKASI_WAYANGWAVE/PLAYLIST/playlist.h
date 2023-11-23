#ifndef playlist_H
#define playlist_H


#include "../../../RIvaldi/arraydin.h"
#include "../FUNGSI_LIST/ladt.h"
#include "../../../src/ADT/list/listlinier.h"
#include "../../mesinkata.h"
#include "../../mesinkarakter.h"
#include <stdio.h>

void CreatePlaylist(ArrayDin *PLY);

void PlaylistADDSong(ArrayDin *PLY, ListPenyanyi penyanyi);

void PlaylistADDAlbum(ArrayDin *PLY, ListPenyanyi penyanyi);

void PlaylistRemove(ArrayDin *PLY, int id, int n);

void PlaylistSwap(ArrayDin *PLY, int id, int x, int y);

void PlaylistDelete(ArrayDin *PLY);

#endif