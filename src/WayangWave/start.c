#include "start.h"
#include <stdio.h>
#include <stdlib.h>

boolean stateWayangWave;
FILE *fc;

void start(List *PlaylistLagu, List Penyanyi, Set Lagu) {

    if (!IsEmpty(*PlaylistLagu)) {
        printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        stateWayangWave = true;
        *fc = fopen("config.txt", "w");
    } else {
        stateWayangWave = false;
    }
}
/*  Membaca file konfigurasi default yang berisi list lagu yang dapat dimainkan.
    I.S. StateSPOTIFY bernilai sembarang.
    F.S. File konfigurasi terbaca dan list lagu bertambah. StateSPOTIFY true.
*/