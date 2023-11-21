/* File: load.c */

#include"load.h"


#include"stdio.h"
#include"stdlib.h"

void LOADWAYANGWAVE(char *filestart) {
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
    printf("\n");
    /* MASUK KE BAGIAN LOAD... LAGU YANG SEDANG DIMAINKAN */
    IgnoreEnter();
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
        IgnoreEnter();
        ADVLOAD();
        printf("Judul Lagu: ");
        printWord(kalimat);
        printf("\n");
    }
    else{
        printf("TIDAK ADA LAGU YANG SEDANG DIMAINKAN\n");
    }
    /* MASUK KE BAGIAN QUEUE */
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahlaguqueue = strToInteger(kalimat);
    printf("Jumlah record lagu dalam queue: %d\n", jumlahlaguqueue);
    for(int i = 0; i < jumlahlaguqueue; i++){
        IgnoreEnter();
        ADVLOAD();
        printf("QUEUE KE-%d\n", i+1);
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
    /* MASUK KE BAGIAN RIWAYAT */
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahlaguriwayat = strToInteger(kalimat);
    printf("Jumlah record riwayat pemutaran lagu: %d\n", jumlahlaguriwayat);
    for(int i = 0; i < jumlahlaguriwayat; i++){
        IgnoreEnter();
        ADVLOAD();
        printf("RIWAYAT KE-%d\n", i+1);
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
    /* MASUK KE BAGIAN PLAYLIST */
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahplaylist = strToInteger(kalimat);
    printf("Jumlah playlist: %d", jumlahplaylist);
    if(jumlahplaylist != 0){
        printf("\n");
        IgnoreEnter();
    }
    for(int i = 0; i < jumlahplaylist; i++){
        ADVWORD();
        int jumlahlaguplaylist = strToInteger(currentWord);
        printf("Jumlah lagu dalam playlist ke-%d: %d\n", i+1, jumlahlaguplaylist);
        ADVSENTENCE();
        printf("Judul playlist ke-%d: ", i+1);
        printWord(kalimat);
        if (jumlahlaguplaylist != 0){
            printf("\n");
            IgnoreEnter();
        }
        for(int j = 0; j < jumlahlaguplaylist; j++){
            if((i == jumlahplaylist-1) && (j == jumlahlaguplaylist-1)){
                ADVLOAD();
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
            }
            else{
                ADVLOAD();
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
                IgnoreEnter();
            }
        }
    }
}