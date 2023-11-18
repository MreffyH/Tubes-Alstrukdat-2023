#ifndef map_H
#define map_H
// #include "../ADT/boolean.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "set.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define MaxElMap 10

// typedef int bool;
typedef Sentence keytype;
typedef Sentence valuetype;
typedef int addr;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotypeMap;

typedef struct
{
	infotypeMap Elements[MaxElMap];
	addr Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElMap */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */

void InsertMap(Map *M, keytype k, Sentence lagu);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif