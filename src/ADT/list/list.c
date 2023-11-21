#include <stdio.h>
#include "list.h"

// Konstruktor

void MakeList(List *L) {
	(*L).Count = 0;
}

boolean IsEmpty(List L) {
	return (L.Count == 0);
}

boolean IsFull(List L) {
	return (L.Count == MaxEl);
}

int Length(List L) {
	return (L.Count);
}

ElType Get(List L, IdxType i) {
	return L.A[i];
}

void SetElmt(List *L, IdxType i, ElType v) {
	(*L).A[i] = v;
}

IdxType FirstIdx(List L) {
    if(!IsEmpty(L)) {
		return 0;
	}
	else {
		return InvalidIdx;
	}
}

IdxType LastIdx(List L) {
	return (L.Count-1);
}

boolean IsIdxValid (List L, IdxType i) {
	return (0 <= i) && (i < MaxEl);
}

boolean IsIdxEff (List L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

boolean Search(List L, ElType X) {
	int i = FirstIdx(L);
	int j = LastIdx(L);
	boolean found = false;
	while ((i <= j) && !found) {
		if (IsKataEqual(L.A[i], X)) {
			found = true;
		}
		i += 1;
	}
    return found;
}

void InsertFirst(List *L, ElType X) {
	IdxType i = LastIdx(*L);
	while (i >= 0) {
		SetElmt(L, i+1, Get(*L, i));
		i--;
	}
	SetElmt(L, 0, X);
}

void InsertAt(List *L, ElType X, IdxType i) {
    IdxType j = LastIdx(*L);
	while (i <= j) {
		SetElmt(L, j+1, Get(*L, j));
        j--;
	}
	SetElmt(L, i, X);
}

void InsertLast(List *L, ElType X) {
	if(!IsFull(*L)) {
		if (IsEmpty(*L)) {
			InsertFirst(L, X);
		} else {
			(*L).A[Length(*L)] = X;
			(*L).Count++;
		}
	}
}

void DeleteFirst(List *L) {
	if(!IsEmpty(*L)){
		int i = FirstIdx(*L);
		while (i < LastIdx(*L)) {
			(*L).A[i] = (*L).A[i+1];
			i++;
		}
		(*L).Count--;
	}
}

void DeleteAt(List *L, IdxType i) {
	if(!IsEmpty(*L)) {
		if(IsIdxEff(*L, i)) {
			int j = LastIdx(*L);
			while (i < j) {
				(*L).A[i] = (*L).A[i+1];
				i++;
			}
			(*L).Count--;
		}
	}
}

void DeleteLast(List *L) {
	if(!IsEmpty(*L)) {
		(*L).Count--;
	}
}

// List Concat(List L1, List L2) {
// 	List L3;
// 	MakeList(&L3);
// 	int i = FirstIdx(L1);
// 	int j = FirstIdx(L2);
// 	int idx = 0;
// 	while (i <= LastIdx(L1)) {
// 		L3.A[idx] = L1.A[i];
//         idx++;
//         i++;
// 	}
// 	while (j <= LastIdx(L2)) {
// 		L3.A[idx] = L2.A[j];
//         idx++;
//         j++;
// 	}

//     return L3;
// }

void PrintList(List *L) {
	printf("[");
	int i = 0;
	while (i < Length(*L)){
		printf("%d", (*L).A[i]);
		i++;
		if(i != Length(*L)){
			printf(", ");
		}
	}
	printf("]\n");
}