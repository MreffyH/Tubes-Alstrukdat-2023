#include "start.h"
#include <stdio.h>
#include <stdlib.h>

boolean stateWayangWave;

void start(List *Penyanyi, Map *Album, Set *Lagu) {
    BacaConfig("config.txt", Penyanyi, Album, Lagu);
    if (IsEmpty(*Penyanyi)) {
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


// while(!isEndWord()) {
//         int singer;
//         singer = strToInteger(currentWord);
//         ADVWORD();
//         int i = 0;
//         while (i <= singer) 
//         {
//             CreateEmpty(Penyanyi);
//             i++;
//         }
//     }