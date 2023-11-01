#include "start.h"
#include<stdio.h>

boolean stateWayangWave;

void start(List *PlaylistLagu, List Penyanyi, Set Lagu) {

    if (!IsEmpty(*PlaylistLagu)) {
        printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        stateWayangWave = true;
    } else {
        stateWayangWave = false;
    }
}
/*  Membaca file konfigurasi default yang berisi list lagu yang dapat dimainkan.
    I.S. StateSPOTIFY bernilai sembarang.
    F.S. File konfigurasi terbaca dan list lagu bertambah. StateSPOTIFY true.
*/