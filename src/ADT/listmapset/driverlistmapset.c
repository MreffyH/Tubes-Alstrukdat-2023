#include <stdio.h>
#include <stdlib.h>
#include "../../../REVISI_TOTAL_MESIN_KATA/listmapset.h"
// gcc driverlistmapset.c ../mapset/set.c ../../../REVISI_TOTAL_MESIN_KATA/mesinkata.c ../../../REVISI_TOTAL_MESIN_KATA/mesinkarakter.c ../../../REVISI_TOTAL_MESIN_KATA/listmapset.c -o a.exe
int main(){
    Set s1;
    Set s2;

    CreateEmptySet(&s1);
    CreateEmptySet(&s2);
    Word kalimat;
    kalimat.TabWord[0] = 'a';
    kalimat.TabWord[1] = 'p';
    kalimat.TabWord[2] = 'p';
    kalimat.TabWord[3] = 'l';
    kalimat.TabWord[4] = 'e';
    kalimat.Length = 5;
    InsertSet(&s1, kalimat);
    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    InsertSet(&s1, kalimat);
    kalimat.TabWord[0] = 'o';
    kalimat.TabWord[1] = 'r';
    kalimat.TabWord[2] = 'a';
    kalimat.TabWord[3] = 'n';
    kalimat.TabWord[4] = 'g';
    kalimat.TabWord[5] = 'e';
    kalimat.Length = 6;
    InsertSet(&s1, kalimat);

    // kalimat.TabWord[0] = 'b';
    // kalimat.TabWord[1] = 'a';
    // kalimat.TabWord[2] = 'n';
    // kalimat.TabWord[3] = 'a';
    // kalimat.TabWord[4] = 'n';
    // kalimat.TabWord[5] = 'a';
    // kalimat.Length = 6;
    // InsertSet(&s2, kalimat);
    // kalimat.TabWord[0] = 'g';
    // kalimat.TabWord[1] = 'r';
    // kalimat.TabWord[2] = 'a';
    // kalimat.TabWord[3] = 'p';
    // kalimat.TabWord[4] = 'e';
    // kalimat.Length = 5;
    // InsertSet(&s2, kalimat);
    // kalimat.TabWord[0] = 'k';
    // kalimat.TabWord[1] = 'i';
    // kalimat.TabWord[2] = 'w';
    // kalimat.TabWord[3] = 'i';
    // kalimat.Length = 4;
    // InsertSet(&s2, kalimat);

    // kalimat.TabWord[0] = 'b';
    // kalimat.TabWord[1] = 'a';
    // kalimat.TabWord[2] = 'n';
    // kalimat.TabWord[3] = 'a';
    // kalimat.TabWord[4] = 'n';
    // kalimat.TabWord[5] = 'a';
    // kalimat.Length = 6;
    // DeleteSet(&s1, kalimat);
    // printf("SET 1:\n");
    // PrintSet(s1);
    // printf("\nSET 2:\n");
    // PrintSet(s2);
    // printf("\n");


    MapAlbum mAlbum;
    CreateMapAlbum(&mAlbum, s1);
    kalimat.TabWord[0] = 'S';
    kalimat.TabWord[1] = 'n';
    kalimat.TabWord[2] = 'M';
    kalimat.Length = 3;
    mAlbum.namaAlbum = DuplicateKata(kalimat);
    printf("isi-isi lagu album :\n");
    PrintSet(mAlbum.setlagu);
    printf("Nama albumnya lagu-lagu tersebut:\n");
    printWord(mAlbum.namaAlbum);
    printf("\n\n");

    
    MapPenyanyi mPenyanyi;
    CreateMapPenyanyi(&mPenyanyi, mAlbum);
    Word kalimat2;
    kalimat2.TabWord[0] = 'J';
    kalimat2.TabWord[1] = 'K';
    kalimat2.TabWord[2] = 'T';
    kalimat2.TabWord[3] = '4';
    kalimat2.TabWord[4] = '8';
    kalimat2.Length = 5;
    mPenyanyi.namaPenyanyi = DuplicateKata(kalimat2);
    mPenyanyi.countalbum++; 
    printf("Nama album dari suatu artis: \n");
    printWord(mPenyanyi.mapalbum[0].namaAlbum);
    printf("\n");
    printf("Nama penyanyi yang punya album tersebut:\n");
    printWord(mPenyanyi.namaPenyanyi);
    printf("\n");
    printf("Berapa jumlah album dari penyanyi tersebut: %d\n", mPenyanyi.countalbum);
    printf("\n\n");


    ListPenyanyi LisPenyanyi_;
    CreateListPenyanyi(&LisPenyanyi_, mPenyanyi);
    LisPenyanyi_.countpenyanyi++;
    printf("MILESTONE\n");
    
    printf("Nama penyanyi pertama dari listpenyanyi:\n");
    printWord(LisPenyanyi_.penyanyi_ke[0].namaPenyanyi);
    Word singer1 = DuplicateKata(LisPenyanyi_.penyanyi_ke[0].namaPenyanyi);
    
    printf("\n");
    printf("Jumlah penyanyi sekarang: %d\n", Jumlahpenyanyi(LisPenyanyi_));
    printf("Milestone1\n\n\n");
    Word ABC;
    ABC.TabWord[0] = 'A';
    ABC.TabWord[1] = 'B';
    ABC.TabWord[2] = 'C';
    ABC.Length = 3;
    // if(IsKataEqual(singer1, ABC)){
    //     printf("\nsama\n");
    // }
    // else{
    //     printf("Gak sama\n");
    // }
    // printf("\n\n\n\n\n");

    // int cek1 = LisPenyanyi_.countpenyanyi;
    // printf("cek1: %d\n", cek1);
    // Word cek2 = LisPenyanyi_.penyanyi_ke[0].namaPenyanyi;
    // printf("cek2: ");
    // printWord(cek2);
    // printf("\n");
    // int cek3 = LisPenyanyi_.penyanyi_ke[0].countalbum;
    // printf("cek3: %d\n", cek3);
    // Word cek4 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].namaAlbum;
    // printf("cek4: ");
    // printWord(cek4);
    // printf("\n");
    // int cek5 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].setlagu.Count;
    // printf("cek5: %d\n", cek5);
    // Word cek6 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].setlagu.Elements[0];
    // printf("cek6: ");
    // printWord(cek6);
    // printf("\n");
    // Word cek7 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].setlagu.Elements[1];
    // printf("cek7: ");
    // printWord(cek7);
    // printf("\n");
    // Word cek8 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].setlagu.Elements[2];
    // printf("cek8: ");
    // printWord(cek8);
    // printf("\n");
    // Word cek9 = LisPenyanyi_.penyanyi_ke[0].mapalbum[0].setlagu.Elements[3];
    // printf("cek9: ");
    // printWord(cek9);
    // printf("\n");
    // printWord(ABC);
    // printf(" adalah penyanyi urutan penyanyi ke-%d\n", urutanke);
    // printf("Nama penyanyi kedua:\n");
    // printWord(LisPenyanyi_.penyanyi_ke[0].namaPenyanyi);
    // Q.TabWord[0] = 'Q';
    // Q.Length = 1;
    // I.TabWord[0] = 'I';
    // I.Length = 1;
    // AddPenyanyi(&L, ABC);
    // AddAlbum(&L, ABC, Q);
    // AddLagu(&L, ABC, Q, I);
    // printWord(L.penyanyi_ke[0].namaPenyanyi);
    // printf("\n");
    // printWord(L.penyanyi_ke[0].listalbum[0].namaAlbum);
    // printf("\n");
    // printWord(L.penyanyi_ke[0].listalbum[0].setlagu.Elements[0]);
    // printf("\n");
    AddPenyanyi(&LisPenyanyi_, ABC);
    printf("\n-----------------------\n");
    printWord(ABC);
    printf("\n");
    printf("MILESTONE2\n");
    // printWord(kalimat2);
    printf("%d\n", LisPenyanyi_.countpenyanyi);
    printWord(LisPenyanyi_.penyanyi_ke[0].namaPenyanyi);
    printf("\n");
    printWord(LisPenyanyi_.penyanyi_ke[1].namaPenyanyi);
    printf("\n");


    printf("MILESTONE3\n\n");
    Word kalimat3;
    kalimat3.TabWord[0] = 'D';
    kalimat3.TabWord[1] = 'e';
    kalimat3.TabWord[2] = 'a';
    kalimat3.TabWord[3] = 't';
    kalimat3.TabWord[4] = 'h';
    kalimat3.Length = 5;
    AddAlbum(&LisPenyanyi_, ABC, kalimat3);

    // printWord(kalimat3);
    printf("NAMA ALBUM BARU: ");
    printWord(LisPenyanyi_.penyanyi_ke[1].mapalbum[0].namaAlbum);
    printf("\n");
    printf("MILESTONE4\n");

    Word kalimat4;
    kalimat4.TabWord[0] = 'M';
    kalimat4.TabWord[1] = 'a';
    kalimat4.TabWord[2] = 'n';
    kalimat4.TabWord[3] = 't';
    kalimat4.TabWord[4] = 'a';
    kalimat4.TabWord[5] = 'p';
    kalimat4.Length = 6;
    AddLagu(&LisPenyanyi_, ABC, kalimat3, kalimat4);
    printf("LAGU BARU YANG DITAMBAHKAN: ");
    printWord(LisPenyanyi_.penyanyi_ke[1].mapalbum[0].setlagu.Elements[0]);
    printf("\n");
    printf("MILESTONE5\n");
    printf("DISPLAY SEMUA PENYANYI:\n");
    for(int j = 0; j<Jumlahpenyanyi(LisPenyanyi_); j++){
        printf("%d. ", j+1);
        printWord(LisPenyanyi_.penyanyi_ke[j].namaPenyanyi);
        printf("\n");
    }
    printf("\n\n\n");
    int choice = 1;
    printf("CHOICE : %d\n", choice);
    printf("DISPLAY SEMUA ALBUM DARI ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].namaPenyanyi);
    printf("\n");
    for(int j = 0; j < LisPenyanyi_.penyanyi_ke[choice-1].countalbum; j++){
        printf("%d. ", j+1);
        printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[j].namaAlbum);
        printf("\n");
    }
    int choice2 = 1;
    printf("CHOICE2: %d\n", choice2);
    printf("DISPLAY SEMUA LAGU DARI ALBUM ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].namaAlbum);
    printf(" DARI PENYANYI ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].namaPenyanyi);
    printf("\n");
    for(int j = 0; j < LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Count; j++){
        printf("%d. ", j+1);
        printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Elements[j]);
        printf("\n");
    }

    printf("\n\n");
    choice = 2;
    printf("CHOICE : %d\n", choice);
    printf("DISPLAY SEMUA ALBUM DARI ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].namaPenyanyi);
    printf("\n");
    for(int j = 0; j < LisPenyanyi_.penyanyi_ke[choice-1].countalbum; j++){
        printf("%d. ", j+1);
        printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[j].namaAlbum);
        printf("\n");
    }
    choice2 = 1;
    printf("CHOICE2: %d\n", choice2);
    printf("DISPLAY SEMUA LAGU DARI ALBUM ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].namaAlbum);
    printf(" DARI PENYANYI ");
    printWord(LisPenyanyi_.penyanyi_ke[choice-1].namaPenyanyi);
    printf("\n");
    for(int j = 0; j < LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Count; j++){
        printf("%d. ", j+1);
        printWord(LisPenyanyi_.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Elements[j]);
        printf("\n");
    }

    printf("\nMILESTONE4\n");
    printf("BERIKUT ADALAH SEMUA PENYANYI YANG ADA: \n");
    DISPLAYPENYANYI(LisPenyanyi_);
    printf("\nBERIKUT ADALAH SEMUA ALBUM YANG ADA:\n");
    DISPLAYALBUM(LisPenyanyi_);
    printf("\nBERIKUT ADALAH SEMUA LAGU YANG ADA:\n");
    DISPLAYLAGU(LisPenyanyi_);

    printf("\nMILESTONE5\n");
    int cek1 = SearchPenyanyi_ke(LisPenyanyi_, ABC);
    printf("PENYANYI ");
    printWord(ABC);
    printf(" ADALAH URUTAN KE-%d\n", cek1);

    int cek2 = SearchAlbum_ke(LisPenyanyi_, ABC, kalimat3);
    printf("PENYANYI ");
    printWord(ABC);
    printf(" MEMILIKI ALBUM BERJUDUL ");
    printWord(kalimat3);
    printf(" ADALAH URUTAN ALBUM KE-%d\n", cek2);

    printf("\nMILESTONE6\n");

    int cek3 = SearchLagu_ke(LisPenyanyi_, ABC, kalimat3, kalimat4);
    printf("PENYANYI ");
    printWord(ABC);
    printf(" MEMILIKI ALBUM BERJUDUL ");
    printWord(kalimat3);
    printf(" YANG DI DALAMNYA TERDAPAT LAGU BERJUDUL ");
    printWord(kalimat4);
    printf(" YANG MERUPAKAN URUTAN LAGU KE-%d\n", cek3);

    printf("\nMILESTONE7\n");
    int idx = 2;
    Word cek4 = GetLagu(LisPenyanyi_, kalimat2, kalimat, idx);
    printf("PENYANYI ");
    printWord(kalimat2);
    printf(" MEMILIKI ALBUM BERJUDUL ");
    printWord(kalimat);
    printf(" YANG DI DALAMNYA PADA URUTAN KE-%d ADA LAGU BERJUDUL ", idx);
    printWord(cek4);
    printf("\n");

    return 0;
}

// int main() {
//     printf("CEK1\n");
//     ListPenyanyi penyanyiList;
//     Sentence penyanyiName;
//     penyanyiName.TabSentence[0] = 'J';
//     penyanyiName.TabSentence[1] = 'o';
//     penyanyiName.TabSentence[2] = 'h';
//     penyanyiName.TabSentence[3] = 'n';
//     penyanyiName.TabSentence[4] = ' ';
//     penyanyiName.TabSentence[5] = 'D';
//     penyanyiName.TabSentence[6] = 'o';
//     penyanyiName.TabSentence[7] = 'e';
//     penyanyiName.Length = 8;
//     Sentence albumName;
//     albumName.TabSentence[0] = 'G';
//     albumName.TabSentence[1] = 'r';
//     albumName.TabSentence[2] = 'e';
//     albumName.TabSentence[3] = 'a';
//     albumName.TabSentence[4] = 't';
//     albumName.TabSentence[5] = 'e';
//     albumName.TabSentence[6] = 's';
//     albumName.TabSentence[7] = 't';
//     albumName.TabSentence[8] = ' ';
//     albumName.TabSentence[9] = 'H';
//     albumName.TabSentence[10] = 'i';
//     albumName.TabSentence[11] = 't';
//     albumName.TabSentence[12] = 's';
//     albumName.Length = 13;
//     Sentence songName;
//     songName.TabSentence[0] = 'A';
//     songName.TabSentence[1] = 'w';
//     songName.TabSentence[2] = 'e';
//     songName.TabSentence[3] = 's';
//     songName.TabSentence[4] = 'o';
//     songName.TabSentence[5] = 'm';
//     songName.TabSentence[6] = 'e';
//     songName.TabSentence[7] = ' ';
//     songName.TabSentence[8] = 'S';
//     songName.TabSentence[9] = 'o';
//     songName.TabSentence[10] = 'n';
//     songName.TabSentence[11] = 'g';
//     songName.Length = 12;
//     printf("CEK2\n");
//     // CreateListPenyanyi(&penyanyiList);

//     // PrintSentence(penyanyiName);
//     // AddPenyanyi(&penyanyiList, penyanyiName);

//     // PrintSentence(albumName);
//     // AddAlbum(&penyanyiList, penyanyiName, albumName);

//     // PrintSentence(songName);
//     // AddLagu(&penyanyiList, penyanyiName, albumName, songName);

//     // Add more penyanyi, albums, and songs for testing

//     // Display the contents of the penyanyiList
//     // int i, j, k;
//     // for (i = 0; i < Jumlahpenyanyi(penyanyiList); i++) {
//     //     printf("Penyanyi: %s\n", penyanyiList.penyanyi_ke[i].namaPenyanyi);
//     //     for (j = 0; j < penyanyiList.penyanyi_ke[i].countalbum; j++) {
//     //         printf("\tAlbum: %s\n", penyanyiList.penyanyi_ke[i].listalbum[j].namaAlbum);
//     //         printf("\tLagu:");
//     //         for (k = 0; k < JumlahSet(penyanyiList.penyanyi_ke[i].listalbum[j].setlagu); k++) {
//     //             printf(" %s", penyanyiList.penyanyi_ke[i].listalbum[j].setlagu.Elements[k]);
//     //         }
//     //         printf("\n");
//     //     }
//     // }

//     return 0;
// }