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
    Word filename;
    Word Choice;
    Word Choice2;
    Word input1;
    int id;
    int x;
    int y;

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
        if((!INPUTEQUAL(currentInput,"START;")) && (!INPUTEQUAL(currentInput,"STATUS;")) && (!INPUTEQUAL(currentInput,"HELP;")) && (!INPUTEQUAL(currentInput,"QUIT;"))){
            int checkchar = 0;
            
            Choice.Length = 0;
            while ((checkchar < currentInput.Length) && (currentInput.TabWord[checkchar] != ' ')){
                Choice.Length++;
                Choice.TabWord[checkchar] = currentInput.TabWord[checkchar];
                checkchar++;
            } /* Checkchar sama dengan indeks pada saat blank */
            checkchar++; /* checkchar sama dengan indeks dari karakter setelah blank */
            if(INPUTEQUAL(Choice,"LOAD")){
                filename.Length = 0;
                int idxfile = 0;
                while(currentInput.TabWord[checkchar] != ';'){
                    filename.Length++;
                    filename.TabWord[idxfile] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxfile++;
                }
            }
            else if(INPUTEQUAL(Choice, "LIST")){
                Choice2.Length = 0;
                int idxchoice2 = 0;
                while (currentInput.TabWord[checkchar] != ';')
                {
                    Choice2.Length++;
                    Choice2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxchoice2++;
                }

            }
            else if(INPUTEQUAL(Choice, "PLAY")){
                Choice2.Length = 0;
                int idxchoice2 = 0;
                while (currentInput.TabWord[checkchar] != ';')
                {
                    Choice2.Length++;
                    Choice2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxchoice2++;
                }
                
            }
            else if(INPUTEQUAL(Choice,"QUEUE")){
                Choice2.Length = 0;
                int idxchoice2 = 0;
                while ((currentInput.TabWord[checkchar] != ';') && (currentInput.TabWord[checkchar] != ' '))
                {
                    Choice2.Length++;
                    Choice2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxchoice2++;
                }
                if (currentInput.TabWord[checkchar] == ' '){
                    Word input1;
                    input1.Length = 0;
                    Word input2;
                    input2.Length = 0;
                    checkchar++;
                    idxchoice2 = 0;
                    while ((currentInput.TabWord[checkchar] != ';') && (currentInput.TabWord[checkchar] != ' ')){
                        input1.Length++;
                        input1.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                        checkchar++;
                        idxchoice2++;
                    }
                    idxchoice2 = 0;
                    if(currentInput.TabWord[checkchar] == ' '){
                        checkchar++;
                        while (currentInput.TabWord[checkchar] != ';')
                        {
                            input2.Length++;
                            input2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                            checkchar++;
                            idxchoice2++;
                        }
                        y = strToInteger(input2);
                    }
                    x = strToInteger(input1);
                }
            }
            else if(INPUTEQUAL(Choice, "SONG")){
                Choice2.Length = 0;
                int idxchoice2 = 0;
                while (currentInput.TabWord[checkchar] != ';')
                {
                    Choice2.Length++;
                    Choice2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxchoice2++;
                }
            }
            else if(INPUTEQUAL(Choice, "PLAYLIST")){
                Choice2.Length = 0;
                int idxchoice2 = 0;
                while ((currentInput.TabWord[checkchar] != ';') && (currentInput.TabWord[checkchar] != ' '))
                {
                    Choice2.Length++;
                    Choice2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxchoice2++;
                }
                if (currentInput.TabWord[checkchar] == ' '){
                    input1.Length = 0;
                    Word input2;
                    input2.Length = 0;
                    Word input3;
                    input3.Length = 0;
                    checkchar++;
                    idxchoice2 = 0;
                    while ((currentInput.TabWord[checkchar] != ';') && (currentInput.TabWord[checkchar] != ' ')){
                        input1.Length++;
                        input1.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                        checkchar++;
                        idxchoice2++;
                    }
                    idxchoice2 = 0;
                    if(currentInput.TabWord[checkchar] == ' '){
                        checkchar++;
                        while ((currentInput.TabWord[checkchar] != ';') && (currentInput.TabWord[checkchar] != ' '))
                        {
                            input2.Length++;
                            input2.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                            checkchar++;
                            idxchoice2++;
                        }
                        x = strToInteger(input2);
                        idxchoice2 = 0;
                        if(currentInput.TabWord[checkchar] == ' '){
                            checkchar++;
                            while (currentInput.TabWord[checkchar] != ';')
                            {
                                input3.Length++;
                                input3.TabWord[idxchoice2] = currentInput.TabWord[checkchar];
                                checkchar++;
                                idxchoice2++;
                            }
                            y = strToInteger(input3);
                        }
                    }
                    id = strToInteger(input1);
                }
            }
            else if(INPUTEQUAL(Choice, "SAVE")){
                filename.Length = 0;
                int idxfile = 0;
                while(currentInput.TabWord[checkchar] != ';'){
                    filename.Length++;
                    filename.TabWord[idxfile] = currentInput.TabWord[checkchar];
                    checkchar++;
                    idxfile++;
                }
            }
        }
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
        else if (INPUTEQUAL(Choice, "LOAD") && dalamsesi == false)
        {
            wordToString(filename, filename.TabWord);
            LOADWAYANGWAVE(&PL, filename.TabWord, &QS, &HS, &PLY, &currentSong);
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
            dalamsesi = true;
        }
        else if ((INPUTEQUAL(Choice, "LOAD")) && dalamsesi == true)
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
        else if ((INPUTEQUAL(Choice, "PLAY")) && dalamsesi == true)
        {
            if(INPUTEQUAL(Choice2, "SONG")){ /* PLAY SONG */
                PLAYSONG(PL, PLY, &currentSong, &HS, &QS);
            }
            else if (INPUTEQUAL(Choice2, "PLAYLIST")) { /* PLAY PLAYLIST */
                playPlaylist(PLY, &currentSong, &HS, &QS);
            }
        }
        else if ((INPUTEQUAL(Choice, "PLAY")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(Choice, "QUEUE")) && dalamsesi == true)
        {
            if(INPUTEQUAL(Choice2, "SONG")){ /* QUEUE SONG */
                QUEUESONG(PL, &QS);
            }
            else if(INPUTEQUAL(Choice2, "PLAYLIST")){ /* QUEUE PLAYLIST */
                QUEUEPLAYLIST(&QS, PLY);
            }
            else if(INPUTEQUAL(Choice2,"CLEAR")){ /* QUEUE CLEAR */
                QUEUECLEAR(&QS);
            }
            else if(INPUTEQUAL(Choice2,"REMOVE")){ /* QUEUE REMOVE */
                QUEUEREMOVE(&QS, x);
                printf("MELAKUKAN QUEUE REMOVE DGN NILAI X: %d\n", x);
            }
            else if(INPUTEQUAL(Choice2,"SWAP")){ /* QUEUE SWAP */
                QUEUESWAP(&QS, x, y);
                printf("MELAKUKAN QUEUE SWAP DGN NILAI X: %d; Y: %d\n", x, y);
            }
        }
        else if ((INPUTEQUAL(Choice, "QUEUE")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        
        else if ((INPUTEQUAL(currentInput, "STATUS;")) && dalamsesi == true)
        {
            /*masukin fungsi STATUS*/
            printf("Masuk ke STATUS\n");
        }
        else if ((INPUTEQUAL(currentInput, "STATUS;")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(Choice, "SAVE")) && dalamsesi == true)
        {
            /*masukin fungsi SAVE*/
            printf("Masuk ke SAVE\n");
        }
        else if ((INPUTEQUAL(Choice, "SAVE")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(Choice, "LIST")) && dalamsesi == true)
        {
            if(INPUTEQUAL(Choice2, "DEFAULT")){ /* LIST DEFAULT */
                printf("MELAKUKAN LIST DEFAULT\n");
                LISTDEFAULT(PL);
            }
            else if(INPUTEQUAL(Choice2, "PLAYLIST")){ /* LIST PLAYLIST */
                LISTPLAYLIST(PLY);
                printf("MELAKUKAN LIST PLAYLIST\n");
            }
        }
        else if ((INPUTEQUAL(Choice, "LIST")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(Choice, "SONG")) && dalamsesi == true)
        {
            if(INPUTEQUAL(Choice2, "NEXT")){ /* SONG NEXT */
                songNext(&QS, &HS, &currentSong);
                printf("MELAKUKAN SONG NEXT\n");
            }
            else if(INPUTEQUAL(Choice2, "PREVIOUS")){ /* SONG PREVIOUS */
                songPrevious(&QS, &HS, &currentSong);
                printf("MELAKUKAN SONG PREVIOUS\n");
            }
        }
        else if ((INPUTEQUAL(Choice, "SONG")) && dalamsesi == false)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        else if ((INPUTEQUAL(Choice, "PLAYLIST")) && dalamsesi == true)
        {
            if (INPUTEQUAL(Choice2, "CREATE")){ /* PLAYLIST CREATE */
                CreatePlaylist(&PLY);
                printf("MELAKUKAN PLAYLIST CREATE\n");
            }
            else if(INPUTEQUAL(Choice2, "ADD")){
                if(INPUTEQUAL(input1, "SONG")){ /* PLAYLIST ADD SONG */
                    PlaylistADDSong(&PLY, PL);
                    printf("Masuk ke PLAYLIST ADD SONG\n");
                }
                else if(INPUTEQUAL(input1, "ALBUM")){ /* PLAYLIST ADD ALBUM */
                    PlaylistADDAlbum(&PLY, PL);
                    printf("Masuk ke PLAYLIST ADD ALBUM\n");
                }
            }
            else if(INPUTEQUAL(Choice2, "SWAP")){ /* PLAYLIST SWAP */
                PlaylistSwap(&PLY, id, x, y);
                printf("Masuk ke PLAYLIST SWAP DGN NILAI ID: %d; X: %d; Y: %d\n", id, x, y);
            }
            else if(INPUTEQUAL(Choice2, "REMOVE")){
                PlaylistRemove(&PLY, id, x);
                printf("Masuk ke PLAYLIST REMOVE DGN NILAI ID: %d; X: %d\n", id, x);
            }
            else if(INPUTEQUAL(Choice2,"DELETE")){
                PlaylistDelete(&PLY);
                printf("Masuk ke PLAYLIST DELETE\n");
            }
        }
        else if ((INPUTEQUAL(Choice, "PLAYLIST")) && dalamsesi == false)
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