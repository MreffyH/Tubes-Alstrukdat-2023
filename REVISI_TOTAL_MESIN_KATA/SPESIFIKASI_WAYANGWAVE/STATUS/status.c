#include <stdio.h>
#include <stdlib.h>
#include "status.h"

// gcc -o status status.c ../../listmapset.c

// Definisi struktur lagu
// typedef struct {
//     char *title;
//     char *album;
//     char *artist;
// } Song;

// Definisi struktur node untuk queue
typedef struct QueueNode {
    DetailSongLL song;
    struct QueueNode* next;
} QueueNode;

typedef struct 
{
    DetailSongLL detsong;
    int statussong;
    Word namaplaylist;
}Status; 

// Definisi struktur untuk queue
// typedef struct {
//     QueueNode* front;
//     QueueNode* rear;
// } Queue;

// Definisi struktur untuk playlist
// typedef struct {
//     char *name;
//     Queue songs; // Misalnya, playlist menggunakan queue juga untuk menyimpan lagu
// } Playlist;

// Global variables untuk Now Playing dan Playlist saat ini
int isPlaylistActive = 1;

// Fungsi untuk menampilkan status
void printStatus(QueueSong queuestatus, DetailSongQ nowPlaying, ArrayDin playlist) {
    IsiPlaylist currentplaylist;
    if (isPlaylistActive = 1) {
        printf("Current Playlist: %s\n", currentplaylist.nama_PlayList);
        printf("\n");
    }

    printf("Now Playing:\n");
    if (!isNotNone(nowPlaying.namaLaguQ)) {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    } else {
        printf("%s - %s - %s\n", nowPlaying.namaPenyanyiQ.TabWord, nowPlaying.namaLaguQ.TabWord, nowPlaying.namaAlbumQ.TabWord);
    }

    printf("\nQueue:\n");
    if (isEmptyQ(queuestatus)) {
        printf("Your queue is empty.\n");
    } else {
        QueueNode *temp = IDX_HEAD(queuestatus);
        int count = 1;
        while (temp != NULL) {
            printf("%d. %s - %s - %s\n", count, temp->song.namaPenyanyi, temp->song.namaLagu, temp->song.namaAlbum);
            temp = Next(temp);
            count++;
        }
    }
}

// Fungsi untuk membuat lagu baru dengan string baru
// Song createSong(char *title, char *artist, char *album) {
//     Song newSong;
//     newSong.title = title;
//     newSong.artist = artist;
//     newSong.album = album;
//     return newSong;
// }

// Fungsi untuk menambahkan lagu ke dalam queue
// void enqueue(Queue *queue, Song newSong) {
//     QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
//     if (newNode == NULL) {
//         printf("Memory allocation failed!\n");
//         return;
//     }
//     newNode->song = newSong;
//     newNode->next = NULL;

//     if (queue->rear == NULL) {
//         queue->front = queue->rear = newNode;
//     } else {
//         queue->rear->next = newNode;
//         queue->rear = newNode;
//     }
// }

// Fungsi utama
// int main() {
//     Queue queue = {NULL, NULL}; // Inisialisasi queue kosong

    // Contoh penggunaan
    // nowPlaying = createSong("Up&Up", "Coldplay", "A Head Full of Dreams");

    // Contoh menambahkan lagu ke queue
    // Song newSong1 = createSong("Jiwaru Days", "JKT48", "Mahagita Vol.2");
    // enqueue(&queue, newSong1);

    // Song newSong2 = createSong("Jurus Rahasia Teleport", "JKT48", "Pajama Drive");
    // enqueue(&queue, newSong2);

    // Contoh menetapkan playlist aktif
    // isPlaylistActive = 2;
    // currentPlaylist.name = "Copium";
    // currentPlaylist.name = "Pajama Drive";

    // Menampilkan status
    // printStatus(&queue);

    // return 0;
// }