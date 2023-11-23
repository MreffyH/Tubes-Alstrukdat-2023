#include "song.h"
#include <stdio.h>
// asumsi jika queue/historysong kosong pasti ada current song untu

void songNext(QueueSong *q, HistorySong *s, DetailSongQ *cs)
{
    Word none;
    none.TabWord[0] = '-';
    none.Length = 1;
    if (isEmptyQ(*q))
    {
        if ((IsKataEqual((*cs).namaPenyanyiQ, none)) && (IsKataEqual((*cs).namaAlbumQ, none)) && (IsKataEqual((*cs).namaLaguQ, none)))
        {
            printf("Tidak dapat memutar lagu\n");
        }
        else
        {
            printf("Queue kosong, memutar kembali lagu\n");
            printf("\"");
            printWord((*cs).namaLaguQ);
            printf("\"");
            printf(" oleh ");
            printf("\"");
            printWord((*cs).namaPenyanyiQ);
            printf("\"");
        }
    }
    else
    {
        DetailSongS csr;
        csr.namaLaguS = DuplicateKata(cs->namaLaguQ);
        csr.namaAlbumS = DuplicateKata(cs->namaAlbumQ);
        csr.namaPenyanyiS = DuplicateKata(cs->namaPenyanyiQ);
        if ((!IsKataEqual((*cs).namaPenyanyiQ, none)) || (!IsKataEqual((*cs).namaAlbumQ, none)) || (!IsKataEqual((*cs).namaLaguQ, none)))
        {
            Push(s, csr);
        }
        dequeue(q, cs);
        printf("Memutar lagu selanjutnya\n");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf(" oleh ");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
        printf("\"");
    }
}

void songPrevious(QueueSong *q, HistorySong *s, DetailSongQ *cs)
{
    Word none;
    none.TabWord[0] = '-';
    none.Length = 1;
    DetailSongS hs;

    if (IsEmptyHistorySong(*s))
    {
        if ((IsKataEqual((*cs).namaPenyanyiQ, none)) && (IsKataEqual((*cs).namaAlbumQ, none)) && (IsKataEqual((*cs).namaLaguQ, none)))
        {
            printf("Tidak dapat memutar lagu\n");
        }
        else
        {
            printf("Queue kosong, memutar kembali lagu\n");
            printf("\"");
            printWord((*cs).namaLaguQ);
            printf("\"");
            printf(" oleh ");
            printf("\"");
            printWord((*cs).namaPenyanyiQ);
            printf("\"");
        }
    }
    else
    {
        DetailSongQ tempSong;
        if ((!IsKataEqual((*cs).namaPenyanyiQ, none)) || (!IsKataEqual((*cs).namaAlbumQ, none)) || (!IsKataEqual((*cs).namaLaguQ, none)))
        {
            enqueue(q, *cs);
            for (int i = 0; i < lengthQ(*q) - 1; i++)
            {
                dequeue(q, &tempSong);
                enqueue(q, tempSong);
            }
        }
        Pop(s, &hs);
        cs->namaLaguQ = DuplicateKata(hs.namaLaguS);
        cs->namaAlbumQ = DuplicateKata(hs.namaAlbumS);
        cs->namaPenyanyiQ = DuplicateKata(hs.namaPenyanyiS);
        printf("Memutar lagu sebelumnya\n");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf(" oleh ");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
        printf("\"");
    }
}