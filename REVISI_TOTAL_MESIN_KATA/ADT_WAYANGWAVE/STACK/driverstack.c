#include <stdio.h>
#include "stack.h"

int main(){
    printf("MILESTONE1\n");
    HistorySong history;
    CreateEmptyHistorySong(&history);
    if(IsEmptyHistorySong(history)){
        printf("HISTORY KOSONG\n");
    }
    else{
        printf("HISTORY TIDAK KOSONG\n");
    }
    printf("TOP: %d\n", Top(history));
    printf("MILESTONE2\n");
    DetailSongS song1;
    Word kalimat;
    kalimat.TabWord[0] = 'J';
    kalimat.TabWord[1] = 'K';
    kalimat.TabWord[2] = 'T';
    kalimat.TabWord[3] = '4';
    kalimat.TabWord[4] = '8';
    kalimat.Length = 5;
    song1.namaPenyanyiS = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'S';
    kalimat.TabWord[1] = 'n';
    kalimat.TabWord[2] = 'M';
    kalimat.Length = 3;
    song1.namaAlbumS = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'T';
    kalimat.TabWord[1] = 'u';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 's';
    kalimat.Length = 5;
    song1.namaLaguS = DuplicateKata(kalimat);
    printf("NAMA PENYANYI: ");
    printWord(song1.namaPenyanyiS);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(song1.namaAlbumS);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(song1.namaLaguS);
    printf("\n");
    printf("MILESTONE3\n");
    Push(&history,song1);
    printf("TEST DALAM STACKNYA\n");
    printf("NAMA PENYANYI: ");
    printWord(InfoTop(history).namaPenyanyiS);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(InfoTop(history).namaAlbumS);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(InfoTop(history).namaLaguS);
    printf("\nTOP: %d\n", Top(history));
    printf("\n\n\n");
    kalimat.TabWord[0] = 'V';
    kalimat.TabWord[1] = 'i';
    kalimat.TabWord[2] = 'e';
    kalimat.TabWord[3] = 'r';
    kalimat.TabWord[4] = 'r';
    kalimat.TabWord[5] = 'a';
    kalimat.TabWord[6] = 't';
    kalimat.TabWord[7] = 'a';
    kalimat.TabWord[8] = 'l';
    kalimat.TabWord[9] = 'e';
    kalimat.Length = 10;
    song1.namaPenyanyiS = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'L';
    kalimat.TabWord[1] = 'o';
    kalimat.TabWord[2] = 'v';
    kalimat.TabWord[3] = 'e';
    kalimat.Length = 4;
    song1.namaAlbumS = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'P';
    kalimat.TabWord[1] = 'e';
    kalimat.TabWord[2] = 'r';
    kalimat.TabWord[3] = 'i';
    kalimat.TabWord[4] = 'h';
    kalimat.Length = 5;
    song1.namaLaguS = DuplicateKata(kalimat);
    printf("NAMA PENYANYI: ");
    printWord(song1.namaPenyanyiS);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(song1.namaAlbumS);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(song1.namaLaguS);
    printf("\n");
    Push(&history,song1);
    printf("TEST DALAM STACKNYA\n");
    printf("NAMA PENYANYI: ");
    printWord(InfoTop(history).namaPenyanyiS);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(InfoTop(history).namaAlbumS);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(InfoTop(history).namaLaguS);
    printf("\nTOP: %d\n", Top(history));
    printf("\n\n\n");
    printf("MILESTONE4\n");
    // DetailSongS song2;
    // Pop(&history,&song2);
    // printf("NAMA PENYANYI: ");
    // printWord(song2.namaPenyanyiS);
    // printf("\n");
    // printf("NAMA ALBUM: ");
    // printWord(song2.namaAlbumS);
    // printf("\n");
    // printf("NAMA LAGU: ");
    // printWord(song2.namaLaguS);
    // printf("\n");
    // printf("TOP: %d\n", Top(history));
    // printf("\n\n");
    DisplayHistorySong(history);
    printf("\nSEKARANG ISI STACK AKAN DIINVERS:\n");
    INVERSSTACK(&history);
    DisplayHistorySong(history);
    return 0;
}