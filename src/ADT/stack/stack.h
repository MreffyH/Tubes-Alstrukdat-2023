/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../../../REVISI_TOTAL_MESIN_KATA/mesinkata.h"

#define Nil -1
#define MaxElS 20
/* Nil adalah stack dengan elemen kosong . */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/

typedef struct{
	Word namaPenyanyiS;
	Word namaAlbumS;
	Word namaLaguS;
} DetailSongS;

typedef struct{
	DetailSongS detil_history[MaxElS]; /* tabel penyimpan elemen */
	int TopHistory; /* alamat TOP: elemen puncak */
} HistorySong;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TopHistory
#define InfoTop(S) (S).detil_history[(S).TopHistory]
#define InfoSingerS(D) D.namaPenyanyiS
#define InfoAlbumS(D) D.namaAlbumS
#define InfoJudulS(D) D.namaLaguS


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyHistorySong(HistorySong *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah HistorySong S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri HistorySong kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHistorySong(HistorySong S);
/* Mengirim true jika HistorySong kosong: lihat definisi di atas */
boolean IsFullHistorySong(HistorySong S);
/* Mengirim true jika tabel penampung nilai elemen HistorySong penuh */

/* ************ Menambahkan sebuah elemen ke HistorySong ************ */
void Push(HistorySong *S, DetailSongS X);
/* Menambahkan X sebagai elemen HistorySong S. */
/* I.S. S mungkin kosong, tabel penampung elemen HistorySong TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen HistorySong ************ */
void Pop(HistorySong *S, DetailSongS *X);
/* Menghapus X dari HistorySong S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayHistorySong(HistorySong S);
/* Menampilkan Stack pada layar
   I.S. S sembarang, mungkin kosong
   F.S. Isi S ditampilkan ke layar */
#endif