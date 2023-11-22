#ifndef song_H
#define song_H

#include "../../mesinkata.h"
#include "../../../src/ADT/stack/stack.h"
#include "../../../src/ADT/queue/queue.h"

void songNext(QueueSong *q, HistorySong *s, DetailSongQ *cs);

void songPrevious(QueueSong *q, HistorySong *s, DetailSongQ *cs);

#endif