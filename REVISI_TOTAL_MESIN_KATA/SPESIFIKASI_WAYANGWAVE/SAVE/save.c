#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "save.h"

// Struktur untuk menyimpan informasi lagu
// typedef struct {
//     char artist[100];
//     char album[100];
//     char title[100];
// } Song;

// Fungsi untuk menyimpan file
void SAVEWAYANGWAVE(ListPenyanyi *PL, char *filesave, QueueSong *QS, HistorySong *HS, ArrayDin *PLY, DetailSongQ *currentSong) {
    FILE *file = fopen(filesave, "w");
    if (file == NULL) {
        // Contoh data lagu
    
    START(); // Memulai mesin karakter

    // Membaca karakter hingga bertemu dengan ';'
    while (currentChar != ';') {
        // Mengabaikan spasi jika perlu
        // IgnoreBlanks(); 

        currentWord.Length = 0;

        // Membaca satu kata (sampai bertemu ';')
        while (currentChar != ';' && !IsEOP()) {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV(); // Maju ke karakter selanjutnya
        }

        // Menambahkan null-terminator pada akhir kata
        currentWord.TabWord[currentWord.Length] = '\0';
        
    }
    }

    // Menulis informasi ke file
    
    // Menulis informasi lagu yang sedang diputar
    fprintf(file, "%s;%s;%s\n", currentSong[0].namaPenyanyiQ, currentSong[0].namaAlbumQ, currentSong[0].namaLaguQ);

    // Menulis queue
    fprintf(file, "%d\n", QS);
    for (int i = 0; i < QS; i++) {
        fprintf(file, "%s;%s;%s\n", currentSong[i].namaPenyanyiQ, currentSong[i].namaAlbumQ, currentSong[i].namaLaguQ);
    }

    // Menulis riwayat pemutaran
    fprintf(file, "%d\n", HS);
    for (int i = 0; i < HS; i++) {
        fprintf(file, "%s;%s;%s\n", currentSong[i].namaPenyanyiQ, currentSong[i].namaAlbumQ, currentSong[i].namaLaguQ);
    }

    // Menulis playlists
    int playlistSizes;
    playlistSizes = GetCapacity(*PLY);
    fprintf(file, "%d\n", PLY);
    for (int i = 0; i < PLY; i++) {
        fprintf(file, "%d Playlist %d\n", playlistSizes[i], i + 1);
        for (int j = 0; j < playlistSizes[i]; j++) {
            fprintf(file, "%s;%s;%s\n", PLY[i][j].artist, playlists[i][j].album, playlists[i][j].title);
        }
    }

    fclose(file);
    printf("File berhasil disimpan.\n");
}

// int main() {
//     Song queue[] = {{"JKT48", "Mahagita Vol.2", "Jiwaru Days"}, {"JKT48", "Mahagita Vol.2", "Ingin Bertemu"}};
//     int queueSize = sizeof(queue) / sizeof(queue[0]);

//     Song history[] = {{"JKT48", "Mahagita Vol.2", "Seventeen"}, {"JKT48", "Mahagita Vol.2", "Better"}};
//     int historySize = sizeof(history) / sizeof(history[0]);

//     int numPlaylists = 2;
//     int playlistSizes[] = {3, 2}; // Jumlah lagu dalam setiap playlist

//     Song* playlists[2];
//     playlists[0] = (Song[]) {{"JKT48", "Pajama Drive", "Jurus Rahasia Teleport"}, {"JKT48", "Pajama Drive", "Bersepeda Berdua"}, {"JKT48", "Pajama Drive", "Ekor Malaikat"}};
//     playlists[1] = (Song[]) {{"JKT48", "Aturan Anti Cinta", "Jatuh Cinta Setiap Bertemu"}, {"JKT48", "Aturan Anti Cinta", "Virus Tipe Hati"}};

//     saveToFile(currentWord.TabWord, queue, queueSize, history, historySize, playlists, playlistSizes, numPlaylists);

//     return 0;
// }