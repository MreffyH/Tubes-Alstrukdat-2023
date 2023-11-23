#include "../../RIvaldi/arraydin.h"
#include "../../REVISI_TOTAL_MESIN_KATA/mesinkata.h"
#include <stdio.h>

void CreatePlaylist(ArrayDin *PLY)
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTINPUT();
    InsertLastArrayDin(PLY, currentInput);

}

void PlaylistADD (Playlist L)
{
    
}

void PlaylistRemove(ArrayDin *PLY, int idPlaylist, int nLagu)

{
    if (idPlaylist > (*AP).Neff || idPlaylist <= 0)
    {
        printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPlaylist);
    }
    if (idPlaylist < (*PLY).Neff || idPlaylist > 0)
    {
        Word namaPlaylist = (*PLY).Nama[idPlaylist-1];
        AnimasiPlaylistRemove();
        DelP(namaPlaylist, &(*PLY).A[idPlaylist-1], nLagu-1);
    }
}




