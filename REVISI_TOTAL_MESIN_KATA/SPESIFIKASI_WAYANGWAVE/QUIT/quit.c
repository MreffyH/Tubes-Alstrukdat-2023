#include <stdio.h>
#include "stdlib.h"
#include "quit.h"
// #include "save.c"

void quit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N): "); 
    STARTINPUT();

    if ( INPUTEQUAL(currentInput,"Y;")){
        // save(); // memanggil save
        printf("save");
    }
    else if (INPUTEQUAL(currentInput,"N;")){
        printf("================Kamu keluar dari WayangWave================\n");
        printf("  _____  ____  __ __   ___   ____    ____  ____    ____    \n");
        printf(" / ___/ /    ||  |  | /   \\ |    \\  /    ||    \\  /    |\n");
        printf("(   \\_ |  o  ||  |  ||     ||  _  ||  o  ||  D  )|  o  |  \n");
        printf(" \\__  ||     ||  ~  ||  O  ||  |  ||     ||    / |     |  \n");
        printf(" /  \\ ||  _  ||___, ||     ||  |  ||  _  ||    \\ |  _  | \n");
        printf(" \\    ||  |  ||     ||     ||  |  ||  |  ||  .  \\|  |  | \n");
        printf("  \\___||__|__||____/  \\___/ |__|__||__|__||__|\\_||__|__|\n");
        printf("\n=========================================================\n");
        exit(0); // keluar dari program
    }
    else{
        printf("Command tidak diketahui!\n");
    }
}