#ifndef LOAD_WayangWave_H
#define LOAD_WayangWave_H

#include "start.h"
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"
#include "../ADT/queue.h"
#include "../ADT/listlinier.h"

void load(List *Penyanyi, Map *Album, Set *Lagu, Stack *History, Queue *Urutan, List *Playlist, Word fileName);
/*  Membaca file konfigurasi yang berisi list lagu yang dapat dimainkan.
    I.S. Playlist sudah terdefinisi dan tidak kosong.
    F.S. File konfigurasi terbaca dan list game bertambah.
*/

#endif