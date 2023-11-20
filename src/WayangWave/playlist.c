#include "playlist.h"
#include "mesinkata.h"
#include <stdio.h>

void CreatePlaylist(Playlist L)
{
    printf("Masukkan nama playlist yang ingin dibuat: ");
    STARTWORD(/*parameter*/);
    if (currentWord.Length > 3)
    {
        printf("Playlist");
        printf(/*nanti bikin di adt fungsi print kata*/);
        printf("dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!");
    }
    else
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void PlaylistADD (Playlist L)
{
    
}



