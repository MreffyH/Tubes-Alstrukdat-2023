#include "bacaConfig.h"

// ADVWORD() diganti ADVSENTENCE()
void bacaConfig(List *Penyanyi, Map *Album, Set *Lagu) {
    printf("Jalan gak?\n");
    // char dir[50] = "./data/";

    // int i = 0;
    // while (filesrc[i]) {
    //     dir[7 + i] = filesrc[i];
    //     i++;
    // }
    // dir[7 + i] = '\0';
    // FILE* input = fopen(dir, "r")
    FILE* input = fopen("config.txt", "r");
    printf("Jalan gak?\n");
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
            PrintSentence(currentKalimat);
            SetElmt(Penyanyi, j , currentKalimat); // masukin penyanyi
            for (int j = 0; j < jumlahAlbum; j++) { // di dalam album
                ADVWORD(); // baris ketiga angka
                for (int i = 0; i <= currentWord.Length; i++) {
                    jumlahLagu *= 10;
                    jumlahLagu += currentWord.TabWord[i] - '0';
                }
                AcquireSentence();
                PrintSentence(currentKalimat);
                Sentence namaAlbum = currentKalimat;
                for (int i = 0; i < jumlahLagu; i++) {
                    AcquireSentence();
                    PrintSentence(currentKalimat);
                    InsertMap(Album, namaAlbum, currentKalimat);
                }
            }
        }
    }  
    fclose(input);
} 