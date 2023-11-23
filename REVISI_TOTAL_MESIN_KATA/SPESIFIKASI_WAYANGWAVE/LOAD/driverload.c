#include "load.h"
#include "../../mesinkata.h"
#include "../../ADT_WAYANGWAVE/QUEUE/queue.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"
// gcc -o driverload driverload.c load.c ../START/start.c ../../mesinkarakter.c ../../mesinkata.c ../../listmapset.c ../../../src/ADT/mapset/set.c ../../../src/ADT/queue/queue.c ../../../src/ADT/stack/stack.c ../../../src/ADT/list/listlinier.c ../../../RIvaldi/arraydin.c
// terminal ../../user1.txt

#include<stdio.h>
#include<stdlib.h>

int main()
{
    // char *file = "user1.txt";
    // STARTWAYANGWAVE(file);
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
    // PrintArrayDin(PLY);
    STARTINPUT();
    Word file = currentInput;
    LOADWAYANGWAVE(&PL, file.TabWord, &QS, &HS, &PLY, &currentSong);

    // printf("\n");
    // DISPLAYPENYANYI(PL);
    // printf("\n");

    // DISPLAYALBUM(PL);
    // printf("\n");

    // DISPLAYLAGU(PL);
    // printf("\n");

    // printf("INI QUEUENYA\n");
    // displayQueue(QS);
    // printf("\n");

    // DisplayHistorySong(HS);
    
    // PrintArrayDin(PLY);

    printWord(currentSong.namaPenyanyiQ);
    printf("\n");
    printWord(currentSong.namaAlbumQ);
    printf("\n");
    printWord(currentSong.namaLaguQ);
    printf("\n");
    return 0;
}