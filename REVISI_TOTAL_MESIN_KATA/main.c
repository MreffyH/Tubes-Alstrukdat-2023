#include <stdio.h>

/* Include ADT */
#include"mesinkarakter.h"
#include "mesinkata.h"

/* Include WayangWave */
#include"start.h"

int main(){
    boolean mulaiWayangWave = true;
    boolean dalamsesi = false;



    printf("\n-------SELAMAT DATANG DI PROGRAM WAYANGWAVE-------\n");
    while (mulaiWayangWave && dalamsesi == false)
    {   
        printf("\n");
        printf(">> ");
        STARTINPUT();
        printf("\n");
        if (INPUTEQUAL(currentInput, "START")) {
            printf("MASUK KE START\n");
            char *file = "user1.txt";
            STARTWAYANGWAVE(file);
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        } else if (INPUTEQUAL(currentInput, "LOAD")) {
            printf("MASUK KE LOAD\n");
        } else { /* BUAT YANG LAINNYA DAN INVALID COMMAND */
            printf("\n");
        }
    }
}