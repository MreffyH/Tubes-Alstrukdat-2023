#include "listmapset.h"
#include <stdio.h>
#include <stdlib.h>


void CreateMapAlbum(MapAlbum *mapalbum, Set S){
    (*mapalbum).setlagu = S;
}

void CreateMapPenyanyi(MapPenyanyi *mappenyanyi){
    Jumlahalbum(*mappenyanyi) = 0;
}

void CreateListPenyanyi(ListPenyanyi *penyanyi){
    Jumlahpenyanyi(*penyanyi) = 0;
}

void AddPenyanyi(ListPenyanyi *penyanyi, Word nama){
    int urutan = SearchPenyanyi_ke(*penyanyi, nama);
    if(urutan == NOTFOUND){
        (*penyanyi).penyanyi_ke[Jumlahpenyanyi(*penyanyi)].namaPenyanyi = nama;
        (*penyanyi).penyanyi_ke[Jumlahpenyanyi(*penyanyi)].countalbum = 0;
        Jumlahpenyanyi(*penyanyi)++;
    }
}

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Word namaPenyanyi){
    int i = 0;
    boolean found = false;
    while ((i < Jumlahpenyanyi(penyanyi)) && (!found)){
        if(IsKataEqual((penyanyi).penyanyi_ke[i].namaPenyanyi, namaPenyanyi)){
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

void AddAlbum(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum){
    int urutanpenyanyi = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if(urutanpenyanyi != NOTFOUND){
        int urutanalbum = SearchAlbum_ke((*penyanyi), (*penyanyi).penyanyi_ke[urutanpenyanyi].namaPenyanyi, namaAlbum);
        if(urutanalbum == NOTFOUND){
            (*penyanyi).penyanyi_ke[urutanpenyanyi].listalbum[Jumlahalbum((*penyanyi).penyanyi_ke[urutanpenyanyi])].namaAlbum = namaAlbum; 
            Jumlahalbum((*penyanyi).penyanyi_ke[urutanpenyanyi])++;
        }
    }
}

int SearchAlbum_ke(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum){
    int i = 0;
    boolean found = false;
    int urutan = SearchPenyanyi_ke(penyanyi, namaPenyanyi);
    if(urutan != NOTFOUND){
        while((i < Jumlahalbum(penyanyi.penyanyi_ke[urutan])) && (!found)){
            if(IsKataEqual(penyanyi.penyanyi_ke[urutan].listalbum[i].namaAlbum, namaAlbum)){
                found = true;
            }
            else{
                i++;
            }
        }
    } /* i == Jumlahalbum(penyanyi.penyanyi_ke[urutan]) or found */
    if (found){
        return i;
    }
    else{
        return NOTFOUND;
    }
}

void AddLagu(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum, Word namaLagu){
    /* cari penyanyi */
    int urutanpenyanyi = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if(urutanpenyanyi != NOTFOUND){
        /* cari album */
        int urutanalbum = SearchAlbum_ke((*penyanyi), (*penyanyi).penyanyi_ke[urutanpenyanyi].namaPenyanyi, namaAlbum);
        if(urutanalbum != NOTFOUND){
            /* cari apakah ada lagu yang sama */
            if(!IsMemberSet((*penyanyi).penyanyi_ke[urutanpenyanyi].listalbum[urutanalbum].setlagu, namaLagu)){
                InsertSet(&((*penyanyi).penyanyi_ke[urutanpenyanyi].listalbum[urutanalbum].setlagu), namaLagu);
            }
        }
    }
}