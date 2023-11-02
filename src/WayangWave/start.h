#ifndef START_WayangWave_H
#define START_WayangWave_H

#include "../adt/mesinkata.h"
#include "../adt/set.h"
#include "../adt/map.h"
#include "../adt/listlinier.h"

void start(List Penyanyi, Map Album, Set Lagu);
/*  Membaca file konfigurasi default yang berisi list lagu yang dapat dimainkan.
    I.S. StateWayangWave bernilai sembarang.
    F.S. File konfigurasi terbaca dan list lagu bertambah. StateWayangWave true.
*/

#endif