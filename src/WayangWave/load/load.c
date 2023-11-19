#include "load.h"

void load(List *Penyanyi, Map *Album, Set *Lagu, Stack *History, Queue *Urutan, List *Playlist, Word fileName) {
    
    char file[50] = ".txt";
    for (int i = 0; i < fileName.Length; i++) {
        file[i] = fileName.TabWord[i];
    }
    file[fileName.Length] = '\0';

    bacaConfig(file, Penyanyi, Album, Lagu);

    ADVWORD(); // bagian urutan (queue)
    int jumlahurutan = 0;
    for (int i = 0; i <= currentWord.Length; i++) { // Baris pertama
        jumlahurutan *= 10;
        jumlahurutan += currentWord.TabWord[i] - '0';
    }
    for (int j = 0; j <= jumlahurutan; j++) {
        ADVWORD();
        enqueue(Urutan, currentWord);
    }

    ADVWORD(); // bagian history (stack)
    int jumlahhistory = 0;
    for (int i = 0; i <= currentWord.Length; i++) { 
        jumlahhistory *= 10;
        jumlahhistory += currentWord.TabWord[i] - '0';
    }
    for (int j = 0; j <= jumlahhistory; j++) {
        ADVWORD();
        Push(History, currentWord);
    }

    ADVWORD();
    int jumlahplaylist = 0;
    for (int i = 0; i <= currentWord.Length; i++) {
        jumlahplaylist *= 10;
        jumlahplaylist += currentWord.TabWord[i] - '0';
    }
    for (int j = 0; j < jumlahplaylist; j++) {
        ADVWORD();
        int laguplaylist = 0;
        for (int i = 0; i <= currentWord.Length; i++) { 
            laguplaylist *= 10;
            laguplaylist += currentWord.TabWord[i] - '0';
        }
        ADVWORD();
        Insert(Playlist, currentWord); // masukin judul playlistnya (gatau Insertnya pke yg mana)
        for (int i = 0; i <= laguplaylist; i++) {
                ADVWORD();
                InsVFirst(Playlist, currentWord);
            }
    }
}