#include "listmapset.h"
#include <stdio.h>
#include <stdlib.h>


void CreateListPenyanyi(ListPenyanyi *penyanyi){
    Jumlahpenyanyi(*penyanyi) = 0;
}

void AddPenyanyi(ListPenyanyi *penyanyi, Sentence nama){
    (*penyanyi).penyanyi_ke[Jumlahpenyanyi(*penyanyi)].namaPenyanyi = nama;
    (*penyanyi).penyanyi_ke[Jumlahpenyanyi(*penyanyi)].countalbum = 0;
    Jumlahpenyanyi(*penyanyi)++;
}

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Sentence namaPenyanyi){
    int i = 0;
    boolean found = false;
    while ((i < Jumlahpenyanyi(penyanyi)) && (!found)){
        if(IsKalimatEqual((penyanyi).penyanyi_ke[i].namaPenyanyi, namaPenyanyi)){
            found = true;
        }
        else{
            i++;
        }
    } /* i == Jumlahpenyanyi(*penyanyi) or found */
    if (found){
        return i;
    }
    else{
        return NOTFOUND;
    }
}
void AddAlbum(ListPenyanyi *penyanyi, Sentence namaPenyanyi, Sentence namaAlbum){
    int urutan = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if(urutan != NOTFOUND){
        (*penyanyi).penyanyi_ke[urutan].listalbum[Jumlahalbum((*penyanyi).penyanyi_ke[urutan])].namaAlbum = namaAlbum; 
        Jumlahalbum((*penyanyi).penyanyi_ke[urutan])++;
    }
}

void AddLagu(ListPenyanyi *penyanyi, Sentence namaPenyanyi, Sentence namaAlbum, Sentence namaLagu){
    /* cari penyanyi */
    int urutan = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if(urutan != NOTFOUND){
        /* cari album */
        int i = 0;
        boolean found = false;
        while ((i < (*penyanyi).penyanyi_ke[urutan].countalbum) && (!found)){
            if (IsKalimatEqual((*penyanyi).penyanyi_ke[urutan].listalbum[i].namaAlbum, namaAlbum)){
                found = true;
            }
            else{
                i++;
            }
        } /* i == jumlahalbum or found */
        if(found){
            /* cari apakah ada lagu yang sama */
            if(!IsMemberSet((*penyanyi).penyanyi_ke[urutan].listalbum[i].setlagu, namaLagu)){
                InsertSet(&((*penyanyi).penyanyi_ke[urutan].listalbum[i].setlagu), namaLagu);
            }
        }
    }
}