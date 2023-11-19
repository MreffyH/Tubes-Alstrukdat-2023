#include <stdio.h>
#include "listadt.c"
#include "arraydin.c"
#include "queue.h"

void QUEUESONG(List *L, Queue *M, const char *penyanyi, const char *album, int idx)
{
    printf(">> QUEUE SONG");
    int i;
    listdefault(L);
    ListAlbumPenyanyi(L, *penyanyi);
    lagudanalbum(L, penyanyi, album);

    printf("Masukkan ID Lagu yang dipilih: %d;", idx);
    ElTypeQ lagu = {penyanyi, album, idx};
    enqueue(M, lagu);

    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", getSongName(M), getArtistName(M));
}
void QUEUEPLAYLIST(List *L, Queue *M, const char *penyanyi, const char *album, const char lagu, int idx)
{
    printf(">> QUEUE PLAYLIST\n");
    QUEUESONG(L, M, penyanyi, album, idx);
    int idx = findPlaylistIndex(L, idPlaylist);

    if (idx != -1)
    {
        // Tampilkan lagu dalam playlist yang dipilih
        printf("Daftar Lagu dalam Playlist %d:\n", idPlaylist);
        playPlaylist(L, penyanyi, album, lagu, idx);

        // Masukkan lagu dari playlist ke dalam queue
        *M = getPlaylistSongs(L, idx);
        for (int i = 0; i < songs->size; i++)
        {
            ElTypeQ lagu = {songs->elements[i].namaLagu, songs->elements[i].penyanyi, songs->elements[i].album};
            enqueue(M, lagu);
        }

        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", songs->playlistName);
    }
    else
    {
        printf("Playlist dengan ID %d tidak ditemukan.\n", idPlaylist);
    }
}

void QUEUESWAP()
{
}

void QUEUEREMOVE()
{
}

void QUEUECLEAR()
{
}