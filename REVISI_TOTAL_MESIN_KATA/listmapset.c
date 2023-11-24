#include "listmapset.h"
#include <stdio.h>
#include <stdlib.h>

void CreateMapAlbum(MapAlbum *mapalbum, Set S)
{
    (*mapalbum).setlagu = S;
}

void CreateMapPenyanyi(MapPenyanyi *mappenyanyi, MapAlbum m_album)
{
    (*mappenyanyi).mapalbum[0] = m_album;
    Jumlahalbum(*mappenyanyi) = 0;
}

void CreateListPenyanyi(ListPenyanyi *penyanyi, MapPenyanyi mappenyanyi)
{
    Jumlahpenyanyi(*penyanyi) = 0;
    (*penyanyi).penyanyi_ke[0] = mappenyanyi;
}

int SearchPenyanyi_ke(ListPenyanyi penyanyi, Word namaPenyanyi)
{
    int i = 0;
    boolean found = false;
    while ((i < Jumlahpenyanyi(penyanyi)) && (!found))
    {
        if (IsKataEqual((penyanyi).penyanyi_ke[i].namaPenyanyi, namaPenyanyi))
        {
            found = true;
        }
        else
        {
            i++;
        }
    } /* i == Jumlahpenyanyi(*penyanyi) or found */
    if (found)
    {
        return i;
    }
    else
    {
        return NOTFOUND;
    }
}

void AddPenyanyi(ListPenyanyi *penyanyi, Word nama)
{
    int urutan = SearchPenyanyi_ke(*penyanyi, nama);
    if (urutan == NOTFOUND)
    {
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

void AddAlbum(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum)
{
    int urutanpenyanyi = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if (urutanpenyanyi != NOTFOUND)
    {
        int urutanalbum = SearchAlbum_ke((*penyanyi), (*penyanyi).penyanyi_ke[urutanpenyanyi].namaPenyanyi, namaAlbum);
        if (urutanalbum == NOTFOUND)
        {
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

int SearchAlbum_ke(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum)
{
    int i = 0;
    boolean found = false;
    int urutan = SearchPenyanyi_ke(penyanyi, namaPenyanyi);
    if (urutan != NOTFOUND)
    {
        while ((i < Jumlahalbum(penyanyi.penyanyi_ke[urutan])) && (!found))
        {
            if (IsKataEqual(penyanyi.penyanyi_ke[urutan].mapalbum[i].namaAlbum, namaAlbum))
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
    } /* i == Jumlahalbum(penyanyi.penyanyi_ke[urutan]) or found */
    if (found)
    {
        return i;
    }
    else
    {
        return NOTFOUND;
    }
}

void AddLagu(ListPenyanyi *penyanyi, Word namaPenyanyi, Word namaAlbum, Word namaLagu)
{
    /* cari penyanyi */
    int urutanpenyanyi = SearchPenyanyi_ke(*penyanyi, namaPenyanyi);
    if (urutanpenyanyi != NOTFOUND)
    {
        /* cari album */
        int urutanalbum = SearchAlbum_ke((*penyanyi), (*penyanyi).penyanyi_ke[urutanpenyanyi].namaPenyanyi, namaAlbum);
        if (urutanalbum != NOTFOUND)
        {
            /* cari apakah ada lagu yang sama */
            if (!IsMemberSet((*penyanyi).penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu, namaLagu))
            {
                InsertSet(&((*penyanyi).penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu), namaLagu);
            }
        }
    }
}

int SearchLagu_ke(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum, Word namaLagu)
{
    int i = 0;
    boolean found = false;
    int urutanpenyanyi = SearchPenyanyi_ke(penyanyi, namaPenyanyi);
    if (urutanpenyanyi != NOTFOUND)
    {
        int urutanalbum = SearchAlbum_ke(penyanyi, namaPenyanyi, namaAlbum);
        if (urutanalbum != NOTFOUND)
        {
            while ((i < penyanyi.penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu.Count) && (!found))
            {
                if (IsKataEqual(penyanyi.penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu.Elements[i], namaLagu))
                {
                    found = true;
                }
                else
                {
                    i++;
                }
            }
        }
    } /* i == penyanyi.penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu.Count or found */
    if (found)
    {
        return i;
    }
    else
    {
        return NOTFOUND;
    }
}

Word GetLagu(ListPenyanyi penyanyi, Word namaPenyanyi, Word namaAlbum, int idx)
{
    Word namaLagu;
    namaLagu.TabWord[0] = '-';
    namaLagu.Length = 1;
    boolean found = false;
    int urutanpenyanyi = SearchPenyanyi_ke(penyanyi, namaPenyanyi);
    if (urutanpenyanyi != NOTFOUND)
    {

        int urutanalbum = SearchAlbum_ke(penyanyi, namaPenyanyi, namaAlbum);
        if (urutanalbum != NOTFOUND)

        {
            if(((idx - 1) < penyanyi.penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu.Count) && ((idx - 1) >= 0)){
                namaLagu = DuplicateKata(penyanyi.penyanyi_ke[urutanpenyanyi].mapalbum[urutanalbum].setlagu.Elements[idx - 1]);
            }
        }
    }
    return namaLagu;
}

void DISPLAYPENYANYI(ListPenyanyi penyanyi)
{
    printf("DISPLAY SEMUA PENYANYI:\n");
    for (int j = 0; j < Jumlahpenyanyi(penyanyi); j++)
    {
        printf("%d. ", j + 1);
        printWord(penyanyi.penyanyi_ke[j].namaPenyanyi);
        printf("\n");
    }
}

void DISPLAYALBUM(ListPenyanyi penyanyi)
{
    int choice;
    printf("CHOICE: ");
    STARTWORD();
    choice = strToInteger(currentWord);
    if(((choice - 1) < penyanyi.countpenyanyi) && ((choice - 1) >= 0)){
        printf("DISPLAY SEMUA ALBUM DARI ");
        printWord(penyanyi.penyanyi_ke[choice - 1].namaPenyanyi);
        printf("\n");
        for (int j = 0; j < penyanyi.penyanyi_ke[choice - 1].countalbum; j++)
        {
            printf("%d. ", j + 1);
            printWord(penyanyi.penyanyi_ke[choice - 1].mapalbum[j].namaAlbum);
            printf("\n");
        }
    }
}

void DISPLAYLAGU(ListPenyanyi penyanyi)
{
    int choice;
    printf("PENYANYI KE BERAPA: ");
    STARTWORD();
    choice = strToInteger(currentWord);
    if(((choice - 1) < penyanyi.countpenyanyi) && ((choice - 1) >= 0)){
        int choice2;
        printf("ALBUM KE BERAPA: ");
        STARTWORD();
        choice2 = strToInteger(currentWord);
        if(((choice2 - 1) < penyanyi.penyanyi_ke[choice-1].countalbum) && ((choice2 - 1) >= 0)){
            printWord(penyanyi.penyanyi_ke[choice - 1].mapalbum[choice2 - 1].namaAlbum);
            printf(" DARI PENYANYI ");
            printWord(penyanyi.penyanyi_ke[choice - 1].namaPenyanyi);
            printf("\n");
            for (int j = 0; j < penyanyi.penyanyi_ke[choice - 1].mapalbum[choice2 - 1].setlagu.Count; j++)
            {
                printf("%d. ", j + 1);
                printWord(penyanyi.penyanyi_ke[choice - 1].mapalbum[choice2 - 1].setlagu.Elements[j]);
                printf("\n");
            }
        }
    }
}
