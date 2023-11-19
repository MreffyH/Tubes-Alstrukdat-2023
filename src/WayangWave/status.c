#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur lagu
typedef struct {
    char title[100];
    char album[100];
    char artist[100];
} Song;

// Definisi struktur node untuk queue
typedef struct QueueNode {
    Song song;
    struct QueueNode* next;
} QueueNode;

// Definisi struktur untuk queue
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Definisi struktur untuk playlist
typedef struct {
    char name[100];
    Queue songs; // Misalnya, playlist menggunakan queue juga untuk menyimpan lagu
} Playlist;

// Global variables untuk Now Playing dan Playlist saat ini
Song nowPlaying;
Playlist currentPlaylist;
int isPlaylistActive = 0;

// Fungsi untuk menampilkan status
void printStatus(Queue* queue) {
    if (isPlaylistActive) {
        printf("\nCurrent Playlist: %s\n", currentPlaylist.name);
    }

    printf("Now Playing:\n");
    if (strlen(nowPlaying.title) == 0) {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    } else {
        printf("%s - %s - %s\n", nowPlaying.artist, nowPlaying.title, nowPlaying.album);
    }

    printf("\nQueue:\n");
    if (queue->front == NULL) {
        printf("Your queue is empty.\n");
    } else {
        QueueNode* temp = queue->front;
        int count = 1;
        while (temp != NULL) {
            printf("%d. %s - %s - %s\n", count, temp->song.artist, temp->song.title, temp->song.album);
            temp = temp->next;
            count++;
        }
    }


}

// Fungsi utama
int main() {
    Queue queue = {NULL, NULL}; // Inisialisasi queue kosong

    // Contoh penggunaan
    strcpy(nowPlaying.title, "Up&Up");
    strcpy(nowPlaying.artist, "Coldplay");
    strcpy(nowPlaying.album, "A Head Full of Dreams");

    // Contoh menambahkan lagu ke queue
    // ... (kode untuk menambahkan lagu ke queue)

    // Contoh menetapkan playlist aktif
    isPlaylistActive = 1;
    strcpy(currentPlaylist.name, "Copium");

    // Menampilkan status
    printStatus(&queue);

    return 0;
}