#include <stdio.h>

void helpBefore(){
    printf("===============[ Menu Help WayangWave ]===============\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("======================================================\n");
}

void helpAfter(){
    printf("===============[ Menu Help WayangWave ]===============\n");
    printf("1. LIST -> Untuk menampilkan list playlist yang ada, list penyanyi, list album dari penyanyi, dan list lagu yang ada di album\n");
    printf("   -----Jenis command-----\n");
    printf("   1.a. LIST DEFAULT -> untuk melihat list penyanyi yang ada\n");
    printf("   1.b. LIST PLAYLIST -> untuk menampilkan playlist yang ada\n");
    printf("2. PLAY -> Untuk memutar lagu atau playlist yang dipilih\n");
    printf("   -----Jenis command-----\n");
    printf("   2.a. PLAY SONG - untuk melihat list penyanyi yang ada\n");
    printf("   2.b. PLAY PLAYLIST - untuk melihat list penyanyi yang ada\n");   
    printf("3. QUEUE -> Untuk memanipulasi queue lagu\n");
    printf("   -----Jenis command-----\n");
    printf("   3.a. QUEUE SONG -> untuk menambahkan lagu ke dalam queue\n");
    printf("   3.b. QUEUE PLAYLIST -> untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
    printf("   3.c. QUEUE SWAP <x> <y> -> untuk menukar lagu pada urutan ke x dan juga urutan ke y\n");  
    printf("   3.d. QUEUE REMOVE <id> -> untuk menghapus lagu dari queue\n");
    printf("   3.e. QUEUE CLEAR -> untuk mengosongkan queue\n");  
    printf("4. SONG -> untuk navigasi lagu yang ada pada queue lagu\n");
    printf("   -----Jenis command-----\n");
    printf("   4.a. SONG NEXT -> untuk memutar lagu yang berada di dalam queue\n");  
    printf("   4.b. SONG PREVIOUS -> untuk memutar lagu yang terakhir kali diputar\n");  
    printf("5. PLAYLIST -> untuk melakukan basic command untuk playlist\n");
    printf("   -----Jenis command-----\n");
    printf("   5.a. PLAYLIST CREATE -> untuk membuat playlist baru dan ditambahkan pada daftar playlist\n");  
    printf("   5.b. PLAYLIST ADD -> untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist\n");  
    printf("   5.c. PLAYLIST SWAP <id> <x> <y> -> untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id\n");  
    printf("   5.d. PLAYLIST REMOVE <id> <n> -> untuk menghapus lagu dengan urutan n pada playlist dengan index id\n");  
    printf("   5.e. PLAYLIST DELETE -> untuk melakukan penghapusan suatu existing playlist dalam daftar playlist \n");  
    printf("6. STATUS -> untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n");
    printf("7. SAVE -> untuk menyimpan state aplikasi terbaru ke dalam suatu file\n");
    printf("8. QUIT -> untuk keluar dari sesi aplikasi WayangWave\n");
    printf("======================================================\n");   

}

