#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "start.h"
#include "arraydin.c"

void listDefault(List *s, char name_penyanyi, char name_album, char name_lagu)
{
    Fullarray(s);
    printf(">> LIST DEFAULT;\n");
    int i;
    char *b = arrayfirst();
    MakeList(s);
    listdefault(s);

    char choice;
    if (choice == 'Y' || choice == 'y')
    {
        if (Search(s, name_penyanyi))
        {
            printf("Pilih penyanyi untuk melihat album mereka: \n%s", name_penyanyi);
            printf("Daftar Album oleh %s:\n", name_penyanyi);
            ListAlbumPenyanyi(s, name_penyanyi);
            if (Search(*s, name_album))
            {
                printf("Masukkan Nama Album yang dipilih : \n%s\n", name_album);
                char choice2;
                if (choice2 == 'Y' || choice2 == 'y')
                {
                    printf("Ingin melihat lagu yang ada?(Y/N): %s;", choice2);
                    printf("Pilih album untuk melihat lagu yang ada di album :\n %s;\n", name_album);
                    lagudanalbum(s, name_album, name_penyanyi);
                }
            }
            else
            {
                printf("Tidak ada nama album yang sesuai");
            }
        }
    }
}

void playlist(List *s)
{
    printf(">> LIST PLAYLIST;\n");
    int i;
    if (s == NULL)
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