#include"load.h"
#include"mesinkata.h"
// gcc -o driverload driverload.c load.c start.c mesinkarakter.c mesinkata.c listmapset.c ../src/ADT/mapset/set.c

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

    STARTINPUT();
    Word file = currentInput;
    LOADWAYANGWAVE(&PL, file.TabWord);

    DISPLAYPENYANYI(PL);

    DISPLAYALBUM(PL);

    DISPLAYLAGU(PL);

    return 0;
}