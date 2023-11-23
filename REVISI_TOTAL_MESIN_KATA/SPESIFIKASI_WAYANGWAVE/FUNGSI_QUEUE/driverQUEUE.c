#include "QUEUE_WW.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"
#include "../LOAD/load.h"
// gcc -o driverQUEUE driverQUEUE.c ../LOAD/load.c ../START/start.c ../../mesinkarakter.c ../../mesinkata.c ../../listmapset.c ../../../src/ADT/mapset/set.c ../../ADT_WAYANGWAVE/QUEUE/queue.c ../../ADT_WAYANGWAVE/STACK/stack.c ../../../src/ADT/list/listlinier.c ../../../RIvaldi/arraydin.c playlist.c

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
    char *file = "../../user1.txt";
    LOADWAYANGWAVE(&PL, file, &QS, &HS, &PLY, &currentSong);
}