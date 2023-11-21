#include <stdio.h>

/* Include ADT */
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "../src/WayangWave/help.h"

/* Include WayangWave */
#include "start.h"
#include "load.h"
#include "quit.h"

int main()
{
    boolean mulaiWayangWave = true;
    boolean dalamsesi = false;

    printf("\n-------------------SELAMAT DATANG DI PROGRAM WAYANGWAVE-------------------\n");
    printf(" __    __   ____  __ __   ____  ____    ____  __    __   ____  __ __    ___      \n");
    printf("|  |__|  | /    ||  |  | /    ||    \\  /    ||  |__|  | /    ||  |  |  /  _]    \n");
    printf("|  |  |  ||  o  ||  |  ||  o  ||  _  ||   __||  |  |  ||  o  ||  |  | /  [_      \n");
    printf("|  |  |  ||     ||  ~  ||     ||  |  ||  |  ||  |  |  ||     ||  |  ||    _]     \n");
    printf("|  `  '  ||  _  ||___, ||  _  ||  |  ||  |_ ||  `  '  ||  _  ||  :  ||   [_      \n");
    printf(" \\      / |  |  ||     ||  |  ||  |  ||     | \\      / |  |  | \\   / |     |  \n");
    printf("  \\_/\\_/  |__|__||____/ |__|__||__|__||___,_|  \\_/\\_/  |__|__|  \\_/  |_____|\n");
    while (mulaiWayangWave) 
    {
        printf("\n");
        printf(">> ");
        STARTINPUT();
        printf("\n");
        
        if ((INPUTEQUAL(currentInput, "START;")) && dalamsesi == false)
        {
            printf("MASUK KE START\n");
            char *file = "config.txt";
            STARTWAYANGWAVE(file);
            dalamsesi = true;
            printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
        else if ((INPUTEQUAL(currentInput, "START;")) && dalamsesi == true)
        {
            printf("Wayangwave telah berjalan, silahkan masukkan command");
        }
        else if (INPUTEQUAL(currentInput, "LOAD;") && dalamsesi == false)
        {
            printf(">> ");
            STARTINPUT();
            Word file = currentInput;
            LOADWAYANGWAVE(file.TabWord);
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
            dalamsesi = true;
        }
        else if ((INPUTEQUAL(currentInput, "LOAD;")) && dalamsesi == true)
        {
            printf("Wayangwave telah berjalan, silahkan masukkan command");
        }
        else if ((INPUTEQUAL(currentInput, "HELP;")) && dalamsesi == true)
        {
            helpAfter();
            printf("berhasil fungsi help after\n");
        }
        else if ((INPUTEQUAL(currentInput, "HELP;")) && dalamsesi == false)
        {
            helpBefore();
            printf("berhasil fungsi help before\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAY SONG*/
            printf("Masuk ke PLAY SONG");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAY PLAYLIST*/
            printf("Masuk ke PLAY PLAYLIST");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE;")) && dalamsesi == true)
        {
            /*masukin fungsi QUEUE*/
            printf("Masuk ke QUEUE");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS;")) && dalamsesi == true)
        {
            /*masukin fungsi STATUS*/
            printf("Masuk ke STATUS");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE;")) && dalamsesi == true)
        {
            /*masukin fungsi SAVE*/
            printf("Masuk ke SAVE");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }  
        else if ((INPUTEQUAL(currentInput, "LIST DEFAULT;")) && dalamsesi == true)
        {
            /*masukin fungsi LIST DEFAULT*/
            printf("Masuk ke LIST DEFAULT");
        }
        else if ((INPUTEQUAL(currentInput, "LIST DEFAULT;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "LIST PLAYLIST;")) && dalamsesi == true)
        {
            /*masukin fungsi LIST PLAYLIST*/
            printf("Masuk ke LIST PLAYLIST");
        }
        else if ((INPUTEQUAL(currentInput, "LIST PLAYLIST;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG NEXT;")) && dalamsesi == true)
        {
            /*masukin fungsi SONG NEXT*/
            printf("Masuk ke SONG NEXT");
        }
        else if ((INPUTEQUAL(currentInput, "SONG NEXT;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG PREVIOUS;")) && dalamsesi == true)
        {
            /*masukin fungsi SONG PREVIOUS*/
            printf("Masuk ke SONG PREVIOUS");
        }
        else if ((INPUTEQUAL(currentInput, "SONG PREVIOUS;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST CREATE;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST CREATE*/
            printf("Masuk ke PLAYLIST CREATE");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST CREATE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD SONG;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST ADD*/
            printf("Masuk ke PLAYLIST ADD SONG");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD SONG;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD ALBUM;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST ADD*/
            printf("Masuk ke PLAYLIST ADD ALBUM");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD ALBUM;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST SWAP;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST ADD*/
            printf("Masuk ke PLAYLIST ADD");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST SWAP;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }      
        else if ((INPUTEQUAL(currentInput, "PLAYLIST REMOVE;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST REMOVE*/
            printf("Masuk ke PLAYLIST REMOVE");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST REMOVE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }      
        else if ((INPUTEQUAL(currentInput, "PLAYLIST DELETE;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST DELETE*/
            printf("Masuk ke PLAYLIST DELETE");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST DELETE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }      
        else if ((INPUTEQUAL(currentInput, "QUIT;")) && dalamsesi == true)
        {
            quit();
        }
        else if ((INPUTEQUAL(currentInput, "QUIT;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }      
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }
}