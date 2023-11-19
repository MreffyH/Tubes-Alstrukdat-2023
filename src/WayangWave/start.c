#include "start.h"
#include <stdio.h>
#include <stdlib.h>

void start(char *input, List *Penyanyi, Map *Album, Set *Lagu) {
    STARTFILE(input);
    int jumlahPenyanyi = 0;
    int jumlahAlbum = 0;
    int jumlahLagu = 0;

    /* Angka Jumlah Penyanyi*/
    jumlahPenyanyi = strToInteger(currentWord);

    /* Berdasarkan Jumlah Penyanyi...*/
    for (int inSinger = 0; inSinger < jumlahPenyanyi; inSinger++) { // di dalam penyanyi
        ADVWORD(); 
        /* Angka Jumlah Album */
        jumlahAlbum = strToInteger(currentWord);
        
        AcquireSentence();
        Sentence PenyanyiNow = currentKalimat;
        AddPenyanyi(&Penyanyi, currentKalimat); // Input penyanyi ke list
        /* Berdasarkan Jumlah Album... */
        for (int inAlbum = 0; inAlbum < jumlahAlbum; inAlbum++) { // di dalam album
            ADVWORD(); // baris ketiga angka
            /* Angka Jumlah Lagu */
            jumlahLagu = strToInteger(currentWord);
            AcquireSentence();
            Sentence AlbumNow = currentKalimat;
            AddAlbum(&Penyanyi, PenyanyiNow, currentKalimat); // input album ke map
            /* Berdasarkan Jumlah Lagu...*/
            for (int i = 0; i < jumlahLagu; i++) { // Input lagu ke set
                AcquireSentence();
                AddLagu(&Penyanyi, PenyanyiNow, AlbumNow, currentKalimat);
            }
        }
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