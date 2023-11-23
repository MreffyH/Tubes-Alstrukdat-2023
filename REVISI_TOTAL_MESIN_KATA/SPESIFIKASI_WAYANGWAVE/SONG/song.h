#ifndef song_H
#define song_H

#include "../../mesinkata.h"
#include "../../ADT_WAYANGWAVE/QUEUE/queue.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"

void songNext(QueueSong *q, HistorySong *s, DetailSongQ *cs);

void songPrevious(QueueSong *q, HistorySong *s, DetailSongQ *cs);

#endif