#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "main.c"
#include "listmapset.h"
#include "mesinkata.h"

void listdefault(ListPenyanyi penyanyi)
{
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
    if (IsKataEqual(currentInput, "Y"))
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
            if (IsKataEqual(currentInput, "Y"))
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

void playlist(List *s)
{
    int i;
    if (is)
    {
        printf("Daftar playlist yang kamu miliki:\n");
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    else
    {
        printf("Daftar playlist yang kamu miliki:\n");
        for (i = 0; i < Playlist.A; i++)
        {
            printf("%d. %s\n", i + 1, Playlist.A[i]);
        }
    }
}