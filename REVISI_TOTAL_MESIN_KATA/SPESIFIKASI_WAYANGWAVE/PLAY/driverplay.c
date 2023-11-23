/* File: driverplay.c */
// gcc -o driverplay driverplay.c play.c ../../mesinkata.c ../../mesinkarakter.c ../../listmapset.c ../LOAD/load.c ../START/start.c ../../../src/ADT/mapset/set.c  ../../../src/ADT/list/list.c ../../ADT_WAYANGWAVE/QUEUE/queue.c ../../ADT_WAYANGWAVE/STACK/stack.c ../../../RIvaldi/arraydin.c ../../../src/ADT/list/listlinier.c

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

int main()
{
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

    char *file = "../../user1.txt";
    LOADWAYANGWAVE(&PL, file, &QS, &HS, &PLY, &currentSong);
    printf("\n");

    // PLAYSONG(PL);

    playPlaylist(PLY, &currentSong, &HS, &QS);

    return 0;
}