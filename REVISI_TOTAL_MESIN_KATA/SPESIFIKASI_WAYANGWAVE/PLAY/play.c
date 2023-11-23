#include <stdio.h>
#include <stdlib.h>
// #include "main.c"
#include "play.h"

void PLAYSONG(ListPenyanyi penyanyi, ArrayDin array, DetailSongQ *currentSong, HistorySong *history, QueueSong *step)
{
    printf("Daftar Penyanyi : \n");
    int i;
    for (i = 0; i < Jumlahpenyanyi(penyanyi); i++)
    {
        Word name;
        name = DuplicateKata(penyanyi.penyanyi_ke[i].namaPenyanyi);
        printf("%d. ", i + 1);
        printWord(name);
        printf("\n");
    }

    printf("Masukkan Nama Penyanyi yang dipilih: \n");
    STARTINPUT();
    printf("\n");
    Word nama_penyanyi = DuplicateKata(currentInput);
    int urutan = SearchPenyanyi_ke(penyanyi, currentInput);
    if (urutan != NOTFOUND)
    {
        printf("Daftar Album oleh ");
        printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
        printf(" :\n");
        int jum_album;
        jum_album = penyanyi.penyanyi_ke[urutan].countalbum;
        for (i = 0; i < jum_album; i++)
        {
            printf("%d. ", i + 1);
            Word name_album;
            name_album = penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum;
            printWord(name_album);
            printf("\n");
        }

        printf("Masukkan Nama Album yang dipilih : : \n");
        STARTINPUT();
        int search_album = SearchAlbum_ke(penyanyi, nama_penyanyi, currentInput);
        if (search_album != NOTFOUND)
        {
            printf("Daftar Lagu Album ");
            printWord(penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum);
            printf(" oleh ");
            printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            printf(":\n");
            int jum_lagu;
            jum_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Count;
            for (i = 0; i < jum_lagu; i++)
            {
                printf("%d. ", i + 1);
                Word name_lagu;
                name_lagu = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[i];
                printWord(name_lagu);
                printf("\n");
            }
            printf("Masukkan ID Lagu yang dipilih : ");
            STARTINPUT();
            int hasil = strToInteger(currentInput);
            Word LAGU_PANGGIL;
            LAGU_PANGGIL = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[hasil - 1];
            printf("Memutar lagu |");
            printWord(LAGU_PANGGIL);
            printf("| oleh |");
            printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            printf("|.");
            DetailSongQ trashqueue;
            DetailSongS trashstack;
            address P;
            while (!isEmptyQ(*step))
            {
                dequeue(step, &trashqueue);
            }
            while (!IsEmptyHistorySong(*history))
            {
                Pop(history, &trashstack);
            }
        }
    }
}

void playPlaylist(ArrayDin array, DetailSongQ *currentSong, HistorySong *history, QueueSong *urutan)
{
    if (!IsEmptyArrayDin(array))
    {
        for (int i = 0; i < LengthArrayDin(array); i++)
        {
            printf("%d. ", i + 1);
            printWord(array.detil_playlist[i].nama_PlayList);
            printf("\n");
        }
        printf("Masukkan ID Playlist: ");
        STARTINPUT();
        int hasil = strToInteger(currentInput);
        IsiPlaylist nama_playlist = GetPlaylist(array, hasil-1);
        printf("Memutar playlist “");
        printWord(nama_playlist.nama_PlayList);
        printf("”.\n");
        DetailSongQ trashqueue;
        DetailSongS trashstack;
        address P;
        while (!isEmptyQ(*urutan))
        {
            dequeue(urutan, &trashqueue);
        }
        while (!IsEmptyHistorySong(*history))
        {
            Pop(history, &trashstack);
        }
        P = First(array.detil_playlist[hasil].IsiLagu);
        DetailSongLL timpalagu;
        int idx = 0;
        while ((idx < array.detil_playlist[hasil].countlaguLL) && (P != NilLin))
        {
            timpalagu.namaPenyanyi = InfoPenyanyi(P);
            timpalagu.namaAlbum = InfoAlbum(P);
            timpalagu.namaLagu = InfoJudul(P);
            trashqueue.namaPenyanyiQ = timpalagu.namaPenyanyi;
            trashqueue.namaAlbumQ = timpalagu.namaAlbum;
            trashqueue.namaLaguQ = timpalagu.namaLagu;
            trashstack.namaPenyanyiS = timpalagu.namaPenyanyi;
            trashstack.namaAlbumS = timpalagu.namaAlbum;
            trashstack.namaLaguS = timpalagu.namaLagu;
            enqueue(urutan, trashqueue);
            Push(history, trashstack);
            P = Next(P);
        }
        dequeue(urutan, currentSong);
    }
}
