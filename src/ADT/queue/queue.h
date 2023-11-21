/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../../../REVISI_TOTAL_MESIN_KATA/mesinkata.h"

#define IDX_UNDEF -1
#define MaxElQ 20

/* Definisi elemen dan address */
typedef struct{
	Word namaPenyanyiQ;
	Word namaAlbumQ;
	Word namaLaguQ;
} DetailSongQ;

typedef struct{
	DetailSongQ detil_queue[MaxElQ];
	int idxHead;
	int idxTail;
} QueueSong;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).detil_queue[(q).idxHead]
#define     TAIL(q) (q).detil_queue[(q).idxTail]
#define InfoSingerQ(D) D.namaPenyanyiQ
#define InfoAlbumQ(D) D.namaAlbumQ
#define InfoJudulQ(D) D.namaLaguQ

/* *** Kreator *** */
void CreateEmptyQueue(QueueSong *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyQ(QueueSong q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQ(QueueSong q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQ(QueueSong q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(QueueSong *q, DetailSongQ val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(QueueSong *q, DetailSongQ *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(QueueSong q);
/* Menampilkan queue pada layar
   I.S. Q sembarang, mungkin kosong
   F.S. Isi Q ditampilkan ke layar */

boolean IsMemberQ (QueueSong q, DetailSongQ v);
/* Mengembalikan nilai true apabila elemen v ada pada Queue */

#endif
