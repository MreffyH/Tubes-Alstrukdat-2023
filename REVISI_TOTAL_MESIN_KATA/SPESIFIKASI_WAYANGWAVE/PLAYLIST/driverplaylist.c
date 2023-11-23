#include "playlist.h"
#include <stdio.h>
#include "../LOAD/load.h"

// gcc -o driverplaylist driverplaylist.c ../LOAD/load.c ../START/start.c ../../mesinkarakter.c ../../mesinkata.c ../../listmapset.c ../../../src/ADT/mapset/set.c ../../ADT_WAYANGWAVE/QUEUE/queue.c ../../ADT_WAYANGWAVE/STACK/stack.c ../../../src/ADT/list/listlinier.c ../../../RIvaldi/arraydin.c playlist.c


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

    CreatePlaylist(&PLY);

    //PlaylistADDSong(&PLY, PL);

    PlaylistADDAlbum(&PLY, PL);

    // PlaylistRemove(&PLY,  1, 2);

    // PlaylistSwap(&PLY, 1, 0, 1);

    //PlaylistDelete(&PLY);
}