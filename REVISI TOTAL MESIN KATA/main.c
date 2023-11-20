#include <stdio.h>
#include "mesinkata.h"

int main(){
    STARTFILE("config.txt");
    ADV();
    ADVWORD();
    int jumlahPenyanyi = strToInteger(currentWord);
    printf("Jumlah penyanyi: %d\n", jumlahPenyanyi);
    ADV();
    IgnoreEnter();
    // ADVFILE();
    // printf("%c", currentChar);
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    /* Mesin karakter AMANNN */
    for (int i = 0; i < jumlahPenyanyi; i++){
        ADVWORD();
        int jumlahalbum = strToInteger(currentWord);
        printf("Jumlah album penyanyi ke-%d: %d\n", i+1, jumlahalbum);
        ADVSENTENCE();
        printf("Nama penyanyi ke-%d: ", i+1);
        printWord(kalimat);
        printf("\n");
        for (int j = 0; j < jumlahalbum; j++){
            ADVWORD();
            int jumlahlagu = strToInteger(currentWord);
            printf("Jumlah lagu album ke-%d: %d\n", j+1, jumlahlagu);
            ADVSENTENCE();
            printf("Nama album ke-%d: ", j+1);
            printWord(kalimat);
            printf("\n");
            for(int k = 0; k < jumlahlagu; k++){
                ADVSENTENCE();
                printf("Nama lagu ke-%d: ", k+1);
                printWord(kalimat);
                printf("\n");
            }
        }
    }
    // ADVWORD();
    // printWord(currentWord);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVWORD();
    // for(int i = 0; i < currentWord.Length; i++){
    //     printf("%c", currentWord.TabWord[i]);
    // }
    return 0;
}