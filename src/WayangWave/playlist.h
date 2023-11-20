#define playlist_H

#include "boolean.h"
#include "stdio.h"
#include "stdlib.h"
#include "./ADT/listlinier.h"
#include "mesinkata.h"

#define Nil NULL

typedef Word infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype info;
    address next;
} ElmtList;
typedef struct
{
    List lagu;
    address First;
} Playlist;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info_P(P) (P)->info
#define Next_P(P) (P)->next
#define First_P(L) ((L).First)

void CreateEmptyPlaylist(Playlist *L)
{
    First_P(*L) = Nil;
}

void InsertVLastPlaylist (Playlist *L, infotype X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}