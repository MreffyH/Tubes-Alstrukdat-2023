#include <stdio.h>
#include "stdlib.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
// #include "save.c"

void quit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): "); 

    START(); // Memulai mesin karakter

    while (currentChar != ';') {
        IgnoreBlanks(); // Mengabaikan spasi

        currentWord.Length = 0;
        currentWord.TabWord[currentWord.Length++] = currentChar; // memasukkan currenchar ke tabword

        ADV(); //maju ke karakter selanjutnya
    }

    if ( currentWord.TabWord[0] == 'Y'){
        // save(); // memanggil save
        printf("save");
    }
    else{
        printf("Kamu keluar dari WayangWave\n");
        printf("Sampai bertemu lagii :)\n");
        exit(0); // keluar dari program
    }

}



