#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "main.c"
#include "listmapset.h"
#include "mesinkata.h"
#include "listdinamis.h"


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