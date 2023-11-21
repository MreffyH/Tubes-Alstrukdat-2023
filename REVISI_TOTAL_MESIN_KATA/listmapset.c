#include "listmapset.h"
#include <stdio.h>
#include <stdlib.h>


void CreateMapAlbum(MapAlbum *mapalbum, Set S){
    (*mapalbum).setlagu = S;
}

void CreateMapPenyanyi(MapPenyanyi *mappenyanyi, MapAlbum m_album) {
    (*mappenyanyi).mapalbum[0] = m_album;
    Jumlahalbum(*mappenyanyi) = 0;
}

void CreateListPenyanyi(ListPenyanyi *penyanyi, MapPenyanyi mappenyanyi){
    Jumlahpenyanyi(*penyanyi) = 0;
    (*penyanyi).penyanyi_ke[0] = mappenyanyi;
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

void AddPenyanyi(ListPenyanyi *penyanyi, Word nama){
    int urutan = SearchPenyanyi_ke(*penyanyi, nama);
    if(urutan == NOTFOUND){
        Set S;
        CreateEmptySet(&S);
        MapAlbum m_album;
        CreateMapAlbum(&m_album, S);
        MapPenyanyi mPenyanyi;
        CreateMapPenyanyi(&mPenyanyi, m_album);
        mPenyanyi.namaPenyanyi = nama;
        (*penyanyi).penyanyi_ke[Jumlahpenyanyi(*penyanyi)] = mPenyanyi;
        Jumlahpenyanyi(*penyanyi)++;
    }
}


void AddAlbum(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum){
    int urutanpenyanyi = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if(urutanpenyanyi != NOTFOUND){
        int urutanalbum = SearchAlbum_ke((*penyanyi), (*penyanyi).penyanyi_ke[urutanpenyanyi].namaPenyanyi, namaAlbum);
        if(urutanalbum == NOTFOUND){
            Set S;
            CreateEmptySet(&S);
            MapAlbum m_album;
            CreateMapAlbum(&m_album, S);
            m_album.namaAlbum = namaAlbum;
            (*penyanyi).penyanyi_ke[urutanpenyanyi].mapalbum[Jumlahalbum((*penyanyi).penyanyi_ke[urutanpenyanyi])] = m_album;
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
            if(IsKataEqual(penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum, namaAlbum)){
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
            if(!IsMemberSet((*penyanyi).penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu, namaLagu)){
                InsertSet(&((*penyanyi).penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu), namaLagu);
            }
        }
    }
}