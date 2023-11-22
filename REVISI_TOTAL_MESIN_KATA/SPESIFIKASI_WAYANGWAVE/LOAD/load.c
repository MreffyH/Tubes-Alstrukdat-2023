/* File: load.c */
/*gcc -o load.c */
#include"load.h"
#include"stdio.h"
#include"stdlib.h"

void LOADWAYANGWAVE(ListPenyanyi*PL, char *filestart, QueueSong *QS, HistorySong *HS, ArrayDin *PLY) {
    STARTWAYANGWAVE(PL, filestart);
    // printf("\n");
    /* MASUK KE BAGIAN LOAD... LAGU YANG SEDANG DIMAINKAN */
    IgnoreEnter();
    ADVLOAD();
    if(isNotNone(kalimat)){
        // printf("LAGU YANG SEDANG DIMAINKAN\n");
        // printf("Artis : ");
        // printWord(kalimat);
        // printf("\n");
        ADVLOAD();
        // printf("Judul Album: ");
        // printWord(kalimat);
        // printf("\n");
        IgnoreEnter();
        ADVLOAD();
        // printf("Judul Lagu: ");
        // printWord(kalimat);
        // printf("\n");
    }
    else{
        printf("TIDAK ADA LAGU YANG SEDANG DIMAINKAN\n");
    }
    /* MASUK KE BAGIAN QUEUE */
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahlaguqueue = strToInteger(kalimat);
    // printf("Jumlah record lagu dalam queue: %d\n", jumlahlaguqueue);
    for(int i = 0; i < jumlahlaguqueue; i++){
        IgnoreEnter();
        ADVLOAD();
        // printf("QUEUE KE-%d\n", i+1);
        // printf("Artis : ");
        // printWord(kalimat);
        // printf("\n");
        Word PenyanyiQ = kalimat;
        ADVLOAD();
        // printf("Judul Album: ");
        // printWord(kalimat);
        // printf("\n");
        Word AlbumQ = kalimat;
        ADVLOAD();
        // printf("Judul Lagu: ");
        // printWord(kalimat);
        // printf("\n");
        Word LaguQ = kalimat;
        DetailSongQ tempQ;
        tempQ.namaPenyanyiQ = PenyanyiQ;
        tempQ.namaAlbumQ = AlbumQ;
        tempQ.namaLaguQ = LaguQ;
        enqueue(QS, tempQ);
    }
    /* MASUK KE BAGIAN RIWAYAT */
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahlaguriwayat = strToInteger(kalimat);
    // printf("Jumlah record riwayat pemutaran lagu: %d\n", jumlahlaguriwayat);
    for(int i = 0; i < jumlahlaguriwayat; i++){
        IgnoreEnter();
        ADVLOAD();
        // printf("RIWAYAT KE-%d\n", i+1);
        // printf("Artis : ");
        // printWord(kalimat);
        // printf("\n");
        Word PenyanyiS = kalimat;
        ADVLOAD();
        // printf("Judul Album: ");
        // printWord(kalimat);
        // printf("\n");
        Word AlbumS = kalimat;
        ADVLOAD();
        // printf("Judul Lagu: ");
        // printWord(kalimat);
        // printf("\n");
        Word LaguS = kalimat;
        DetailSongS tempS;
        tempS.namaPenyanyiS = PenyanyiS;
        tempS.namaAlbumS = AlbumS;
        tempS.namaLaguS = LaguS;
        Push(HS, tempS);
    }
    /* MASUK KE BAGIAN PLAYLIST */
    IsiPlaylist PLAYLIST1LOAD;
    
    IgnoreEnter();
    ADVSENTENCE();
    int jumlahplaylist = strToInteger(kalimat);
    printf("Jumlah playlist: %d", jumlahplaylist);
    if(jumlahplaylist != 0){
        printf("\n");
        IgnoreEnter();
    }
    for(int i = 0; i < jumlahplaylist; i++){
        CreateEmptyListLin(&PLAYLIST1LOAD.IsiLagu);
        printf("LOOP KE-%d\n", i+1);
        ADVWORD();
        int jumlahlaguplaylist = strToInteger(currentWord);
        PLAYLIST1LOAD.countlaguLL = jumlahlaguplaylist;
        printf("Jumlah lagu dalam playlist ke-%d: %d\n", i+1, PLAYLIST1LOAD.countlaguLL);
        ADVSENTENCE();
        printf("Judul playlist ke-%d: ", i+1);
        PLAYLIST1LOAD.nama_PlayList = kalimat;
        printWord(PLAYLIST1LOAD.nama_PlayList);
        if (jumlahlaguplaylist != 0){
            printf("\n");
            IgnoreEnter();
        }
        DetailSongLL BIOPLY;
        for(int j = 0; j < jumlahlaguplaylist; j++){
            printf("nilai j = %d\n", j);
            if((i == jumlahplaylist-1) && (j == jumlahlaguplaylist-1)){
                printf("CEK IF\n");
                ADVLOAD();
                // printf("Artis : ");
                // printWord(kalimat);
                // printf("\n");
                BIOPLY.namaPenyanyi = kalimat;
                ADVLOAD();
                // printf("Judul Album: ");
                // printWord(kalimat);
                // printf("\n");
                BIOPLY.namaAlbum = kalimat;
                ADVLOAD();
                // printf("Judul Lagu: ");
                // printWord(kalimat);
                BIOPLY.namaLagu = kalimat;
                InsVLast(&PLAYLIST1LOAD.IsiLagu, BIOPLY);

            }
            else{
                printf("CEK ELSE\n");
                ADVLOAD();
                // printf("Artis : ");
                // printWord(kalimat);
                // printf("\n");
                BIOPLY.namaPenyanyi = kalimat;
                printWord(BIOPLY.namaPenyanyi);
                printf("\n");
                ADVLOAD();
                // printf("Judul Album: ");
                // printWord(kalimat);
                // printf("\n");
                BIOPLY.namaAlbum = kalimat;
                printWord(BIOPLY.namaAlbum);
                printf("\n");
                ADVLOAD();
                // printf("Judul Lagu: ");
                // printWord(kalimat);
                // printf("\n");
                BIOPLY.namaLagu = kalimat;
                printWord(BIOPLY.namaLagu);
                printf("\n");
                printf("CEK SEBELUM INSERT: ");
                PrintInfoLL(PLAYLIST1LOAD.IsiLagu);
                InsVLast(&PLAYLIST1LOAD.IsiLagu, BIOPLY);
                printf("CEK ISI PLAYLIST: ");
                PrintInfoLL(PLAYLIST1LOAD.IsiLagu);
                printf("\n");
                IgnoreEnter();
            }
        }
        InsertLastArrayDin(PLY, PLAYLIST1LOAD);
        PrintArrayDin(*PLY);
    }
}