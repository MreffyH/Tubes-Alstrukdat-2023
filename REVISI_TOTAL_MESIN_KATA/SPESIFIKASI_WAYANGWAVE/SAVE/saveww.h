#ifndef _SAVE_H_
#define _SAVE_H_

#include "../../ADT_WAYANGWAVE/QUEUE/queue.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"
#include "../../mesinkata.h"
#include "../../../RIvaldi/arraydin.h"
#include "../../listmapset.h"

static FILE *file;

void SAVEWW(ListPenyanyi *PL, char *namafile, ArrayDin *PLY, QueueSong *QS, HistorySong *HS, DetailSongQ *CS);

#endif