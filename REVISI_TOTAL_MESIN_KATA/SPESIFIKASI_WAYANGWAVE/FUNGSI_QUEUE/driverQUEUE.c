#include "QUEUE_WW.h"
#include "../../ADT_WAYANGWAVE/STACK/stack.h"

int main(){
    // char *file = "user1.txt";
    // STARTWAYANGWAVE(file);
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
    // PrintArrayDin(PLY);
    STARTINPUT();
    Word file = currentInput;
    LOADWAYANGWAVE(&PL, file.TabWord, &QS, &HS, &PLY, &currentSong);


}