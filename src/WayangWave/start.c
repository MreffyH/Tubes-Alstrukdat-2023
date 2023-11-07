#include "start.h"
#include <stdio.h>
#include <stdlib.h>

boolean stateWayangWave;

void start(List *Penyanyi, Map *Album, Set *Lagu) {
    STARTWORD();
    int singer;
    for (int i = 0; i <= currentWord.Length; i++) {
        singer *= 10;
        singer += currentWord.TabWord[i] - '0';
    }
    for (int i = 0; i < singer; i++) {
        ADVWORD();
        Set;
    }
}
/*  Membaca file konfigurasi default yang berisi list lagu yang dapat dimainkan.
    I.S. StateSPOTIFY bernilai sembarang.
    F.S. File konfigurasi terbaca dan list lagu bertambah. StateSPOTIFY true.
*/
// if (!IsEmpty(*Penyanyi)) {
//         printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
//         stateWayangWave = true;
//     } else {
//         stateWayangWave = false;
//     }

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