#include "list.h"
#include <stdio.h>
// list default
#include "start.h"

void listdefault(List *s)
{
    printf(">> LIST DEFAULT;\n");
    int i;
    printf("Daftar Penyanyi:\n");
    for (i = 0; i < Length(*s); i++)
    {
        printf("%d. %s\n", i + 1, currentWord);
    }

    char choice;
    if (choice == 'Y' || choice == 'y')
    {
        char name;
        printf("Pilih penyanyi untuk melihat album mereka: \n%s", name);
        printf("Daftar Album oleh %s:\n", currentWord);
        for (i = 0; i < length(); i++)
        {
            printf("%d. %s\n", i + 1, map_H);
        }
        printf("Masukkan Nama Album yang dipilih : \n%s", currentWord);

        char choice2;
        if (choice2 == 'Y' || choice2 == 'y')
        {
            printf("Ingin melihat lagu yang ada?(Y/N): Y;");
            printf("Pilih album untuk melihat lagu yang ada di album :\n %s;", currentWord);
            printf("Daftar Lagu di %s:\n", currentWord);
            for (i = 0; i < album.count; i++)
            {
                printf("%d. %s\n", i + 1, set_H);
            }
        }
    }
}

void playlist(List *s)
{
    printf(">> LIST PLAYLIST;\n");
    int i;
    if (playlist(*s) == NULL)
    {
        printf("Daftar playlist yang kamu miliki:\n");
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    else
    {
        for (i = 0; i < length(); i++)
        {
            printf("Kamu tidak memiliki playlist.\n");
            printf("%d. %s\n", i + 1, playlist(s));
        }
    }
}