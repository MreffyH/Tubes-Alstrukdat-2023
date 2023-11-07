#include "bacaConfig.h"

void BacaConfig(char *filesrc, List *Penyanyi, Map *Album, Set *Lagu) {
    STARTWORD();
    int singer = 0;
    int albumnya = 0;
    int lagunya = 0;
    for (int i = 0; i <= currentWord.Length; i++) { // Baris pertama
        singer *= 10;
        singer += currentWord.TabWord[i] - '0';
    }

    ADVWORD(); // baris kedua angka
    for (int i = 0; i <= currentWord.Length; i++) {
        albumnya *= 10;
        albumnya += currentWord.TabWord[i] - '0';
    }

    for (int i = 0; i < singer; i++) { // masukin penyanyi-nya
        ADVWORD();
        SetElmt(Penyanyi, i , currentWord);
    }

    ADVWORD(); // baris ketiga angka
    for (int i = 0; i <= currentWord.Length; i++) {
        lagunya *= 10;
        lagunya += currentWord.TabWord[i] - '0';
    }

    for (int i = 0; i < albumnya; i++) { // masukin albumnya-nya, kayaknya buat nama albumnya harus list juga?
        ADVWORD();
        Insert(Album, Penyanyi, currentWord);
    }

    for (int i = 0; i < lagunya; i++) {
        ADVWORD();

    }
}   