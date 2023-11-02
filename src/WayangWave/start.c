#include "start.h"
#include <stdio.h>
#include <stdlib.h>

boolean stateWayangWave;

void start(List *Penyanyi, Map *Album, Set *Lagu) {
    STARTWORD();
    while(!isEndWord()) {
        int singer;
        singer = strToInteger(currentWord);
        ADVWORD();
        int i;
        while (i <= singer) 
        {
            CreateEmpty(Penyanyi);
            i++;
        }
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