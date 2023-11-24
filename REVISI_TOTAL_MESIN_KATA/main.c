// gcc -o main main.c mesinkarakter.c mesinkata.c ADT_WAYANGWAVE/QUEUE/queue.c SPESIFIKASI_WAYANGWAVE/PLAYLIST/playlist.C ADT_WAYANGWAVE/STACK/stack.c SPESIFIKASI_WAYANGWAVE/HELP/help.c SPESIFIKASI_WAYANGWAVE/START/start.c SPESIFIKASI_WAYANGWAVE/LOAD/load.c SPESIFIKASI_WAYANGWAVE/QUIT/quit.c listmapset.c ../src/ADT/mapset/set.c SPESIFIKASI_WAYANGWAVE/FUNGSI_LIST/ladt.c SPESIFIKASI_WAYANGWAVE/PLAY/play.c ../RIvaldi/arraydin.c ../src/ADT/list/listlinier.c SPESIFIKASI_WAYANGWAVE/SONG/song.c SPESIFIKASI_WAYANGWAVE/FUNGSI_QUEUE/QUEUE_WW.c

#include <stdio.h>

/* Include ADT */
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "listmapset.h"
#include "../src/ADT/mapset/set.h"
#include "ADT_WAYANGWAVE/QUEUE/queue.h"
#include "ADT_WAYANGWAVE/STACK/stack.h"
#include "../RIvaldi/arraydin.h"

/* Include WayangWave */
#include "SPESIFIKASI_WAYANGWAVE/START/start.h"
#include "SPESIFIKASI_WAYANGWAVE/LOAD/load.h"
#include "SPESIFIKASI_WAYANGWAVE/HELP/help.h"
#include "SPESIFIKASI_WAYANGWAVE/QUIT/quit.h"
#include "SPESIFIKASI_WAYANGWAVE/FUNGSI_LIST/ladt.h"
#include "SPESIFIKASI_WAYANGWAVE/PLAY/play.h"
#include "SPESIFIKASI_WAYANGWAVE/SONG/song.h"
#include "SPESIFIKASI_WAYANGWAVE/FUNGSI_QUEUE/QUEUE_WW.H"
#include "SPESIFIKASI_WAYANGWAVE/PLAYLIST/playlist.h"

int main()
{
    boolean mulaiWayangWave = true;
    boolean dalamsesi = false;

    Set S;
    CreateEmptySet(&S);

    MapAlbum MA;
    CreateMapAlbum(&MA, S);

    MapPenyanyi MP;
    CreateMapPenyanyi(&MP, MA);

    ListPenyanyi PL;
    CreateListPenyanyi(&PL, MP);

    DetailSongQ currentSong;

    QueueSong QS;
    CreateEmptyQueue(&QS);

    HistorySong HS;
    CreateEmptyHistorySong(&HS);

    ArrayDin PLY;
    PLY = MakeArrayDin();

    printf("\n======================SELAMAT DATANG DI PROGRAM WAYANGWAVE======================\n");
    printf(" __    __   ____  __ __   ____  ____    ____  __    __   ____  __ __    ___       \n");
    printf("|  |__|  | /    ||  |  | /    ||    \\  /    ||  |__|  | /    ||  |  |  /  _]     \n");
    printf("|  |  |  ||  o  ||  |  ||  o  ||  _  ||   __||  |  |  ||  o  ||  |  | /  [_       \n");
    printf("|  |  |  ||     ||  ~  ||     ||  |  ||  |  ||  |  |  ||     ||  |  ||    _]      \n");
    printf("|  `  '  ||  _  ||___, ||  _  ||  |  ||  |_ ||  `  '  ||  _  ||  :  ||   [_       \n");
    printf(" \\      / |  |  ||     ||  |  ||  |  ||     | \\      / |  |  | \\   / |     |   \n");
    printf("  \\_/\\_/  |__|__||____/ |__|__||__|__||___,_|  \\_/\\_/  |__|__|  \\_/  |_____| \n");
    printf("\n================================================================================\n");
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
            STARTWAYANGWAVE(&PL, file);
            // printf("\n");

            // DISPLAYPENYANYI(PL);

            // DISPLAYALBUM(PL);

            // DISPLAYLAGU(PL);
            dalamsesi = true;
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
        else if ((INPUTEQUAL(currentInput, "START;")) && dalamsesi == true)
        {
            printf("Wayangwave telah berjalan, silahkan masukkan command\n");
        }
        else if (INPUTEQUAL(currentInput, "LOAD;") && dalamsesi == false)
        {
            printf("LOAD ");
            STARTINPUT();
            Word file = currentInput;
            
            LOADWAYANGWAVE(&PL, file.TabWord, &QS, &HS, &PLY, &currentSong);
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
            dalamsesi = true;
        }
        else if ((INPUTEQUAL(currentInput, "LOAD;")) && dalamsesi == true)
        {
            printf("Wayangwave telah berjalan, silahkan masukkan command\n");
        }
        else if ((INPUTEQUAL(currentInput, "HELP;")) && dalamsesi == true)
        {
            helpAfter();
        }
        else if ((INPUTEQUAL(currentInput, "HELP;")) && dalamsesi == false)
        {
            helpBefore();
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG;")) && dalamsesi == true)
        {
            PLAYSONG(PL, PLY, &currentSong, &HS, &QS);
        }
        else if ((INPUTEQUAL(currentInput, "PLAY SONG;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAY PLAYLIST*/
            playPlaylist(PLY, &currentSong, &HS, &QS);
        }
        else if ((INPUTEQUAL(currentInput, "PLAY PLAYLIST;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE SONG;")) && dalamsesi == true)
        {
            QUEUESONG(PL, &QS);
            // printf("Masuk Prints Song.");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE SONG;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE PLAYLIST;")) && dalamsesi == true) 
        {
            QUEUEPLAYLIST(&QS, PLY);
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE PLAYLIST;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE CLEAR;")) && dalamsesi == true) 
        {
            QUEUECLEAR(&QS);
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE CLEAR;")) && dalamsesi == false) 
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE REMOVE;")) && dalamsesi == true) 
        {
            // Perlu diedit lagi
            int IDX;
            IDX = strToInteger(currentInput);
            QUEUEREMOVE(&QS, IDX);
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE REMOVE;")) && dalamsesi == false) 
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE SWAP;")) && dalamsesi == true)
        {
            // Perlu diedit lagi
            int IDX1Q, IDX2Q;
            IDX1Q = strToInteger(currentInput);
            IDX2Q = strToInteger(currentInput);
            QUEUESWAP(&QS, IDX1Q, IDX2Q);
        }
        else if ((INPUTEQUAL(currentInput, "QUEUE SWAP;")) && dalamsesi == false) 
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS")) && dalamsesi == true)
        {
            /*masukin fungsi STATUS*/
            printf("Masuk ke STATUS\n");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE")) && dalamsesi == true)
        {
            /*masukin fungsi SAVE*/
            printf("Masuk ke SAVE\n");
        }
        else if ((INPUTEQUAL(currentInput, "SAVE")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "LIST DEFAULT;")) && dalamsesi == true)
        {
            LISTDEFAULT(PL);
        }
        else if ((INPUTEQUAL(currentInput, "LIST DEFAULT;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "LIST PLAYLIST;")) && dalamsesi == true)
        {
            /*masukin fungsi LIST PLAYLIST*/
            LISTPLAYLIST(PLY);
        }
        else if ((INPUTEQUAL(currentInput, "LIST PLAYLIST;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG NEXT;")) && dalamsesi == true)
        {
            songNext(&QS, &HS, &currentSong);
            // printf("Masuk ke SONG NEXT\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG NEXT;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG PREVIOUS;")) && dalamsesi == true)
        {
            songPrevious(&QS, &HS, &currentSong);
            // printf("Masuk ke SONG PREVIOUS\n");
        }
        else if ((INPUTEQUAL(currentInput, "SONG PREVIOUS;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST CREATE;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST CREATE*/
            CreatePlaylist(&PLY);
            // printf("Masuk ke PLAYLIST CREATE\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST CREATE;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD SONG;")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST ADD*/
            PlaylistADDSong(&PLY, PL);
            printf("Masuk ke PLAYLIST ADD SONG\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD SONG;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD ALBUM")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST ADD*/
            PlaylistADDAlbum(&PLY, PL);
            printf("Masuk ke PLAYLIST ADD ALBUM\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST ADD ALBUM")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST SWAP")) && dalamsesi == true)
        {
            // Perlu diedit lagi
            int IDXPS, IDX1PS, IDX2PS;
            IDXPS = strToInteger(currentInput);
            IDX1PS = strToInteger(currentInput);
            IDX2PS = strToInteger(currentInput);
            PlaylistSwap(&PLY, IDXPS, IDX1PS, IDX2PS);
            // printf("Masuk ke PLAYLIST ADD\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST SWAP")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST REMOVE")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST REMOVE*/
            int IDXPR, N;
            IDXPR = strToInteger(currentInput);
            N = strToInteger(currentInput);
            PlaylistRemove(&PLY, IDXPR, N);
            // printf("Masuk ke PLAYLIST REMOVE\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST REMOVE")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST DELETE")) && dalamsesi == true)
        {
            /*masukin fungsi PLAYLIST DELETE*/
            PlaylistDelete(&PLY);
            printf("Masuk ke PLAYLIST DELETE\n");
        }
        else if ((INPUTEQUAL(currentInput, "PLAYLIST DELETE")) && dalamsesi == false)
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