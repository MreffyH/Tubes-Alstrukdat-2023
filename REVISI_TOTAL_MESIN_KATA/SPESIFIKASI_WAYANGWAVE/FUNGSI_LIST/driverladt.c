#include "ladt.h"
// #include "listdinamis.h"
// gcc -o driverladt driverladt.c ladt.c ../../../src/ADT/list/list.c ../../../src/ADT/mapset/set.c ../../listmapset.c ../../mesinkata.c ../../mesinkarakter.c ../START/start.c ../../../RIvaldi/arraydin.c ../../../src/ADT/list/listlinier.c

#include <stdio.h>
#include <stdlib.h>
#include "../../../RIvaldi/arraydin.h"
#include "../../../src/ADT/list/listlinier.h"

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

    ArrayDin PList;
    MakeArrayDin(PList);

    char *file = "../../config.txt";
    STARTWAYANGWAVE(&PL, file);
    printf("\n");

    // DISPLAYPENYANYI(PL);

    LISTDEFAULT(PL);
    LISTPLAYLIST(PList);
    return 0;
}