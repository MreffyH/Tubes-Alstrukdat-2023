#ifndef POINT
#define POINT

#include <stdio.h>
#include "boolean.h"

typedef struct {
    int x;
    int y;
} Point;

Point createPoint(int x, int y);
/* Membuat titik dengan absis x dan ordinat y */

boolean isPointEqual(Point A, Point B);
/* Mengembalikan nilai true jika titik A sama dengan titik B */

void cetakPoint(Point P);
/* Mencetak titik P
   I.S. Titik P terdefinisi
   F.S. Titik P dicetak ke layar dalam bentuk <x,y> */

void setPointNull(Point* P);
/* Mengubah titik P menjadi bernilai NULL 
   I.S. sembarang
   F.S. Absis dan Ordinat P bernilai NULL */

#endif