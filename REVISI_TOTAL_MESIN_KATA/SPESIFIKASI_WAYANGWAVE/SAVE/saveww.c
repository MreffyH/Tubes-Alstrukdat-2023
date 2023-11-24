#include<stdio.h>
#include<stdlib.h>
#include"saveww.h"

static FILE *file;

void SAVEWW(ListPenyanyi *PL, char *namafile, ArrayDin *PLY, QueueSong *QS, HistorySong *HS, DetailSongQ *CS) {
    file = fopen(namafile, "w");
    fprintf(file, "%d\n", (*PL).countpenyanyi); // BACA JUMLAH PENYANYI
    for (int i = 0; i < (*PL).countpenyanyi; i++) {
        fprintf(file, "%d %s\n", (*PL).penyanyi_ke[i].countalbum ,(*PL).penyanyi_ke[i].namaPenyanyi); // BACA JUMLAH ALBUM DAN NAMA PENYANYI
        for (int j = 0; j < (*PL).penyanyi_ke[i].countalbum; j++)
        {
            fprintf(file, "%d %s\n", (*PL).penyanyi_ke[i].mapalbum[j].setlagu.Count, (*PL).penyanyi_ke[i].mapalbum[j].namaAlbum); // BACA JUMLAH LAGU DAN NAMA ALBUM
            for (int z = 0; z < (*PL).penyanyi_ke[i].mapalbum[j].setlagu.Count; z++)
            {
                fprintf(file, "%s\n", (*PL).penyanyi_ke[i].mapalbum[j].setlagu.Elements[z]); // BACA NAMA LAGU 
            }
            
        }
        
    }
    /* Current Song */
    if(((*CS).namaPenyanyiQ.TabWord[0] == NONE) && ((*CS).namaAlbumQ.TabWord[0] == NONE) && ((*CS).namaLaguQ.TabWord[0] == NONE)){
        fprintf(file,"-\n");
    }
    else {
        fprintf(file, "%s", (*CS).namaPenyanyiQ);
        fprintf(file, ";%s", (*CS).namaAlbumQ);
        fprintf(file, ";%s\n", (*CS).namaLaguQ);
    }
    /* QUEUE */
    fprintf(file, "%d\n", lengthQ(*QS));
    for(int i = 0; i < lengthQ(*QS); i++){
        fprintf(file, "%s", (*QS).detil_queue[i].namaPenyanyiQ);
        fprintf(file, ";%s", (*QS).detil_queue[i].namaAlbumQ);
        fprintf(file,";%s\n", (*QS).detil_queue[i].namaLaguQ);
    }
    /* HISTORY */
    fprintf(file, "%d\n", lengthS(*HS));
    for (int i = 0; i < lengthS(*HS); i++) {
        fprintf(file, "%s", (*HS).detil_history[i].namaPenyanyiS);
        fprintf(file, ";%s", (*HS).detil_history[i].namaAlbumS);
        fprintf(file, ";%s\n", (*HS).detil_history[i].namaLaguS);
    }
    
    /* PLAYLIST */
    fprintf(file, "%d\n", (*PLY).Neff);
    for (int i = 0; i < (*PLY).Neff; i++) {
        fprintf(file, "%d ", (*PLY).detil_playlist[i].countlaguLL);
        fprintf(file, "%s\n", (*PLY).detil_playlist[i].nama_PlayList);
        address P = First((*PLY).detil_playlist[i].IsiLagu);
        while (P != NilLin){
            fprintf(file, "%s", InfoPenyanyi(P));
            fprintf(file, ";%s", InfoAlbum(P));
            fprintf(file, ";%s\n", InfoJudul(P));
            P = Next(P);
        }
    }
    fclose(file);
}