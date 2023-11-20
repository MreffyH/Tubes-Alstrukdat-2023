#include <stdio.h>
#include "mesinkata.h"

int main(){
    STARTFILE("user1.txt");
    ADV();
    ADVWORD();
    int jumlahPenyanyi = strToInteger(currentWord);
    printf("Jumlah penyanyi: %d\n", jumlahPenyanyi);
    ADV();
    IgnoreEnter();
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
    ADVLOAD();
    if(isNotNone(kalimat)){
        printf("LAGU YANG SEDANG DIMAINKAN\n");
        printf("Artis : ");
        printWord(kalimat);
        printf("\n");
        ADVLOAD();
        printf("Judul Album: ");
        printWord(kalimat);
        printf("\n");
        ADVLOAD();
        printf("Judul Lagu: ");
        printWord(kalimat);
        printf("\n");
    }
    else{
        printf("TIDAK ADA LAGU YANG SEDANG DIMAINKAN\n");
    }
    ADVSENTENCE();
    
    return 0;
}