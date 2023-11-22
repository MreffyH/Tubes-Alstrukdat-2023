#include <stdio.h>
#include "arraydin.h"

int main(){
    /* LOGIKA BERPIKIR ARRAY DINAMIS */
    // int a,c;
    // c = 0;
    // a = 10;
    // printf("CAPACITY: %d; NEFF: %d\n", a, c);
    // while(c<=10){
    //     if(c <= a/2){
    //         a = (a*3)/4;
    //     }
    //     else if(c == a){
    //         a = a*2;
    //     }
    //     c += 1; 
    //     printf("CAPACITY: %d; NEFF: %d\n", a, c);
    // } 
    /* HERE WE GO */
    printf("MILESTONE1\n");
    ArrayDin KumpulanPlaylist;
    KumpulanPlaylist = MakeArrayDin();
    printf("CAPACITY KUMPULAN PLAYLIST: %d\n", GetCapacity(KumpulanPlaylist));
    printf("JUMLAH NEFF KUMPULAN PLAYLIST: %d\n", LengthArrayDin(KumpulanPlaylist));
    if(IsEmptyArrayDin(KumpulanPlaylist)){
        printf("KUMPULAN PLAYLIST KOSONG\n");
    }
    else{
        printf("KUMPULAN PLAYLIST TIDAK KOSONG\n");
    }
    printf("\n");
    PrintArrayDin(KumpulanPlaylist);
    printf("\n");
    printf("\nMakeArrayDin, GetCapacity, LengthArrayDin, IsEmptyArrayDin, PrintArrayDin AMANNN\n");
    printf("\nMILESTONE2\n");
    IsiPlaylist playlist1;
    CreateEmptyListLin(&playlist1.IsiLagu);
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
    InsVLast(&playlist1.IsiLagu, X);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1.IsiLagu);
    printf("\n");
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
    InsVFirst(&playlist1.IsiLagu, Y);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1.IsiLagu);
    printf("\n");
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
    InsVLast(&playlist1.IsiLagu, Z);
    printf("BERIKUT ADALAH ISI PLAYLIST1:\n");
    PrintInfoLL(playlist1.IsiLagu);
    printf("\n");
    playlist1.countlaguLL = NbElmtLL(playlist1.IsiLagu);
    Word title;
    title.TabWord[0] = 'A';
    title.TabWord[1] = 's';
    title.TabWord[2] = 'y';
    title.TabWord[3] = 'i';
    title.TabWord[4] = 'k';
    title.Length = 5;
    playlist1.nama_PlayList = DuplicateKata(title);
    printf("InsertLastArrayDin:\n");
    InsertLastArrayDin(&KumpulanPlaylist, playlist1);
    PrintArrayDin(KumpulanPlaylist);
    printf("CAPACITY KUMPULAN PLAYLIST: %d\n", GetCapacity(KumpulanPlaylist));
    printf("JUMLAH NEFF KUMPULAN PLAYLIST: %d\n", LengthArrayDin(KumpulanPlaylist));
    printf("\nMILESTONE3\n\n");
    IsiPlaylist playlist2;
    CreateEmptyListLin(&playlist2.IsiLagu);
    playlist2.countlaguLL = NbElmtLL(playlist2.IsiLagu);
    title.TabWord[0] = 'M';
    title.TabWord[1] = 'i';
    title.TabWord[2] = 'x';
    title.TabWord[3] = 'e';
    title.TabWord[4] = 'd';
    title.TabWord[5] = ' ';
    title.TabWord[6] = 'F';
    title.TabWord[7] = 'e';
    title.TabWord[8] = 'e';
    title.TabWord[9] = 'l';
    title.TabWord[10] = 'i';
    title.TabWord[11] = 'n';
    title.TabWord[12] = 'g';
    title.TabWord[13] = 's';
    title.Length = 14;
    playlist2.nama_PlayList = DuplicateKata(title);
    printf("InsertFirstArrayDin:\n\n");
    InsertFirstArrayDin(&KumpulanPlaylist, playlist2);
    PrintArrayDin(KumpulanPlaylist);
    printf("CAPACITY KUMPULAN PLAYLIST: %d\n", GetCapacity(KumpulanPlaylist));
    printf("JUMLAH NEFF KUMPULAN PLAYLIST: %d\n", LengthArrayDin(KumpulanPlaylist));
    printf("\nMakeArrayDin, GetCapacity, LengthArrayDin, IsEmptyArrayDin, PrintArrayDin, InsertFirstArrayDin, InsertLastArrayDin, InsertAtArrayDin AMANNN\n");
    printf("\nMILESTONE4\n");
    IdxType idxplaylist1;
    idxplaylist1 = SearchIdxPlaylist(KumpulanPlaylist, playlist1);
    printf("PLAYLIST1 ada di indeks ke: %d\n", idxplaylist1);
    IdxType idxplaylist2;
    idxplaylist2 = SearchIdxPlaylist(KumpulanPlaylist, playlist2);
    printf("PLAYLIST2 ada di indeks ke: %d\n", idxplaylist2);
    printf("MEMBALIK ISI PLAYLIST\n");
    ReverseArrayDin(&KumpulanPlaylist);
    PrintArrayDin(KumpulanPlaylist);
    printf("\nMakeArrayDin, GetCapacity, LengthArrayDin, IsEmptyArrayDin, PrintArrayDin, InsertFirstArrayDin, InsertLastArrayDin, InsertAtArrayDin, SearchIdxPlaylist, ReverseArrayDin AMANNN\n");
    printf("MILESTONE5\n");
    ArrayDin KumpulanPlaylist2;
    KumpulanPlaylist2 = MakeArrayDin();
    KumpulanPlaylist2 = CopyArrayDin(KumpulanPlaylist);
    printf("DeleteLastArrayDin:\n");
    DeleteLastArrayDin(&KumpulanPlaylist);
    PrintArrayDin(KumpulanPlaylist);
    printf("CAPACITY KUMPULAN PLAYLIST: %d\n", GetCapacity(KumpulanPlaylist));
    printf("JUMLAH NEFF KUMPULAN PLAYLIST: %d\n", LengthArrayDin(KumpulanPlaylist));
    printf("DeleteFirstArrayDin:\n");
    DeleteFirstArrayDin(&KumpulanPlaylist);
    PrintArrayDin(KumpulanPlaylist);
    printf("CAPACITY KUMPULAN PLAYLIST: %d\n", GetCapacity(KumpulanPlaylist));
    printf("JUMLAH NEFF KUMPULAN PLAYLIST: %d\n", LengthArrayDin(KumpulanPlaylist));
    printf("HASIL COPY KE KUMPULAN PLAYLIST2\n");
    PrintArrayDin(KumpulanPlaylist2);
    printf("\nMakeArrayDin, GetCapacity, LengthArrayDin, IsEmptyArrayDin, PrintArrayDin, InsertFirstArrayDin, InsertLastArrayDin, InsertAtArrayDin, SearchIdxPlaylist, ReverseArrayDin, DeleteFirstArrayDin, DeleteAtArrayDin, DeleteLastArrayDin, CopyArrayDin AMANNN\n");
    printf("MILESTONE6\n");
    return 0;
}