/* File = start.c */
#include"start.h"

#include<stdio.h>
#include<stdlib.h>

void STARTWAYANGWAVE(char *file) {
    STARTFILE(file);
    ADV();
    ADVWORD();
    int jumlahpenyanyi = strToInteger(currentWord);
    printf("%d\n", jumlahpenyanyi);
    // printf("Jumlah penyanyi: %d\n", jumlahpenyanyi);
    ADV();
    IgnoreEnter();
    for (int i = 0; i < jumlahpenyanyi; i++){
        ADVWORD();
        int jumlahalbum = strToInteger(currentWord);
        printf("%d ", jumlahalbum);
        // printf("Jumlah album penyanyi ke-%d: %d\n", i+1, jumlahalbum);
        ADVSENTENCE();
        IgnoreEnter();
        // printf("Nama penyanyi ke-%d: ", i+1);
        printWord(kalimat);
        printf("\n");
        for (int j = 0; j < jumlahalbum; j++){
            ADVWORD();
            int jumlahlagu = strToInteger(currentWord);
            printf("%d ", jumlahlagu);
            // printf("Jumlah lagu album ke-%d: %d\n", j+1, jumlahlagu);
            ADVSENTENCE();
            IgnoreEnter();
            // printf("Nama album ke-%d: ", j+1);
            printWord(kalimat);
            printf("\n");
            for(int k = 0; k < jumlahlagu; k++){
                if((i == jumlahpenyanyi-1) && (j == jumlahalbum-1) && (k == jumlahlagu-1)){
                    ADVSENTENCE();
                    // printf("Nama lagu ke-%d: ", k+1);
                    printWord(kalimat);
                }
                else{
                    ADVSENTENCE();
                    IgnoreEnter();
                    // printf("Nama lagu ke-%d: ", k+1);
                    printWord(kalimat);
                    printf("\n");
                }
            }
        }
    }
}

// int main() {
//     char *file = "user1.txt";
//     STARTWAYANGWAVE(file);
// }