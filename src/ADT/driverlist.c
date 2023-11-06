#include <stdio.h>
#include "list.h"

int main(){
    List L1, L2;
    MakeList(&L1);
    MakeList(&L2);
    printf("Berikut adalah isi List 1:\n");
    PrintList(&L1);
    printf("Berikut adalah isi List 2:\n");
    PrintList(&L2);
    if(IsEmpty(L1)){
        printf("List 1 kosong\n");
    }
    else{
        printf("List 1 tidak kosong\n");
    }
    InsertFirst(&L1, 2);
    PrintList(&L1);
    InsertLast(&L1, 5);
    PrintList(&L1);
    InsertFirst(&L1, 3);
    PrintList(&L1);
    InsertAt(&L1, 4, 1);
    PrintList(&L1);
    if(IsEmpty(L1)){
        printf("List 1 kosong\n");
    }
    else{
        printf("List 1 tidak kosong\n");
    }
    if(IsIdxValid(L1, 123)){
        printf("Indeks 123 valid\n");
    }
    else{
        printf("Indeks 123 tidak valid\n");
    }
    if(IsIdxValid(L1, 5)){
        printf("Indeks 5 valid\n");
    }
    else{
        printf("Indeks 5 tidak valid\n");
    }
    if(IsIdxEff(L1, 5)){
        printf("Indeks 5 merupakan indeks efektif\n");
    }
    else{
        printf("Indeks 5 bukan indeks efektif\n");
    }
    if(IsIdxEff(L1, 3)){
        printf("Indeks 3 merupakan indeks efektif\n");
    }
    else{
        printf("Indeks 3 bukan indeks efektif\n");
    }
    int idx = 2;
    int ops1 = Get(L1, idx);
    printf("Elemen List 1 indeks ke %d adalah %d\n", idx, ops1);
    Set(&L1, idx, 99);
    int ops2 = Get(L1, idx);
    printf("Elemen List 1 indeks ke %d telah berubah dari %d menjadi %d\n", idx, ops1, ops2);
    PrintList(&L1);
    printf("Panjang List 1 adalah %d\n", Length(L1));
    printf("Indeks pertama dari List 1 adalah %d dan Indeks terakhir dari List 1 adalah %d\n", FirstIdx(L1), LastIdx(L1));
    if(Search(L1, ops1)){
        printf("Elemen %d pada List 1 ditemukan\n", ops1);
    }
    else{
        printf("Elemen %d pada List 1 tidak ditemukan\n", ops1);
    }
    if(Search(L1, ops2)){
        printf("Elemen %d pada List 1 ditemukan\n", ops2);
    }
    else{
        printf("Elemen %d pada List 1 tidak ditemukan\n", ops2);
    }
    printf("Berikut pengecekan pada List 2:\n");
    PrintList(&L2);
    printf("Panjang List 2: %d\n", Length(L2));
    InsertLast(&L2, 1);
    PrintList(&L2);
    printf("Panjang List 2: %d\n", Length(L2));
    InsertLast(&L2, 7);
    PrintList(&L2);
    printf("Panjang List 2: %d\n", Length(L2));
    InsertFirst(&L2, 3);
    PrintList(&L2);
    printf("Panjang List 2: %d\n", Length(L2));
    InsertAt(&L2, 8, 6);
    PrintList(&L2);
    printf("Panjang List 2: %d\n", Length(L2));
    DeleteFirst(&L1);
    printf("List 1: ");
    PrintList(&L1);
    DeleteLast(&L2);
    printf("List 2: ");
    PrintList(&L2);
    DeleteAt(&L1, 2);
    printf("List 1: ");
    PrintList(&L1);
    return 0;
}