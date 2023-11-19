#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"
#include "mesinkalimat.h"
#include "mesinkarakter.h"

#define MAX_LENGTH 50 // Asumsikan panjang maksimum dari nama

typedef struct
{
    int id;
    char nama1[MAX_LENGTH];
    char nama2[MAX_LENGTH];
} Data;

typedef struct
{
    Data *data;
    int size;
} List;

int arrayfirst()
{
    FILE *f = fopen("../../save/config.txt", "r");

    if (f == NULL)
    {
        printf("file tidak ditemukan");
        return 0;
        fclose(f);
    }
    else
    {
        int i;
        char *temp;
        fgets(temp, sizeof(temp), f);
        i = atoi(temp);
        fclose(f);
        return i;
    }
}

void Fullarray(List *L)
// menjadikan semua data file txt menjadi list
{
    (*L).size = 0;
    FILE *f = fopen("../../save/config.txt", "r");

    if (f == NULL)
    {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    // Tentukan ukuran awal untuk array
    int capacity = 10;

    (*L).data = (Data *)malloc(capacity * sizeof(Data));

    // Baca data dari file
    while (fscanf(f, " %s %s", (*L).data[(*L).size].nama1, (*L).data[(*L).size].nama2) == 2)
    {
        // Tambahkan satu ke ukuran
        (*L).size++;

        // Periksa apakah array penuh, dan perbesar jika perlu
        if ((*L).size == capacity)
        {
            capacity *= 2;
            (*L).data = (Data *)realloc((*L).data, capacity * sizeof(Data));
        }
    }
    fclose(f);
}

int customStrCmp(const char *str1, const char *str2)
// mengcompare string
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int namatarget(List *L, const char *nama)
{
    Fullarray(L);

    // Iterasi melalui list dan cari data yang sesuai dengan nama
    for (int i = 0; i < (*L).size; i++)
    {
        if (customStrCmp((*L).data[i].nama1, nama) || customStrCmp((*L).data[i].nama2, nama))
        {
            // Mengonversi id menjadi angka dan mengembalikan nilainya
            return (*L).data[i].id;
        }
    }

    // Mengembalikan -1 jika tidak ditemukan
    return -1;
}

void ListAlbumPenyanyi(List *L, const char *penyanyi)
{
    Fullarray(L);

    printf("Daftar album untuk %s:\n", penyanyi);

    int i = 0;

    // Iterasi melalui list dan cari data yang sesuai dengan penyanyi
    while (i < (*L).size && customStrCmp((*L).data[i].nama1, penyanyi) == 0)
    {
        printf("%d. %s\n", i + 1, (*L).data[i].nama2);

        // Jumlah lagu dalam album
        int jumlahLagu = atoi((*L).data[i + 1].id);

        // Melompati baris album
        i += 2;

        // Melompati baris lagu
        for (int j = 0; j < jumlahLagu; j++)
        {
            i++;
        }
    }

    // Jika tidak ada album, cetak pesan
    if (i == 0)
    {
        printf("Tidak ada album yang ditemukan untuk %s.\n", penyanyi);
    }
}

void lagudanalbum(List *L, const char *penyanyi, const char *album)
{
    Fullarray(L);

    printf("Daftar lagu di %s:\n", album);

    int i = 0;

    // Iterasi melalui list dan cari data yang sesuai dengan penyanyi dan album
    while (i < (*L).size && (customStrCmp((*L).data[i].nama1, penyanyi) != 0 || compareStrings((*L).data[i].nama2, album) != 0))
    {
        i++;
    }

    // Cek apakah album ditemukan
    if (i < (*L).size)
    {
        // Jumlah lagu dalam album
        int jumlahLagu = atoi((*L).data[i + 1].id);

        // Melompati baris album
        i += 2;

        // Cetak nama lagu
        for (int j = 0; j < jumlahLagu; j++)
        {
            printf("   %s\n", (*L).data[i].nama1);
            i++;
        }
    }
    else
    {
        printf("Album %s tidak ditemukan untuk %s.\n", album, penyanyi);
    }
}
// memisahkan semua daftar album penyanyi lagu
void listdefault(List *s)
{
    Fullarray(s);
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < (*s).size; i++)
    {
        printf("%s\n", (*s).data[i].nama1);
    }
}

void ListAlbumPenyanyi2(List *L, const char *penyanyi)
{
    Fullarray(L);

    printf("Daftar Album oleh %s :\n", penyanyi);

    int i = 0;

    // Iterasi melalui list dan cari data yang sesuai dengan penyanyi
    while (i < (*L).size && customStrCmp((*L).data[i].nama1, penyanyi) != 0)
    {
        i++;
    }

    // Cek apakah penyanyi ditemukan
    if (i < (*L).size)
    {
        // Jumlah album penyanyi
        int jumlahAlbum = atoi((*L).data[i].id);

        // Melompati baris penyanyi
        i++;

        // Cetak nama album
        for (int j = 0; j < jumlahAlbum; j++)
        {
            printf("%s\n", (*L).data[i + j].nama2);
        }
    }
    else
    {
        printf("Penyanyi %s tidak ditemukan.\n", penyanyi);
    }
}

void ListLaguDariAlbumPenyanyi(List *L, const char *penyanyi, const char *album)
{
    Fullarray(L);

    printf("Daftar Lagu Album %s oleh %s :\n", album, penyanyi);

    int i = 0;

    // Iterasi melalui list dan cari data yang sesuai dengan penyanyi dan album
    while (i < (*L).size && (((*L).data[i].nama1, penyanyi) != 0 || strcmp((*L).data[i].nama2, album) != 0))
    {
        i++;
    }

    // Cek apakah album ditemukan
    if (i < (*L).size)
    {
        // Jumlah lagu dalam album
        int jumlahLagu = atoi((*L).data[i].id);

        // Melompati baris album
        i++;

        // Cetak nama lagu
        for (int j = 0; j < jumlahLagu; j++)
        {
            printf("%s\n", (*L).data[i + j].nama1);
        }
    }
    else
    {
        printf("Album %s tidak ditemukan untuk %s.\n", album, penyanyi);
    }
}