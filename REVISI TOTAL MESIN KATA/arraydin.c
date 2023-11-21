#include<stdio.h>
#include<stdlib.h>
#include "arraydin.h"
#include<stdbool.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    // Local Dictoinary
    ArrayDin arr;
    // Algorithm
    arr.A = (ElType*) malloc(InitialSize * sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    return(array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    return(array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i) {
    return (array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    return(array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    // Dictionary
    
    // Algorithm
    if (GetCapacity(*array) == Length(*array)) {
        int newCap = GetCapacity(*array) * 2;
        ElType *newArray = (ElType *) malloc (newCap * sizeof(ElType));

        for (int j = 0; j < Length(*array); j++) {
            newArray[j] = Get(*array, j);
        }
        
        free((*array).A);
        (*array).A = newArray;
        (*array).Capacity = newCap;
    }
    
    for (int j = Length(*array); i <= j; j--) {
        (*array).A[j] = (*array).A[j-1]; 
    }
    (*array).A[i] = el;
    (*array).Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el) {
    InsertAt(array, el, (*array).Neff);
}
/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el) {
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i) {
    // Dictionary

    // Algorithm
    for (int j = i; j < Length(*array) - 1; j++) {
        (*array).A[j] = (*array).A[j+1];    
    }
    (*array).Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array) {
    // Dictionary

    // Algorithm
    int j = Length(*array);
	(*array).A[j] = '\0';
	(*array).Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array) {
    // Dictionary
    int i;
    // Algorithm
    if (IsEmpty(array)) {
        printf("[]\n");
    } else {
        printf("[");
        for (i = 0; i < array.Neff; i++) {
            printf("%d", array.A[i]);
            if (i < array.Neff - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array) {
    // Dictionary 
    ElType temp;
    int length;
    int i;
    // Algorithm
    length = Length(*array);
    for (i = 0; i < length / 2; i++) {
        temp = array -> A[i];
        array->A[i] = array->A[length - i -1];
        array->A[length - i - 1] = temp; 
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array) {
    // Dictionary
    ArrayDin copy;
    int i;
    // Algorithm
    copy = MakeArrayDin();
    for (i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el) {
    // Dictionary
    int i;
    // Algorithm
    for (i = 0; i < array.Neff; i++) {
        if (array.A[i] == el) {
            return i;
        }
    }
    return -1;
}