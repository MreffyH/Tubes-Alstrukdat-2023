#include <stdio.h>
#include <stdlib.h>
#include "../../../REVISI_TOTAL_MESIN_KATA/listmapset.h"

int main(){
    Set s1, s2;

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

    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    InsertSet(&s2, kalimat);
    kalimat.TabWord[0] = 'g';
    kalimat.TabWord[1] = 'r';
    kalimat.TabWord[2] = 'a';
    kalimat.TabWord[3] = 'p';
    kalimat.TabWord[4] = 'e';
    kalimat.Length = 5;
    InsertSet(&s2, kalimat);
    kalimat.TabWord[0] = 'k';
    kalimat.TabWord[1] = 'i';
    kalimat.TabWord[2] = 'w';
    kalimat.TabWord[3] = 'i';
    kalimat.Length = 4;
    InsertSet(&s2, kalimat);

    kalimat.TabWord[0] = 'b';
    kalimat.TabWord[1] = 'a';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 'n';
    kalimat.TabWord[5] = 'a';
    kalimat.Length = 6;
    DeleteSet(&s1, kalimat);
    PrintSet(s1);
    printf("0000000\n");
    PrintSet(s2);


    MapAlbum mAlbum;
    CreateMapAlbum(&mAlbum, s1);
    kalimat.TabWord[0] = 'j';
    kalimat.TabWord[1] = 'k';
    kalimat.TabWord[2] = 't';
    kalimat.Length = 3;
    mAlbum.namaAlbum = DuplicateKata(kalimat);
    PrintSet(mAlbum.setlagu);
    MapPenyanyi mPenyanyi;
    CreateMapPenyanyi(&mPenyanyi);


    ListPenyanyi LisPenyanyi_;
    // CreateListPenyanyi(&LisPenyanyi_);
    printf("MIlestone\n");
    // ABC.TabWord[0] = 'A';
    // ABC.TabWord[1] = 'B';
    // ABC.TabWord[2] = 'C';
    // ABC.Length = 3;
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