#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyHistorySong (HistorySong *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah HistorySong S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri HistorySong kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHistorySong (HistorySong S)
/* Mengirim true jika HistorySong kosong: lihat definisi di atas */
{
    return (Top(S)==Nil);
}

boolean IsFullHistorySong (HistorySong S)
/* Mengirim true jika tabel penampung nilai elemen HistorySong penuh */
{
    return (Top(S)==MaxElS-1);
}

/* ************ Menambahkan sebuah elemen ke HistorySong ************ */
void Push (HistorySong * S, DetailSongS X)
/* Menambahkan X sebagai elemen HistorySong S. */
/* I.S. S mungkin kosong, tabel penampung elemen HistorySong TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen HistorySong ************ */
void Pop (HistorySong *S, DetailSongS *X)
/* Menghapus X dari HistorySong S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

void DisplayHistorySong(HistorySong S)
{
    HistorySong temp;
    DetailSongS detiltemp;
    CreateEmptyHistorySong(&temp);
    printf("BERIKUT URUTAN RIWAYAT DARI YANG TERBARU: \n");
    int i = 0;
    while(!IsEmptyHistorySong(S)){
        i++;
        printf("%d. ", i);
        Pop(&S,&detiltemp);
        printf("Nama Penyanyi: ");
        printWord(InfoSingerS(detiltemp));
        printf("\n");
        printf("Nama Album: ");
        printWord(InfoAlbumS(detiltemp));
        printf("\n");
        printf("Nama Lagu: ");
        printWord(InfoJudulS(detiltemp));
        printf("\n");
        Push(&temp, detiltemp);
    }
    while(!IsEmptyHistorySong(temp)){
        Pop(&temp,&detiltemp);
        Push(&S,detiltemp);
    }
}