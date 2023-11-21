#include <stdio.h>

/* Include ADT */
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "../WayangWave/help.h"

/* Include WayangWave */
#include "start.h"
#include "load.h"

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
            STARTINPUT();
            Word file = currentInput;
            LOADWAYANGWAVE(file.TabWord);
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
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
            printf("Masuk ke PLAY SONG");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG")) && dalamsesi == false)
        {
            printf("silahkan input START terlebih dahulu");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST")) && dalamsesi == true)
        {
            /*masukin fungsi PLAY PLAYLIST*/
            printf("Masuk ke PLAY PLAYLIST");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST")) && dalamsesi == false)
        {
            printf("silahkan input START terlebih dahulu");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE")) && dalamsesi == true)
        {
            /*masukin fungsi QUEUE*/
            printf("Masuk ke QUEUE");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE")) && dalamsesi == false)
        {
            printf("silahkan input START terlebih dahulu");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS")) && dalamsesi == true)
        {
            /*masukin fungsi STATUS*/
            printf("Masuk ke STATUS");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS")) && dalamsesi == false)
        {
            printf("silahkan input START terlebih dahulu");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE")) && dalamsesi == true)
        {
            /*masukin fungsi SAVE*/
            printf("Masuk ke SAVE");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE")) && dalamsesi == false)
        {
            printf("silahkan input START terlebih dahulu");
        }        
    }
}