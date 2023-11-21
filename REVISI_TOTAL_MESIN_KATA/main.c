#include <stdio.h>

/* Include ADT */
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "../WayangWave/help.h"

/* Include WayangWave */
#include "start.h"

int main()
{
    boolean mulaiWayangWave = true;
    boolean dalamsesi = false;

    printf("\n-------SELAMAT DATANG DI PROGRAM WAYANGWAVE-------\n");
    while (mulaiWayangWave)
    {
        printf("\n");
        printf(">> ");
        STARTINPUT();
        printf("\n");
        if (INPUTEQUAL(currentInput, "START"))
        {
            printf("MASUK KE START\n");
            char *file = "user1.txt";
            STARTWAYANGWAVE(file);
            dalamsesi = true;
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
        else if (INPUTEQUAL(currentInput, "LOAD"))
        {
            printf("MASUK KE LOAD\n");
            dalamsesi = true;
        }
        else if ((INPUTEQUAL(currentInput, "HELP")) && dalamsesi == true)
        {
            helpAfter();
            printf("berhasil fungsi help after\n");
        }
        else if ((INPUTEQUAL(currentInput, "HELP")) && dalamsesi == false)
        {
            helpBefore();
            printf("berhasil fungsi help after\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG")) && dalamsesi == true)
        {
            /*masukin fungsi PLAY SONG*/
            printf("Masuk ke PLAY SONG")
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG")) && dalamsesi == false){
    }
}