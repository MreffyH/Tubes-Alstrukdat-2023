#include "../../RIvaldi/arraydin.h"
#include "../FUNGSI_LIST/ladt.h"
#include "../../../src/ADT/list/listlinier.h"
#include "../../REVISI_TOTAL_MESIN_KATA/mesinkata.h"
#include <stdio.h>

void CreatePlaylist(ArrayDin *PLY)
{
    IsiPlaylist detil_playlist;
    ListLin IsiLagu;
    CreateEmptyListLin(&IsiLagu);
    (detil_playlist).countlaguLL = NbElmtLL(IsiLagu);
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTINPUT();
    detil_playlist.nama_PlayList = currentInput;
    InsertLastArrayDin(PLY, detil_playlist);
}

void PlaylistADDSong (ArrayDin *PLY, ListPenyanyi penyanyi)
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
            // printf("Memutar lagu |");
            // printWord(LAGU_PANGGIL);
            // printf("| oleh |");
            // printWord(penyanyi.penyanyi_ke[urutan].namaPenyanyi);
            // printf("|.");

            DetailSongLL LL;

            LL.namaPenyanyi = penyanyi.penyanyi_ke[urutan].namaPenyanyi;
            LL.namaAlbum = penyanyi.penyanyi_ke[urutan].mapalbum[search_album].namaAlbum;
            LL.namaLagu = LAGU_PANGGIL;

            printf("\n");
            printf("Daftar playlist yang kamu miliki:\n");
            if (!IsEmptyArrayDin(*PLY))
            {
                for (int i = 0; i < LengthArrayDin(*PLY); i++)
                {
                    printf("%d. ", i + 1);
                    printWord((*PLY).detil_playlist[i].nama_PlayList);
                    printf("\n");
                }

                printf("Masukkan ID playlist: ");
                STARTINPUT();
                int idPlaylist = strToInteger(currentInput);

                InsVLast(&(*PLY).detil_playlist[idPlaylist].IsiLagu, LL);
                printf("Berhasil memasukkan lagu %s ke dalam playlist %s\n", LAGU_PANGGIL, (*PLY).detil_playlist[idPlaylist].nama_PlayList.TabWord);


            }
            else
            {
                printf("Kamu tidak memiliki playlist.\n");
            }

        }
    }
}

void PlaylistADDAlbum(ArrayDin *PLY, MapAlbum Album, ListPenyanyi penyanyi)
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
        
        }
    }
    printf("\n");
    printf("Daftar playlist yang kamu miliki:\n");
    if (!IsEmptyArrayDin(*PLY))
    {
        for (int i = 0; i < LengthArrayDin(*PLY); i++)
        {
            printf("%d. ", i + 1);
            printWord(PLY.detil_playlist[i].nama_PlayList);
            printf("\n");
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist.\n");
    }

}




