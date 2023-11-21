/* File = start.c */
#include"start.h"

#include<stdio.h>
#include<stdlib.h>

void STARTWAYANGWAVE(char *filestart) {
    STARTKATAFILE(filestart);
    ADV();
    ADVWORD();
    int jumlahpenyanyi = strToInteger(currentWord);
    printf("%d\n", jumlahpenyanyi);
    ADV();
    IgnoreEnter();
    for (int i = 0; i < jumlahpenyanyi; i++){
        ADVWORD();
        int jumlahalbum = strToInteger(currentWord);
        printf("%d ", jumlahalbum);
        ADVSENTENCE();
        IgnoreEnter();
        printWord(kalimat);
        printf("\n");
        for (int j = 0; j < jumlahalbum; j++){
            ADVWORD();
            int jumlahlagu = strToInteger(currentWord);
            printf("%d ", jumlahlagu);
            ADVSENTENCE();
            IgnoreEnter();
            printWord(kalimat);
            printf("\n");
            for(int k = 0; k < jumlahlagu; k++){
                if((i == jumlahpenyanyi-1) && (j == jumlahalbum-1) && (k == jumlahlagu-1)){
                    ADVSENTENCE();
                    printWord(kalimat);
                }
                else{
                    ADVSENTENCE();
                    IgnoreEnter();
                    printWord(kalimat);
                    printf("\n");
                }
            }
        }
    }
}