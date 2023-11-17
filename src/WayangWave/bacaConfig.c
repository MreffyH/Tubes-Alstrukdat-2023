#include "bacaConfig.h"

// ADVWORD() diganti ADVSENTENCE()
void bacaConfig(char *filesrc, List *Penyanyi, Map *Album, Set *Lagu) {
    FILE* input = fopen("config.txt", "r");
    
    if (input == NULL) {
        printf("File tidak ditemukan. ");
    } else {
        STARTWORD(input);
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
            AcquireSentence();
            SetElmt(Penyanyi, j , currentWord); // masukin penyanyi
            for (int j = 0; j < jumlahAlbum; j++) { // di dalam album
                ADVWORD(); // baris ketiga angka
                for (int i = 0; i <= currentWord.Length; i++) {
                    jumlahLagu *= 10;
                    jumlahLagu += currentWord.TabWord[i] - '0';
                }
                AcquireSentence();
                Insert(Album, currentWord, Lagu); // ini blum ngerti 
                for (int i = 0; i < jumlahLagu; i++) {
                    AcquireSentence();
                    Insert(Album, currentWord, Lagu);
                }
            }
        }
    }  
} 