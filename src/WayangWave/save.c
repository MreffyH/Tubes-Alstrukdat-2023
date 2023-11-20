#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

// Struktur untuk menyimpan informasi lagu
typedef struct {
    char artist[100];
    char album[100];
    char title[100];
} Song;

// Fungsi untuk menyimpan file
void saveToFile(const char* filename, Song* queue, int queueSize, Song* history, int historySize, Song** playlists, int* playlistSizes, int numPlaylists) {
    FILE *file = fopen(filename, "w");
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
    fprintf(file, "%s;%s;%s\n", queue[0].artist, queue[0].album, queue[0].title);

    // Menulis queue
    fprintf(file, "%d\n", queueSize);
    for (int i = 0; i < queueSize; i++) {
        fprintf(file, "%s;%s;%s\n", queue[i].artist, queue[i].album, queue[i].title);
    }

    // Menulis riwayat pemutaran
    fprintf(file, "%d\n", historySize);
    for (int i = 0; i < historySize; i++) {
        fprintf(file, "%s;%s;%s\n", history[i].artist, history[i].album, history[i].title);
    }

    // Menulis playlists
    fprintf(file, "%d\n", numPlaylists);
    for (int i = 0; i < numPlaylists; i++) {
        fprintf(file, "%d Playlist %d\n", playlistSizes[i], i + 1);
        for (int j = 0; j < playlistSizes[i]; j++) {
            fprintf(file, "%s;%s;%s\n", playlists[i][j].artist, playlists[i][j].album, playlists[i][j].title);
        }
    }

    fclose(file);
    printf("File berhasil disimpan.\n");
}

int main() {
    Song queue[] = {{"JKT48", "Mahagita Vol.2", "Jiwaru Days"}, {"JKT48", "Mahagita Vol.2", "Ingin Bertemu"}};
    int queueSize = sizeof(queue) / sizeof(queue[0]);

    Song history[] = {{"JKT48", "Mahagita Vol.2", "Seventeen"}, {"JKT48", "Mahagita Vol.2", "Better"}};
    int historySize = sizeof(history) / sizeof(history[0]);

    int numPlaylists = 2;
    int playlistSizes[] = {3, 2}; // Jumlah lagu dalam setiap playlist

    Song* playlists[2];
    playlists[0] = (Song[]) {{"JKT48", "Pajama Drive", "Jurus Rahasia Teleport"}, {"JKT48", "Pajama Drive", "Bersepeda Berdua"}, {"JKT48", "Pajama Drive", "Ekor Malaikat"}};
    playlists[1] = (Song[]) {{"JKT48", "Aturan Anti Cinta", "Jatuh Cinta Setiap Bertemu"}, {"JKT48", "Aturan Anti Cinta", "Virus Tipe Hati"}};

    saveToFile(currentWord.TabWord, queue, queueSize, history, historySize, playlists, playlistSizes, numPlaylists);

    return 0;
}