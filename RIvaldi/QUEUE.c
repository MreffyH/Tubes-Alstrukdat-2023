#include "../src/ADT/list/list.h"
#include "../REVISI_TOTAL_MESIN_KATA/listmapset.h"
#include "../REVISI_TOTAL_MESIN_KATA/mesinkata.h"
#include "../REVISI_TOTAL_MESIN_KATA/START/start.h"
#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void QUEUESONG(ListPenyanyi penyanyi, QueueSong *lagu)
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

            DetailSongQ laguqueue;
            laguqueue.namaPenyanyiQ = penyanyi.penyanyi_ke[urutan].namaPenyanyi;
            laguqueue.namaAlbumQ = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum;
            laguqueue.namaLaguQ = GetLagu(penyanyi, laguqueue.namaPenyanyiQ, laguqueue.namaAlbumQ, hasil);
            Word LAGU_PANGGIL;
            LAGU_PANGGIL = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].setlagu.Elements[hasil - 1];
            printf("Berhasil menambahkan lagu  ");
            printWord(LAGU_PANGGIL);
            printf(" oleh ");
            printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            printf("ke queue.\n");
            enqueue(lagu, laguqueue);
        }
    }
}
void QUEUEPLAYLIST(QueueSong *laguplaylist, ArrayDin array)
{
    if (!IsEmptyArrayDin(array))
    {

        printf("Masukkan ID Playlist: ");
        STARTINPUT();
        int hasil = strToInteger(currentInput);
        IsiPlaylist nama_playlist = GetPlaylist(array, hasil);
        printf("Berhasil menambahkan playlist “ ");
        printWord(nama_playlist.nama_PlayList);
        printf("” ke queue.\n");
        address P = First(nama_playlist.IsiLagu);
        DetailSongQ laguqueue;
        while (P != NilLin)
        {
            laguqueue.namaPenyanyiQ = InfoPenyanyi(P);
            laguqueue.namaAlbumQ = InfoAlbum(P);
            laguqueue.namaLaguQ = InfoJudul(P);
            enqueue(laguplaylist, laguqueue);
            P = Next(P);
        }
    }
}

void QUEUESWAP(QueueSong *laguplaylist)
{
    while
}

void QUEUEREMOVE()
{
}

void QUEUECLEAR(QueueSong *urutan)
{
    DetailSongQ trashqueue;
    while (!isEmptyQ(*urutan))
    {
        dequeue(urutan, &trashqueue);
    }
}