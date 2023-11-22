#include "ladt.h"
// #include "listdinamis.h"
// gcc -o driverladt driverladt.c ladt.c ../../../src/ADT/list/list.c ../../../src/ADT/mapset/set.c ../../listmapset.c ../../mesinkata.c ../../mesinkarakter.c ../START/start.c

#include <stdio.h>
#include <stdlib.h>

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

    char *file = "../../config.txt";
    STARTWAYANGWAVE(&PL, file);
    printf("\n");

    DISPLAYPENYANYI(PL);

    LISTDEFAULT(PL);
    return 0;
}