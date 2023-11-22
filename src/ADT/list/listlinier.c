/* File : listlinier.C */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* DetailSongLL adalah integer */

#include "stdio.h"
#include "stdlib.h"
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(ListLin L)
/* Mengirim true jika list kosong */
{
    return (First(L) == NilLin);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListLin(ListLin *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NilLin;
}

/****************** Manajemen Memori ******************/
address Alokasi(DetailSongLL X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NilLin, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilLin */
/* Jika alokasi gagal, mengirimkan NilLin */
{
    address P = (address)malloc(1 * sizeof(ElmtList));
    if (P != NilLin)
    {
        InfoPenyanyi(P) = X.namaPenyanyi;
        InfoAlbum(P) = X.namaAlbum;
        InfoJudul(P) = X.namaLagu;
        Next(P) = NilLin;
        return P;
    }
    {
        return NilLin;
    }
}

void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(ListLin L, DetailSongLL X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLin */
{
    address p = First(L);
    boolean found = false;
    while ((!found) && (p != NilLin)){
        if ((IsKataEqual(InfoPenyanyi(p), X.namaPenyanyi)) && (IsKataEqual(InfoAlbum(p), X.namaAlbum)) && (IsKataEqual(InfoJudul(p), X.namaLagu))){
            found = true;
        }
        else{
            p = Next(p);
        }
    } /* found || p == Nil */
    if (found){
        return p;
    }
    else{
        return NilLin;
    }
}

/****************** PRIMITIF BERDASARKAN nilai ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(ListLin *L, DetailSongLL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if (P != NilLin)
    {
        InsertFirst(L, P);
    }
}

void InsVLast(ListLin *L, DetailSongLL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    if (P != NilLin)
    {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(ListLin *L, DetailSongLL *X)
/* I.S. ListLin L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
    address P = First(*L);
    (*X).namaPenyanyi = DuplicateKata(InfoPenyanyi(P));
    (*X).namaAlbum = DuplicateKata(InfoAlbum(P));
    (*X).namaLagu = DuplicateKata(InfoJudul(P));
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast(ListLin *L, DetailSongLL *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    address Prec = NilLin;

    while (Next(P) != NilLin)
    {
        Prec = P;
        P = Next(P);
    }
    (*X).namaPenyanyi = DuplicateKata(InfoPenyanyi(P));
    (*X).namaAlbum = DuplicateKata(InfoAlbum(P));
    (*X).namaLagu = DuplicateKata(InfoJudul(P));
    if (Prec != NilLin)
    {
        Next(Prec) = NilLin;
    }
    else
    {
        First(*L) = NilLin;
    }
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(ListLin *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(ListLin *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(ListLin *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;

    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        Last = First(*L);
        while (Next(Last) != NilLin)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(ListLin *L, address *P)
/* I.S. ListLin tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NilLin;
}

void DelP(ListLin *L, DetailSongLL X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListLin mungkin menjadi kosong karena penghapusan */
{
    if(!IsEmpty(*L)){
        address P;
        address Prec = NilLin;
        boolean found = false;
        if ((IsKataEqual(InfoPenyanyi(First(*L)), X.namaPenyanyi)) && (IsKataEqual(InfoAlbum(First(*L)), X.namaAlbum)) && (IsKataEqual(InfoJudul(First(*L)), X.namaLagu))){ /* Ditemukan di elemen pertama */
            DelFirst(L, &P);
            Dealokasi(&P);
        }
        else{
            P = First(*L);
            while ((P != NilLin) && (!found)){
                if ((IsKataEqual(InfoPenyanyi(P), X.namaPenyanyi)) && (IsKataEqual(InfoAlbum(P), X.namaAlbum)) && (IsKataEqual(InfoJudul(P), X.namaLagu))){
                    found = true;
                }
                else{
                    Prec = P;
                    P = Next(P);
                }
            }
            if (found){
                DelAfter(L, &P, Prec);
                Dealokasi(&P);
            }
        }
    }
}

void DelLast(ListLin *L, address *P)
/* I.S. ListLin tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Last = First(*L);
    address PrecLast = NilLin;

    while (Next(Last) != NilLin)
    {
        PrecLast = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (PrecLast == NilLin)
    {
        First(*L) = NilLin;
    }
    else
    {
        Next(PrecLast) = NilLin;
    }
}

void DelAfter(ListLin *L, address *Pdel, address Prec)
/* I.S. ListLin tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = NilLin;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(ListLin L)
/* I.S. ListLin mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    address P = First(L);
    while (P != NilLin){
        printWord(InfoPenyanyi(P));
        printf(";");
        printWord(InfoAlbum(P));
        printf(";");
        printWord(InfoJudul(P));
        P = Next(P);
        if (P != NilLin){
            printf("\n");
        }
    }
    printf("]\n");
}
int NbElmt(ListLin L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    address P;

    if (!IsEmpty(L))
    {
        P = First(L);
        while (P != NilLin)
        {
            cnt++;
            P = Next(P);
        }
    }

    return cnt;
}

/****************** PROSES TERHADAP LIST ******************/
void InversList(ListLin *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P;
    address Prec = NilLin;
    address Succ;

    if (!IsEmpty(*L))
    {
        P = First(*L);
        while (P != NilLin)
        {
            Succ = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = Succ;
        }
        First(*L) = Prec;
    }
}

void Konkat1(ListLin *L1, ListLin *L2, ListLin *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last1;

    CreateEmptyListLin(L3);
    if (IsEmpty(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != NilLin)
        {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }

    First(*L1) = NilLin;
    First(*L2) = NilLin;
}