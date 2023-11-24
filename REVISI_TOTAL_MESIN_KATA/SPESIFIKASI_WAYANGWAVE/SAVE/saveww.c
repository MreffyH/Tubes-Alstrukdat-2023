#include<stdio.h>
#include<stdlib.h>
#include"saveww.h"

static FILE *file;

void SAVEWW(ListPenyanyi *PL, char *namafile) {
    file = fopen(namafile, "w");
    fprintf(file, "%d\n", (*PL).countpenyanyi);
    for (int i = 0; i < (*PL).countpenyanyi; i++) {
        fprintf(file, "%d %s\n", (*PL).penyanyi_ke->countalbum ,(*PL).penyanyi_ke[i]);
        for (int j = 0; j < (*PL).penyanyi_ke->countalbum; j++)
        {
            fprintf(file, "%d %s\n", (*PL).penyanyi_ke->mapalbum->setlagu.Count, (*PL).penyanyi_ke->mapalbum->namaAlbum);
            for (int z = 0; z < (*PL).penyanyi_ke->mapalbum->setlagu.Count; z++)
            {
                fprintf(file, "%s\n", (*PL).penyanyi_ke->mapalbum->setlagu.Elements[z]);
            }
            
        }
        
    }
}