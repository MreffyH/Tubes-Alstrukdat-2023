#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include <stdio.h>
//asumsi jika queue/historysong kosong pasti ada current song untu

void songNext(QueueSong *q, HistorySong *s, DetailSongQ * cs)
{
    if (isEmptyQ(*q))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
    }
    else
    {
        DetailSongS csr;
        csr.namaLaguS = DuplicateKata(cs->namaLaguQ);
        csr.namaAlbumS = DuplicateKata(cs->namaAlbumQ);
        csr.namaPenyanyiS = DuplicateKata(cs->namaPenyanyiQ);
        Push(s, csr);
        dequeue(q, cs);
        printf("Memutar lagu selanjutnya");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
        printf("\"");
    }
}

void songPrevious(QueueSong *q, HistorySong *s, DetailSongQ *cs)
{
    if (IsEmptyHistorySong(*s))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
        printf("\"");
    }
    else
    {
        DetailSongS csr;
        DetailSongQ tempSong;
        enqueue(q, *cs);
        for(int i = 0; i < lengthQ(*q)-1; i++){
            dequeue(q, &tempSong);
            enqueue(q, tempSong);
        }
        Pop(s, &csr);
        cs->namaLaguQ = DuplicateKata(csr.namaPenyanyiS);
        cs->namaAlbumQ = DuplicateKata(csr.namaAlbumS);
        cs->namaPenyanyiQ = DuplicateKata(csr.namaPenyanyiS);
        printf("Memutar lagu sebelumnya");
        printf("\"");
        printWord((*cs).namaLaguQ);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*cs).namaPenyanyiQ);
        printf("\"");
    }
}