#include "list.h"

int main(){
    List L1, L2, L3;
    MakeList(&L1);
    MakeList(&L2);
    MakeList(&L3);
    printf("Berikut adalah isi List 1:\n");
    PrintList(&L1);
    printf("Berikut adalah isi List 2:\n");
    PrintList(&L2);
    printf("Berikut adalah isi List 3:\n");
    PrintList(&L3);
    if(IsEmpty(L1)){
        printf("List 1 kosong\n");
    }
    else{
        printf("List 1 tidak kosong\n");
    }
    InsertFirst(&L1, 2);
    InsertLast(&L1, 5);
    InsertFirst(&L1, 3);
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
    return 0;
}