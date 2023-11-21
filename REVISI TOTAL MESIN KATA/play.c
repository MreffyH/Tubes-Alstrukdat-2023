#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "main.c"
#include "listmapset.h"
#include "mesinkata.h"
#include "listdinamis.h"

void PLAYSONG(ListPenyanyi penyanyi)
{
    printf("Daftar Penyanyi : \n");
    int i;
    for (i = 0; i < (penyanyi).countpenyanyi; i++)
    {
        Word nama_penyanyi = DuplicateKata(currentInput);
        int urutan = SearchPenyanyi_ke(penyanyi, currentInput);
        printf("%d. ", i + 1);
        printWord(nama_penyanyi);
        printf("\n");
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTINPUT();
    printf(";\n");
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
    printf("Masukkan Nama Album yang dipilih : ");
    STARTINPUT();
    print("\n");
    int search_album = SearchAlbum_ke(penyanyi, nama_penyanyi, currentInput);
    if (search_album != NOTFOUND)
    {
        printf(" Daftar Lagu Album \n");
        printWord(penyanyi.penyanyi_ke[urutan].listalbum[search_album].namaAlbum);
        printf(" oleh ");
        printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
        printf(" :\n");
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
    printf("Masukkan ID Lagu yang dipilih : ");
    STARTINPUT();
    int hasil = strToInteger(currentInput);
    Word LAGU_PANGGIL;
    LAGU_PANGGIL = penyanyi.penyanyi_ke[urutan].listalbum[search_album].Elements[hasil - 1];
    printf("Memutar lagu  ");
    printWord(LAGU_PANGGIL);
    printf(" oleh ");
    printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi)
}

void playPlaylist(List *L, const char *penyanyi, const char *album, const char *lagu, int idLagu)
{
    Fullarray(L);
    playsong(L, penyanyi, album, lagu, idLagu);

    int i = 0;
    // Iterasi melalui list dan cari lagu berdasarkan penyanyi, album, dan ID lagu
    while (i < (*L).size && (customStrCmp((*L).data[i].nama1, penyanyi) != 0 || customStrCmp((*L).data[i].nama2, album) != 0 || atoi((*L).data[i].id) != idLagu))
    {
        i++;
    }

    // Cek apakah lagu ditemukan
    if (i < (*L).size)
    {
        // Mengisi ulang queue dengan lagu dari playlist
        // (Misalnya, menambahkan semua lagu dalam playlist ke dalam queue dengan urutan yang di-reverse)
        int playlistSize = getPlaylistSize(&myPlaylist); // Ganti dengan fungsi yang sesuai di program Anda
        for (int j = 0; j < playlistSize; j++)
        {
            // enqueue(&myQueue, getPlaylistSong(&myPlaylist, j)); // Ganti dengan fungsi yang sesuai di program Anda
        }

        // Output untuk menunjukkan bahwa playlist dimainkan
        printf("Memutar playlist \"%s\".\n", lagu);
    }
    else
    {
        printf("Playlist dengan ID %d tidak ditemukan.\n", idlagu);
    }

    // Pastikan untuk membebaskan memori jika diperlukan
    // freePlaylist(&myPlaylist); // Ganti dengan fungsi yang sesuai di program Anda
}