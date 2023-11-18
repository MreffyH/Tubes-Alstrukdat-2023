#ifndef START_WayangWave_H
#define START_WayangWave_H

#include "../ADT/listmapset/listmapset.h"
#include "../ADT/mesin/mesinkalimat.h"

void start(char *input, List *Penyanyi, Map *Album, Set *Lagu);
/*  Membaca file konfigurasi default yang berisi list lagu yang dapat dimainkan.
    I.S. StateWayangWave bernilai sembarang.
    F.S. File konfigurasi terbaca dan list lagu bertambah. StateWayangWave true.
*/

#endif