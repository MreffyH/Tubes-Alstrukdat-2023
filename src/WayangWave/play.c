#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "start.h"
#include "load.h"
#include "arraydin.c"
#include "listadt.c"

void playsong(List *L, const char *penyanyi, const char *album, const char *lagu, int idLagu)
{
    Fullarray(L);
    // Gunakan fungsi playsong untuk memutar lagu dari playlist
    ListLaguDariAlbumPenyanyi(L, penyanyi, album, lagu, idLagu);
    printf("Memutar playlist \"%s\".\n", lagu);

    int i = 0;

    // Iterasi melalui list dan cari data yang sesuai dengan penyanyi, album, dan ID lagu
    while (i < (*L).size && (strcmp((*L).data[i].nama1, penyanyi) != 0 || strcmp((*L).data[i].nama2, album) != 0 || atoi((*L).data[i].id) != idLagu))
    {
        i++;
    }

    // Cek apakah lagu ditemukan
    if (i < (*L).size)
    {
        printf("Memutar lagu \"%s\" oleh \"%s\".\n", (*L).data[i].nama1, penyanyi);
    }
    else
    {
        printf("Lagu dengan ID %d tidak ditemukan pada album %s oleh %s.\n", idLagu, album, penyanyi);
    }
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