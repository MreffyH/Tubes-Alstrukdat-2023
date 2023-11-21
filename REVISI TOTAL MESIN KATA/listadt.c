#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "main.c"
#include "listmapset.h"
#include "mesinkata.h"
#include "listdinamis.h"

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
                name_album = penyanyi.penyanyi_ke[urutan].listalbum[i].namaAlbum;
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
                    printWord(penyanyi.penyanyi_ke[urutan].listalbum[search_album].namaAlbum);
                    printf(":\n");
                    int jum_lagu;
                    jum_lagu = penyanyi.penyanyi_ke[urutan].listalbum[search_album].setlagu.countSet;
                    for (i = 0; i < jum_album; i++)
                    {
                        printf("%d. ", i + 1);
                        Word name_lagu;
                        name_lagu = penyanyi.penyanyi_ke[urutan].listalbum[search_album].Elements[i];
                        printWord(name_lagu);
                        printf("\n");
                    }
                }
            }
        }
    }
}

void PLAYLIST(ListDinamis L)
{
    printf("\n");
    printf("Daftar playlist yang kamu miliki:\n");
    if (ISEMPTYLD(L))
    {
        int idx = 0;
        for (int i = 0; i < LENGTHLD(L); i++)
        {
            pritf("\t%d ", idx + 1);
            idx++;
            printf("\n");
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist.\n");
    }
}