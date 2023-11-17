#include "list.h"
#include <stdio.h>
#include "listadt.c"
#include "queue.c"

void playSong(List *s, List *artistChoice, List *albumChoice, List *songChoice)
{
    printf(">> PLAY SONG;\n");

    int i;
    printf("Daftar Penyanyi:\n");
    for (i = 0; i < Length(*s); i++)
    {
        printf("%d. %s\n", i + 1, currentWord);
    }
    char name;
    printf("Masukkan Nama Penyanyi yang dipilih : \n%s", name);

    if (strcmp(artistChoice, album) == 0)
    {
        printf("\nDaftar Album oleh %s:\n", artistChoice);
        for (i = 0; i < length(); i++)
        {
            printf("%d. %s\n", i + 1, album);
        }
    }
    char name2;
    printf("\nMasukkan Nama Penyanyi yang dipilih : \n%s", name2);

    if (strcmp(albumChoice, song) == 0)
    {
        printf("\nDaftar Lagu Album %s oleh %s:\n", albumChoice, artistChoice);
        for (i = 0; i < length(); i++)
        {
            printf("%d. %s\n", i + 1, ());
        }
    }
    for (i = 0; i < length(); i++)
    {
        int sum;
        printf("Masukkan ID Lagu yang dipilih : %d;", sum);
        if (sum == i)
        {
            printf("\nMemutar lagu \"%s\" oleh \"%s\".\n", songChoice, artistChoice);
        }
    }
}

void playPlaylist(Playlist playlists[], int numPlaylists, int playlistID, Queue *queue)
{
    if (playlistID >= 0 && playlistID < numPlaylists)
    {
        printf("Memutar playlist \"%s\".\n", playlists[playlistID].name);

        Playlist playlist = playlists[playlistID];

        // Reverse the songs in the playlist
        for (int i = playlist.numSongs - 1; i >= 0; i--)
        {
            enqueue(queue, playlist.songs[i]);
        }

        // Play the songs from the queue
        while (queue->front != -1)
        {
            Song currentSong = dequeue(queue);
            printf("Memutar lagu \"%s\" oleh \"%s\".\n", currentSong.name, currentSong.artist);
        }
    }
}
