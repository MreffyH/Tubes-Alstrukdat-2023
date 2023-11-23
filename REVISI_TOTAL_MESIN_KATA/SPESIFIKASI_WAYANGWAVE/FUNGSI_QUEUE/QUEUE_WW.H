#ifndef _QUEUE_WW_H_
#define _QUEUE_WW_H_

#include "../../../src/ADT/list/list.h"
#include "../../listmapset.h"
#include "../../mesinkata.h"
#include "../../mesinkarakter.h"
#include "../../../RIvaldi/arraydin.h"
#include "../../../src/ADT/list/listlinier.h"
#include "../START/start.h"
#include "../../ADT_WAYANGWAVE/QUEUE/queue.h"

void QUEUESONG(ListPenyanyi penyanyi, QueueSong *lagu);

void QUEUEPLAYLIST(QueueSong *laguplaylist, ArrayDin array);

void QUEUESWAP(QueueSong *laguplaylist, int x, int y);

void QUEUEREMOVE(QueueSong *laguplaylist, int id);

void QUEUECLEAR(QueueSong *urutan);

#endif /* LISTDEFAULT_H */