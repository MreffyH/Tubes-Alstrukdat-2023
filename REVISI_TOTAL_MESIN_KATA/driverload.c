#include"load.h"
#include"mesinkata.h"
#include"../src/ADT/queue/queue.h"
#include"../src/ADT/stack/stack.h"
// gcc -o driverload driverload.c load.c start.c mesinkarakter.c mesinkata.c listmapset.c ../src/ADT/mapset/set.c ../src/ADT/queue/queue.c ../src/ADT/stack/stack.c

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

    QueueSong QS;
    CreateEmptyQueue(&QS);

    HistorySong HS;
    CreateEmptyHistorySong(&HS);

    STARTINPUT();
    Word file = currentInput;
    LOADWAYANGWAVE(&PL, file.TabWord, &QS, &HS);

    printf("\n");
    DISPLAYPENYANYI(PL);
    printf("\n");

    DISPLAYALBUM(PL);
    printf("\n");

    DISPLAYLAGU(PL);
    printf("\n");

    printf("INI QUEUENYA\n");
    displayQueue(QS);
    printf("\n");

    DisplayHistorySong(HS);

    return 0;
}