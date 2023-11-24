#include <stdio.h>
#include <stdlib.h>
#include "status.h"

// gcc -o status status.c ../../listmapset.c

void Status(ArrayDin  AD, QueueSong  QS, DetailSongQ currentsong)
{   
    if(!IsEmptyArrayDin(AD))
    {
        printf("Current Playlist: ");
        printWord(AD.detil_playlist->nama_PlayList);
        printf("\n");
    }

    printf("\nNow Playing:\n");
    if (isEmptyQ(QS))
    {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    else
    {
        printWord(currentsong.namaPenyanyiQ);
        printf(" - ");
        printWord(currentsong.namaLaguQ);
        printf(" - ");
        printWord(currentsong.namaAlbumQ);
        printf("\n");
    }
    
    printf("\nQueue:\n");
    if ((QS).idxHead == IDX_UNDEF || (QS).idxTail == IDX_UNDEF)
    {
        printf("Your queue is empty.\n");
    }
    else
    {
        for (int i = (QS).idxHead; i <= (QS).idxTail; i++)
        {
            printf("%d. ", i+1);
            printWord(QS.detil_queue[i].namaPenyanyiQ);
            printf(" - ");
            printWord(QS.detil_queue[i].namaLaguQ);
            printf(" - ");
            printWord(QS.detil_queue[i].namaAlbumQ);
            printf("\n");
        }
    }
}

    // if ((*AD).status == 0 )
    // {   
    //     if (((QS).idxHead != IDX_UNDEF || (QS).idxTail != IDX_UNDEF))
    //     {   
    //         if ((AD).statusPL == 1)
    //         {
    //             printf("\nCurrent Playlist: ");
    //             printWord(AD.detil_playlist->nama_PlayList);
    //         }
            
    //         printf("\nNow Playing:\n");
    //         printf("No songs have been played yet. Please search for a song to begin playback.\n");

    //         printf("\nQueue:\n");
    //         for (int i = (QS).idxHead; i <= (QS).idxTail; i++)
    //         {
    //             printf("%d. ", i+1);
    //             printWord(QS.detil_queue[i].namaPenyanyiQ);
    //             printf(" - ");
    //             printWord(QS.detil_queue[i].namaLaguQ);
    //             printf(" - ");
    //             printWord(QS.detil_queue[i].namaAlbumQ);
    //             printf("\n");
    //         }
    //     }

    //     else if (((QS).idxHead == IDX_UNDEF || (QS).idxTail == IDX_UNDEF))
    //     {
    //         printf("\nNow Playing:\n");
    //         printf("No songs have been played yet. Please search for a song to begin playback.\n");

    //         printf("\nQueue:\n");
    //         printf("Your queue is empty.\n");
    //     }

    // }
    
    // else if ((*AD).status == 1)
    // {   
    //     if ((QS).idxHead == IDX_UNDEF || (QS).idxTail == IDX_UNDEF)
    //     {
    //         printf("\nNow Playing:\n");
    //         printWord(currentsong.namaPenyanyiQ);
    //         printf(" - ");
    //         printWord(currentsong.namaLaguQ);
    //         printf(" - ");
    //         printWord(currentsong.namaAlbumQ);
    //         printf("\n");

    //         printf("\nQueue:\n");
    //         printf("Your queue is empty.\n");
    //     }

    //     else if ((*QS).idxHead != IDX_UNDEF || (*QS).idxTail != IDX_UNDEF)
    //     {   
    //         if ((*AD).statusPL == 1)
    //         {
    //             printf("\nCurrent Playlist: ");
    //             printWord(AD.detil_playlist->nama_PlayList);
    //         }

    //         printf("\nNow Playing:\n");
    //         printWord(currentsong.namaPenyanyiQ);
    //         printf(" - ");
    //         printWord(currentsong.namaLaguQ);
    //         printf(" - ");
    //         printWord(currentsong.namaAlbumQ);
    //         printf("\n");

    //         printf("\nQueue:\n", );
    //         for (int i = (QS).idxHead; i <= (QS).idxTail; i++)
    //         {
    //             printf("%d. ", i+1);
    //             printWord(QS.detil_queue[i].namaPenyanyiQ);
    //             printf(" - ");
    //             printWord(QS.detil_queue[i].namaLaguQ);
    //             printf(" - ");
    //             printWord(QS.detil_queue[i].namaAlbumQ);
    //             printf("\n");
    //         }
    //     }

    // if ((*HS).IDXTOP != IDX_UNDEF)
    // {
    //     printf("\nHistory:\n", );
    //     for (int i = 0; i <= (*HS).IDXTOP; i++)
    //     {
    //         printf("%s%d. %s - %s - %s\n" i+1, (*HS).NamaPenyanyi[i].TabLine, (*HS).JudulLagu[i].TabLine, (*HS).NamaAlbum[i].TabLine);
    //     }
    // }
    
// }