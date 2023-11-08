#include "bacaConfig.h"

// Masukin pengyanyi, album dan lagu dalam bentuk apa?
void BacaConfig(char *filesrc, List *Penyanyi, Map *Album, Set *Lagu) {
    STARTWORD();
    int jumlahPenyanyi = 0;
    int jumlahAlbum = 0;
    int jumlahLagu = 0;

    for (int i = 0; i <= currentWord.Length; i++) { // Baris pertama
        jumlahPenyanyi *= 10;
        jumlahPenyanyi += currentWord.TabWord[i] - '0';
    }

    for (int j = 0; j < jumlahPenyanyi; j++) { // di dalam penyanyi
        ADVWORD(); // baris kedua angka
        for (int i = 0; i <= currentWord.Length; i++) {
            jumlahAlbum *= 10;
            jumlahAlbum += currentWord.TabWord[i] - '0';
        }
        ADVWORD();
        SetElmt(Penyanyi, j , currentWord); // masukin penyanyi
        for (int j = 0; j < jumlahAlbum; j++) { // di dalam album
            ADVWORD(); // baris ketiga angka
            for (int i = 0; i <= currentWord.Length; i++) {
                jumlahLagu *= 10;
                jumlahLagu += currentWord.TabWord[i] - '0';
            }
            ADVWORD();
            Insert(Album, currentWord, Lagu); // ini blum ngerti 
            for (int i = 0; i < jumlahLagu; i++) {
                ADVWORD();
                Insert(Album, currentWord, Lagu);
            }
        }
    }
}   