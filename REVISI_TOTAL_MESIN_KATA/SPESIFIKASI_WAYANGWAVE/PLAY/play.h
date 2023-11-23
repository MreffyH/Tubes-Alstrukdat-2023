/* File: play.h */

#ifndef __PLAY_H_
#define __PLAY_H_

#include "../../boolean.h"

#include "../../mesinkata.h"
#include "../../listmapset.h"
// #include "../../RIvaldi/listdinamis.h"
#include "../../../src/ADT/list/list.h"
#include "../LOAD/load.h"
#include "../../../RIvaldi/arraydin.h"
#include "../../../src/ADT/list/listlinier.h"

void PLAYSONG(ListPenyanyi penyanyi);

void playPlaylist(ArrayDin array);

// void playPlaylist(List *L, const char *penyanyi, const char *album, const char *lagu, int idLagu);
#endif