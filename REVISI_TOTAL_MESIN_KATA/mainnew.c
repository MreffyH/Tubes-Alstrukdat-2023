// gcc -o main mainnew.c mesininput.c mesinkarakter.c mesinkata.c ADT_WAYANGWAVE/QUEUE/queue.c ADT_WAYANGWAVE/STACK/stack.c SPESIFIKASI_WAYANGWAVE/HELP/help.c SPESIFIKASI_WAYANGWAVE/START/start.c SPESIFIKASI_WAYANGWAVE/LOAD/load.c SPESIFIKASI_WAYANGWAVE/QUIT/quit.c listmapset.c ../src/ADT/mapset/set.c SPESIFIKASI_WAYANGWAVE/FUNGSI_LIST/ladt.c SPESIFIKASI_WAYANGWAVE/PLAY/play.c ../RIvaldi/arraydin.c ../src/ADT/list/listlinier.c SPESIFIKASI_WAYANGWAVE/SONG/song.c SPESIFIKASI_WAYANGWAVE/FUNGSI_QUEUE/QUEUE_WW.c

#include <stdio.h>

/* Include ADT */
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesininput.h"
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

int main()
{
    boolean mulaiWayangWave = true;
    boolean adadatabase = false;
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
        printf(">> ");
        STARTINPUT();
        if (INPUTEQUAL(currentInput, "START")) {
            if (!adadatabase) {
                STARTWAYANGWAVE(&PL, "config.txt");
                adadatabase = true;
                dalamsesi = true;
            } else {
                printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
            }
        } else if (INPUTEQUAL(currentInput, "LOAD")) {
            ADVCOMMAND();
            if (!adadatabase) {
                LOADWAYANGWAVE(&PL, currentInput.TabWord, &QS, &HS, &PLY, &currentSong);
                adadatabase = true;
                dalamsesi = true;
            } else {
                printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
            }
        } else if (INPUTEQUAL(currentInput, "LIST")) {
            ADVCOMMAND();
            if (INPUTEQUAL(currentInput, "DEFAULT")) {
                if(dalamsesi) {
                    LISTDEFAULT(PL);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if(INPUTEQUAL(currentInput, "PLAYLIST")) {
                if (dalamsesi) {
                    LISTPLAYLIST(PLY);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            }
        } else if (INPUTEQUAL(currentInput, "PLAY")) {
            ADVCOMMAND();
            if (INPUTEQUAL(currentInput, "SONG")) {
                if(dalamsesi) {
                    PLAYSONG(PL, PLY, &currentSong, &HS, &QS);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "PLAYLIST")) {
                if (dalamsesi) {
                    playPlaylist(PLY, &currentSong, &HS, &QS);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            }
        } else if (INPUTEQUAL(currentInput, "QUEUE")) {
            ADVCOMMAND();
            if (INPUTEQUAL(currentInput, "SONG")) {
                if (dalamsesi) {
                    QUEUESONG(PL, &QS);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "PLAYLIST")) {
                if (dalamsesi) {
                    QUEUEPLAYLIST(&QS, PLY);
                }
            } else if (INPUTEQUAL(currentInput, "SWAP")) {
                if (dalamsesi) {
                    int QSIDX1, QSIDX2;
                    ADVCOMMAND();
                    QSIDX1 = strToInteger(currentInput);
                    ADVCOMMAND();
                    QSIDX2 = strToInteger(currentInput);
                    QUEUESWAP(&QS, QSIDX1, QSIDX2);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "REMOVE")) {
                if (dalamsesi) {
                    int QSIDX;
                    ADVCOMMAND();
                    QSIDX = strToInteger(currentInput);
                    QUEUEREMOVE(&QS, QSIDX);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "CLEAR")) {
                if (dalamsesi) {
                    QUEUECLEAR(&QS);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            }
        } else if (INPUTEQUAL(currentInput, "SONG")) {
            ADVCOMMAND();
            if (INPUTEQUAL(currentInput, "NEXT")) {
                if (dalamsesi) {
                    songNext(&QS, &HS, &currentSong);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "PREVIOUS")) {
                if (dalamsesi) {
                    songPrevious(&QS, &HS, &currentSong);
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            }
        } else if (INPUTEQUAL(currentInput, "PLAYLIST")) {
            ADVCOMMAND();
            if (INPUTEQUAL(currentInput, "CREATE")) {
                if (dalamsesi) {
                    // Fungsi belum ada
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "ADD")) {
                ADVCOMMAND();
                if (INPUTEQUAL(currentInput, "SONG")) {
                    if (dalamsesi) {
                        // MASUKIN FUNGSINYA
                    } else {
                        printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                    }
                } else if (INPUTEQUAL(currentInput, "PLAYLIST")) {
                    if (dalamsesi) {
                        // MASUKIN FUNGSINYA
                    } else {
                        printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                    }
                }
            } else if (INPUTEQUAL(currentInput, "SWAP")) {
                if (dalamsesi) {
                    int PLYIDX1, PLYIDX2;
                    ADVCOMMAND();
                    PLYIDX1 = strToInteger(currentInput);
                    ADVCOMMAND();
                    PLYIDX2 = strToInteger(currentInput);
                    // MASUKIN FUNGSINYA
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "REMOVE")) {
                if (dalamsesi) {
                    int PLYIDXR1, PLYIDXR2;
                    ADVCOMMAND();
                    PLYIDXR1 = strToInteger(currentInput);
                    ADVCOMMAND();
                    PLYIDXR2 = strToInteger(currentInput);
                    // MASUKIN FUNGSINYA
                } else {
                    printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                }
            } else if (INPUTEQUAL(currentInput, "DELETE")) {
                if (dalamsesi) {
                        // MASUKIN FUNGSINYA
                    } else {
                        printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
                    }
            }
        } else if (INPUTEQUAL(currentInput, "HELP")) {
            if (dalamsesi) {
                helpAfter();
            } else {
                helpBefore();
            }
        } else if (INPUTEQUAL(currentInput, "SAVE")) {
            if (dalamsesi) {
                // MASUKIN FUNGSINYA
            } else {
                printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
            }
        } else if (INPUTEQUAL(currentInput, "QUIT")) {
            if (dalamsesi) {
                quit();
            } else {
                printf("ERROR: COMMAND TIDAK DAPAT DIEKSEKUSI!\n");
            }
        } else {
            printf("COMMAND TIDAK DIKETAHUI\n");
        }
    }
}