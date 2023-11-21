#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateEmptyQueue(QueueSong *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(QueueSong q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(QueueSong q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD*/
{
    return (length(q) == MaxElQ);
}


int length(QueueSong q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(QueueSong *q, DetailSongQ val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur". */
{
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } 
    else {
        IDX_TAIL(*q) = IDX_TAIL(*q) + 1;
    }
    TAIL(*q) = val;
}

void dequeue(QueueSong *q, DetailSongQ *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    (*val) = HEAD(*q);
    if (length(*q) == 1) {
        CreateEmptyQueue(q);
    } else {
        for (int i = 1; i < length(*q); i++){
            (*q).detil_queue[i-1] = (*q).detil_queue[i];
        }
        IDX_TAIL(*q)--;
    }
}

/* *** Display Queue *** */
void displayQueue(QueueSong q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    if (!isEmpty(q)) {
        DetailSongQ temp;
        for (int i = 0; i < length(q); i++) {
            dequeue(&q, &temp);
            printf("%d. ", i+1);
            printf("Nama Penyanyi: ");
            printWord(InfoSingerQ(temp));
            printf("\n");
            printf("Nama Album: ");
            printWord(InfoAlbumQ(temp));
            printf("\n");
            printf("Nama Lagu: ");
            printWord(InfoJudulQ(temp));
            printf("\n");
            enqueue(&q, temp);
        }
    } else {
        printf("Queue Kosong \n");
    }
}

boolean IsMemberQ (QueueSong q, DetailSongQ v)
/* Mengembalikan nilai true apabila elemen v ada pada Queue */
{
    if (!isEmpty(q)) {
        DetailSongQ temp;
        for (int i = 0; i < length(q); i++) {
            dequeue(&q, &temp);
            if ((IsKataEqual(temp.namaPenyanyiQ, v.namaPenyanyiQ)) && (IsKataEqual(temp.namaAlbumQ, v.namaAlbumQ)) && (IsKataEqual(temp.namaLaguQ, v.namaLaguQ))) return true;
            enqueue(&q, temp);
        }
    }
    return false;
}