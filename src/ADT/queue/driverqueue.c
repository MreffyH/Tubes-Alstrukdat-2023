#include <stdio.h>
#include "queue.h"

int main(){
    printf("MILESTONE1\n");
    QueueSong QueueTest;
    CreateEmptyQueue(&QueueTest);
    printf("IDXHEAD: %d ; IDXTAIL: %d ; LENGTH: %d\n", IDX_HEAD(QueueTest), IDX_TAIL(QueueTest), length(QueueTest));
    printf("MILESTONE2\n");
    DetailSongQ song1;
    Word kalimat;
    kalimat.TabWord[0] = 'J';
    kalimat.TabWord[1] = 'K';
    kalimat.TabWord[2] = 'T';
    kalimat.TabWord[3] = '4';
    kalimat.TabWord[4] = '8';
    kalimat.Length = 5;
    song1.namaPenyanyiQ = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'S';
    kalimat.TabWord[1] = 'n';
    kalimat.TabWord[2] = 'M';
    kalimat.Length = 3;
    song1.namaAlbumQ = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'T';
    kalimat.TabWord[1] = 'u';
    kalimat.TabWord[2] = 'n';
    kalimat.TabWord[3] = 'a';
    kalimat.TabWord[4] = 's';
    kalimat.Length = 5;
    song1.namaLaguQ = DuplicateKata(kalimat);
    printf("NAMA PENYANYI: ");
    printWord(song1.namaPenyanyiQ);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(song1.namaAlbumQ);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(song1.namaLaguQ);
    printf("\n");
    printf("MILESTONE3\n");
    enqueue(&QueueTest,song1);
    printf("TEST DALAM QUEUENYA\n");
    printf("NAMA PENYANYI: ");
    printWord(QueueTest.detil_queue[0].namaPenyanyiQ);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(QueueTest.detil_queue[0].namaAlbumQ);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(QueueTest.detil_queue[0].namaLaguQ);
    printf("\n");
    printf("IDXHEAD: %d ; IDXTAIL: %d ; LENGTH: %d\n", IDX_HEAD(QueueTest), IDX_TAIL(QueueTest), length(QueueTest));
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
    song1.namaPenyanyiQ = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'L';
    kalimat.TabWord[1] = 'o';
    kalimat.TabWord[2] = 'v';
    kalimat.TabWord[3] = 'e';
    kalimat.Length = 4;
    song1.namaAlbumQ = DuplicateKata(kalimat);
    kalimat.TabWord[0] = 'P';
    kalimat.TabWord[1] = 'e';
    kalimat.TabWord[2] = 'r';
    kalimat.TabWord[3] = 'i';
    kalimat.TabWord[4] = 'h';
    kalimat.Length = 5;
    song1.namaLaguQ = DuplicateKata(kalimat);
    printf("NAMA PENYANYI: ");
    printWord(song1.namaPenyanyiQ);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(song1.namaAlbumQ);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(song1.namaLaguQ);
    printf("\n");
    enqueue(&QueueTest,song1);
    printf("TEST DALAM QUEUENYA\n");
    printf("NAMA PENYANYI: ");
    printWord(QueueTest.detil_queue[1].namaPenyanyiQ);
    printf("\n");
    printf("NAMA ALBUM: ");
    printWord(QueueTest.detil_queue[1].namaAlbumQ);
    printf("\n");
    printf("NAMA LAGU: ");
    printWord(QueueTest.detil_queue[1].namaLaguQ);
    printf("\n");
    printf("IDXHEAD: %d ; IDXTAIL: %d ; LENGTH: %d\n", IDX_HEAD(QueueTest), IDX_TAIL(QueueTest), length(QueueTest));
    printf("MILESTONE4\n");
    // DetailSongQ song2;
    // dequeue(&QueueTest, &song2);
    // printf("NAMA PENYANYI: ");
    // printWord(song2.namaPenyanyi);
    // printf("\n");
    // printf("NAMA ALBUM: ");
    // printWord(song2.namaAlbum);
    // printf("\n");
    // printf("NAMA LAGU: ");
    // printWord(song2.namaLagu);
    // printf("\n");
    // printf("IDXHEAD: %d ; IDXTAIL: %d ; LENGTH: %d\n", IDX_HEAD(QueueTest), IDX_TAIL(QueueTest), length(QueueTest));
    displayQueue(QueueTest);
    return 0;
}