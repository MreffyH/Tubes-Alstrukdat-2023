#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Gagal membuka file.\n");
        return;
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
    // Contoh penggunaan fungsi
    Song queue[] = {/* isi dengan data queue */};
    int queueSize = sizeof(queue) / sizeof(queue[0]);

    Song history[] = {/* isi dengan data riwayat */};
    int historySize = sizeof(history) / sizeof(history[0]);

    Song* playlists[] = {/* isi dengan data playlist */};
    int playlistSizes[] = {/* isi dengan jumlah lagu di tiap playlist */};
    int numPlaylists = sizeof(playlists) / sizeof(playlists[0]);

    saveToFile("/save/savefile.txt", queue, queueSize, history, historySize, playlists, playlistSizes, numPlaylists);

    return 0;
}