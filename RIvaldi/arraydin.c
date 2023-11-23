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
    arr.detil_playlist = (IsiPlaylist*) malloc (InitialSize * sizeof(IsiPlaylist));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Konstruktor Isi Playlist
 * I.S. sembarang
 * F.S. Terbentuk IsiPlaylist kosong dengan countlaguLL sama dengan nbElmtLL(IsiLagu)
*/
void CreateIsiPlaylist(IsiPlaylist *detil_playlist) {
    ListLin IsiLagu;
    CreateEmptyListLin(&IsiLagu);
    (*detil_playlist).countlaguLL = NbElmtLL(IsiLagu);
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    free((*array).detil_playlist);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDin array) {
    return(array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayDin(ArrayDin array) {
    return(array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
IsiPlaylist GetPlaylist(ArrayDin array, IdxTypeAD i) {
    return (array.detil_playlist[i-1]);
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
void InsertAtArrayDin(ArrayDin *array, IsiPlaylist el, IdxTypeAD i) {
    // Dictionary
    
    // Algorithm
    if (GetCapacity(*array) == LengthArrayDin(*array)) {
        int newCap = GetCapacity(*array) * 2;
        IsiPlaylist *newArray = (IsiPlaylist*) malloc (newCap * sizeof(IsiPlaylist));

        for (int j = 0; j < LengthArrayDin(*array); j++) {
            newArray[j] = GetPlaylist(*array, j);
        }
        
        free((*array).detil_playlist);
        (*array).detil_playlist = newArray;
        (*array).Capacity = newCap;
    }
    else if (LengthArrayDin(*array) <= (GetCapacity(*array)/2)) {
        int newCap = ((GetCapacity(*array)*3)/4);
        IsiPlaylist *newArray = (IsiPlaylist*) malloc (newCap * sizeof(IsiPlaylist));

        for (int j = 0; j < LengthArrayDin(*array); j++) {
            newArray[j] = GetPlaylist(*array, j);
        }
        
        free((*array).detil_playlist);
        (*array).detil_playlist = newArray;
        (*array).Capacity = newCap;
    }
    for (int j = LengthArrayDin(*array); i <= j; j--) {
        (*array).detil_playlist[j] = (*array).detil_playlist[j-1]; 
    }
    (*array).detil_playlist[i] = el;
    (*array).Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastArrayDin(ArrayDin *array, IsiPlaylist el) {
    InsertAtArrayDin(array, el, (*array).Neff);
}
/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstArrayDin(ArrayDin *array, IsiPlaylist el) {
    InsertAtArrayDin(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArrayDin(ArrayDin *array, IdxTypeAD i) {
    // Dictionary

    // Algorithm
    if (LengthArrayDin(*array) <= (GetCapacity(*array)/2)) {
        int newCap = ((GetCapacity(*array)*3)/4);
        IsiPlaylist *newArray = (IsiPlaylist*) malloc (newCap * sizeof(IsiPlaylist));

        for (int j = 0; j < LengthArrayDin(*array); j++) {
            newArray[j] = GetPlaylist(*array, j);
        }
        
        free((*array).detil_playlist);
        (*array).detil_playlist = newArray;
        (*array).Capacity = newCap;
    }
    for (int j = i; j < LengthArrayDin(*array) - 1; j++) {
        (*array).detil_playlist[j] = (*array).detil_playlist[j+1];    
    }
    (*array).Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastArrayDin(ArrayDin *array) {
    // Dictionary

    // Algorithm
    DeleteAtArrayDin(array, (LengthArrayDin(*array)-1));
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirstArrayDin(ArrayDin *array) {
    DeleteAtArrayDin(array, 0);
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
    if (IsEmptyArrayDin(array)) {
        printf("[]\n");
    } else {
        printf("[");
        for (i = 0; i < array.Neff; i++) {
            printf("%d.\n{", i+1);
            printf("NAMA PLAYLIST: ");
            printWord(array.detil_playlist[i].nama_PlayList);
            printf("\nISI PLAYLIST: ");
            PrintInfoLL(array.detil_playlist[i].IsiLagu);
            printf("JUMLAH LAGU: %d", array.detil_playlist[i].countlaguLL);
            printf("}");
            if (i < array.Neff - 1) {
                printf("\n");
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
    IsiPlaylist temp;
    int length;
    int i;
    // Algorithm
    length = LengthArrayDin(*array);
    for (i = 0; i < length / 2; i++) {
        temp = (*array).detil_playlist[i];
        (*array).detil_playlist[i] = (*array).detil_playlist[length - i -1];
        (*array).detil_playlist[length - i - 1] = temp; 
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
        InsertLastArrayDin(&copy, array.detil_playlist[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxTypeAD SearchIdxPlaylist(ArrayDin array, IsiPlaylist el) {
    // Dictionary
    IdxTypeAD i = 0;
    boolean foundPlaylist = false;
    // Algorithm
    while((i < LengthArrayDin(array)) && (!foundPlaylist)){
        if((IsKataEqual(array.detil_playlist[i].nama_PlayList, el.nama_PlayList)) && (array.detil_playlist[i].countlaguLL == el.countlaguLL)){
            if(isLLsama(array.detil_playlist[i].IsiLagu, el.IsiLagu)){
                foundPlaylist = true;
            }
        }
        else{
            i++;
        }
    } /* i == Length(array) or foundPlaylist */
    if(foundPlaylist){
        return i;
    }
    else{
        return -1;
    }
}