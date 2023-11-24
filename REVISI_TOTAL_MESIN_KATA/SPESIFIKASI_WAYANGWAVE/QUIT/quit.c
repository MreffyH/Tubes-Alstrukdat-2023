#include <stdio.h>
#include "stdlib.h"
#include "quit.h"
#include "../SAVE/saveww.h"

void quit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): "); 
    STARTINPUT();
    Word filename;
    Word Choice;
    Word Choice2;
    Word input1;
    int id;
    int x;
    int y;

    Set S;
    CreateEmptySet(&S);

    MapAlbum MA;
    CreateMapAlbum(&MA, S);

    MapPenyanyi MP;
    CreateMapPenyanyi(&MP, MA);

    ListPenyanyi PL;
    CreateListPenyanyi(&PL, MP);

    DetailSongQ currentSong;

    QueueSong QS;
    CreateEmptyQueue(&QS);

    HistorySong HS;
    CreateEmptyHistorySong(&HS);

    ArrayDin PLY;
    PLY = MakeArrayDin();

    if ( INPUTEQUAL(currentInput,"Y;")){
        wordToString(filename, filename.TabWord);
        SAVEWW(&PL, &filename.TabWord, &PLY, &QS, &HS, &currentSong);
    }
    else if (INPUTEQUAL(currentInput,"N;")){
        printf("================Kamu keluar dari WayangWave================\n");
        printf("  _____  ____  __ __   ___   ____    ____  ____    ____    \n");
        printf(" / ___/ /    ||  |  | /   \\ |    \\  /    ||    \\  /    |\n");
        printf("(   \\_ |  o  ||  |  ||     ||  _  ||  o  ||  D  )|  o  |  \n");
        printf(" \\__  ||     ||  ~  ||  O  ||  |  ||     ||    / |     |  \n");
        printf(" /  \\ ||  _  ||___, ||     ||  |  ||  _  ||    \\ |  _  | \n");
        printf(" \\    ||  |  ||     ||     ||  |  ||  |  ||  .  \\|  |  | \n");
        printf("  \\___||__|__||____/  \\___/ |__|__||__|__||__|\\_||__|__|\n");
        printf("\n=========================================================\n");
        exit(0); // keluar dari program
    }
    else{
        printf("Command tidak diketahui!\n");
    }
}