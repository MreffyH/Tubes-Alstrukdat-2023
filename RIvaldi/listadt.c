#include "../src/ADT/list/list.h"
#include "../REVISI_TOTAL_MESIN_KATA/listmapset.h"
#include "../REVISI_TOTAL_MESIN_KATA/mesinkata.h"
// #include "listdinamis.h"
// gcc -o listadt listadt.c ../src/ADT/list/list.c ../REVISI_TOTAL_MESIN_KATA/listmapset.c ../REVISI_TOTAL_MESIN_KATA/mesinkata.c ../src/ADT/mapset/set.c ../REVISI_TOTAL_MESIN_KATA/mesinkarakter.c

#include <stdio.h>
#include <stdlib.h>

void LISTDEFAULT(ListPenyanyi penyanyi)
{
    printf("Daftar Penyanyi : \n");
    int i;
    for (i = 0; i < (penyanyi).countpenyanyi; i++)
    {
        Word name;
        name = DuplicateKata(penyanyi.penyanyi_ke[i].namaPenyanyi);
        printf("%d. ", i + 1);
        printWord(name);
        printf("\n");
    }
    printf("Ingin melihat album yang ada?(Y/N): ");
    STARTINPUT();
    printf("\n");
    Word idx;
    idx.TabWord[0] = 'Y';
    idx.Length = 1;
    if (IsKataEqual(currentInput, idx))
    {
        printf("Pilih penyanyi untuk melihat album mereka: \n");
        STARTINPUT();
        Word nama_penyanyi = DuplicateKata(currentInput);
        int urutan = SearchPenyanyi_ke(penyanyi, currentInput);
        if (urutan != NOTFOUND)
        {
            printf("Daftar Album oleh ");
            printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            printf(" :\n");
            int jum_album;
            jum_album = penyanyi.penyanyi_ke[urutan].countalbum;
            for (i = 0; i < jum_album; i++)
            {
                printf("%d. ", i + 1);
                Word name_album;
                name_album = penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum;
                printWord(name_album);
                printf("\n");
            }
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            STARTINPUT();
            if (IsKataEqual(currentInput, idx))
            {
                printf("Pilih album untuk melihat lagu yang ada di album : ");
                STARTINPUT();
                printf("\n");
                int search_album = SearchAlbum_ke(penyanyi, nama_penyanyi, currentInput);
                if (search_album != NOTFOUND)
                {
                    printf(" Daftar Lagu di \n");
                    printWord(penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum);
                    printf(":\n");
                    int jum_lagu;
                    jum_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Count;
                    for (i = 0; i < jum_album; i++)
                    {
                        printf("%d. ", i + 1);
                        Word name_lagu;
                        name_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[i];
                        printWord(name_lagu);
                        printf("\n");
                    }
                }
            }
        }
    }
}

// void PLAYLIST(ListDinamis L)
// {
//     printf("\n");
//     printf("Daftar playlist yang kamu miliki:\n");
//     if (ISEMPTYLD(L))
//     {
//         int idx = 0;
//         for (int i = 0; i < LENGTHLD(L); i++)
//         {
//             pritf("\t%d ", idx + 1);
//             idx++;
//             printf("\n");
//         }
//     }
//     else
//     {
//         printf("Kamu tidak memiliki playlist.\n");
//     }
// }
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
    LISTDEFAULT(PL);
    return 0;
}