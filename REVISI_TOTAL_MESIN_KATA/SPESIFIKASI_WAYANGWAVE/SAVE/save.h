#ifndef __SAVE_H_
#define __SAVE_H_

#include "../../mesinkata.h"
#include "../START/start.h"
#include "../../listmapset.h"
#include "../../ADT_WAYANGWAVE/QUEUE/queue.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"
#include "../../../RIvaldi/arraydin.h"
#include "../../../src/ADT/list/listlinier.h"

void LOADWAYANGWAVE(ListPenyanyi *PL, char *fileload, QueueSong *QS, HistorySong *HS, ArrayDin *PLY, DetailSongQ *currentSong);

#endif