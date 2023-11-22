#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    printf("MILESTONE1\n");
    ListLin playlist1, playlist2;
    CreateEmptyListLin(&playlist1);
    CreateEmptyListLin(&playlist2);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("CreateEmptyListLin, PrintInfoLL AMANNN\n\n");
    DetailSongLL X, Y, Z;
    X.namaPenyanyi.TabWord[0] = 'J';
    X.namaPenyanyi.TabWord[1] = 'K';
    X.namaPenyanyi.TabWord[2] = 'T';
    X.namaPenyanyi.TabWord[3] = '4';
    X.namaPenyanyi.TabWord[4] = '8';
    X.namaPenyanyi.Length = 5;
    X.namaAlbum.TabWord[0] = 'S';
    X.namaAlbum.TabWord[1] = 'n';
    X.namaAlbum.TabWord[2] = 'M';
    X.namaAlbum.Length = 3;
    X.namaLagu.TabWord[0] = 'T';
    X.namaLagu.TabWord[1] = 'u';
    X.namaLagu.TabWord[2] = 'n';
    X.namaLagu.TabWord[3] = 'a';
    X.namaLagu.TabWord[4] = 's';
    X.namaLagu.Length = 5;
    printf("InsVLast:\n");
    InsVLast(&playlist1, X);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    if(IsEmptyLL(playlist1)){
        printf("ISI PLAYLIST1 KOSONG\n");
    }
    else{
        printf("ISI PLAYLIST1 TIDAK KOSONG\n");
    }
    if(IsEmptyLL(playlist2)){
        printf("ISI PLAYLIST2 KOSONG\n");
    }
    else{
        printf("ISI PLAYLIST2 TIDAK KOSONG\n");
    }
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsertFirstLL AMANNN\n");
    printf("MILESTONE2\n\n");
    Y.namaPenyanyi.TabWord[0] = 'V';
    Y.namaPenyanyi.TabWord[1] = 'i';
    Y.namaPenyanyi.TabWord[2] = 'e';
    Y.namaPenyanyi.TabWord[3] = 'r';
    Y.namaPenyanyi.TabWord[4] = 'r';
    Y.namaPenyanyi.TabWord[5] = 'a';
    Y.namaPenyanyi.TabWord[6] = 't';
    Y.namaPenyanyi.TabWord[7] = 'a';
    Y.namaPenyanyi.TabWord[8] = 'l';
    Y.namaPenyanyi.TabWord[9] = 'e';
    Y.namaPenyanyi.Length = 10;
    Y.namaAlbum.TabWord[0] = 'L';
    Y.namaAlbum.TabWord[1] = 'o';
    Y.namaAlbum.TabWord[2] = 'v';
    Y.namaAlbum.TabWord[3] = 'e';
    Y.namaAlbum.Length = 4;
    Y.namaLagu.TabWord[0] = 'P';
    Y.namaLagu.TabWord[1] = 'e';
    Y.namaLagu.TabWord[2] = 'r';
    Y.namaLagu.TabWord[3] = 'i';
    Y.namaLagu.TabWord[4] = 'h';
    Y.namaLagu.Length = 5;
    printf("InsVFirst:\n");
    InsVFirst(&playlist1, Y);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL AMANNNNN\n");
    Z.namaPenyanyi.TabWord[0] = 'B';
    Z.namaPenyanyi.TabWord[1] = 'l';
    Z.namaPenyanyi.TabWord[2] = 'a';
    Z.namaPenyanyi.TabWord[3] = 'c';
    Z.namaPenyanyi.TabWord[4] = 'k';
    Z.namaPenyanyi.TabWord[5] = 'p';
    Z.namaPenyanyi.TabWord[6] = 'i';
    Z.namaPenyanyi.TabWord[7] = 'n';
    Z.namaPenyanyi.TabWord[8] = 'k';
    Z.namaPenyanyi.Length = 9;
    Z.namaAlbum.TabWord[0] = 'B';
    Z.namaAlbum.TabWord[1] = 'O';
    Z.namaAlbum.TabWord[2] = 'R';
    Z.namaAlbum.TabWord[3] = 'N';
    Z.namaAlbum.TabWord[4] = ' ';
    Z.namaAlbum.TabWord[5] = 'P';
    Z.namaAlbum.TabWord[6] = 'I';
    Z.namaAlbum.TabWord[7] = 'N';
    Z.namaAlbum.TabWord[8] = 'K';
    Z.namaAlbum.Length = 9;
    Z.namaLagu.TabWord[0] = 'S';
    Z.namaLagu.TabWord[1] = 'h';
    Z.namaLagu.TabWord[2] = 'u';
    Z.namaLagu.TabWord[3] = 't';
    Z.namaLagu.TabWord[4] = ' ';
    Z.namaLagu.TabWord[5] = 'D';
    Z.namaLagu.TabWord[6] = 'o';
    Z.namaLagu.TabWord[7] = 'w';
    Z.namaLagu.TabWord[8] = 'n';
    Z.namaLagu.Length = 9;
    printf("InsVLast:\n");
    InsVLast(&playlist1, Z);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL, InsertAfterLL AMANNNNN\n");
    printf("MILESTONE3\n\n");
    printf("DelVFirst:\n");
    DelVFirst(&playlist1, &Y);
    printf("BERIKUT ADALAH ISI playlist1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("YANG DIHAPUS DARI playlist1:\n");
    printf("NAMA PENYANYI: ");
    printWord(Y.namaPenyanyi);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(Y.namaAlbum);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(Y.namaLagu);
    printf("\n");
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL, InsertAfterLL, DelVFirst, DealokasiLL  AMANNNNN\n\n");
    printf("DelVLast:\n");
    DelVLast(&playlist1, &Z);
    printf("BERIKUT ADALAH ISI playlist1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("YANG DIHAPUS DARI playlist1:\n");
    printf("NAMA PENYANYI: ");
    printWord(Z.namaPenyanyi);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(Z.namaAlbum);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(Z.namaLagu);
    printf("\n");
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL, InsertAfterLL, DelVFirst, DealokasiLL, DelVLast AMANNNNN\n");
    printf("\nDelPLL:\n");
    DelPLL(&playlist1, X);
    printf("BERIKUT ADALAH ISI playlist1:\n");
    PrintInfoLL(playlist1);
    printf("\n");
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL, InsertAfterLL, DelVFirst, DealokasiLL, DelVLast, DelPLL AMANNNNN\n");
    printf("MILESTONE4\n\n");
    InsVFirst(&playlist1, X);
    InsVFirst(&playlist1, Y);
    InsVFirst(&playlist1, Z);
    printf("BERIKUT ISI PLAYLIST1: \n");
    PrintInfoLL(playlist1);
    printf("\n\nBERIKUT ISI PLAYLIST2: \n");
    PrintInfoLL(playlist2);
    printf("\n");
    printf("JUMLAH ISI PLAYLIST1: %d; JUMLAH ISI PLAYLIST2: %d\n", NbElmtLL(playlist1), NbElmtLL(playlist2));
    InsVFirst(&playlist2, X);
    InsVFirst(&playlist2, Y);
    InsVFirst(&playlist2, Z);
    printf("\nUPDATE ISI PLAYLIST\n");
    printf("BERIKUT ISI PLAYLIST1: \n");
    PrintInfoLL(playlist1);
    printf("\nBERIKUT ISI PLAYLIST2: \n");
    PrintInfoLL(playlist2);
    printf("\n");
    if(isLLsama(playlist1,playlist2)){
        printf("PLAYLIST1 DAN PLAYLIST2 SAMA\n");
    }
    else{
        printf("PLAYLIST1 DAN PLAYLIST2 TIDAK SAMA\n");
    }
    InversListLL(&playlist1);
    printf("\nUPDATE ISI PLAYLIST\n");
    printf("BERIKUT ISI PLAYLIST1: \n");
    PrintInfoLL(playlist1);
    printf("\nBERIKUT ISI PLAYLIST2: \n");
    PrintInfoLL(playlist2);
    printf("\n");
    if(isLLsama(playlist1,playlist2)){
        printf("PLAYLIST1 DAN PLAYLIST2 SAMA\n");
    }
    else{
        printf("PLAYLIST1 DAN PLAYLIST2 TIDAK SAMA\n");
    }
    printf("CreateEmptyListLin, IsEmptyLL, PrintInfoLL, InsVLast, AlokasiLL, InsertLastLL, InsVFirst, InsertFirstLL, InsertAfterLL, DelVFirst, DealokasiLL, DelVLast, DelPLL, nbElmtLL, InversListLL, isLLSama AMANNNNN\n");
    printf("MILESTONE5\n");
    return 0;
}