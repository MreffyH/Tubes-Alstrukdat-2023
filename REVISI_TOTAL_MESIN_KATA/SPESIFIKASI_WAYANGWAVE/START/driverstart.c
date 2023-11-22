/* File: driverstart.c */
/* gcc -o driverstart driverstart.c start.c ../../mesinkata.c ../../listmapset.c ../../mesinkarakter.c ../../../src/ADT/mapset/set.c */

#include "start.h"
#include "../../mesinkata.h"
#include "../../listmapset.h"

#include<stdio.h>
#include<stdlib.h>

int main() {
    
    Set S;
    CreateEmptySet(&S);

    MapAlbum MA;
    CreateMapAlbum(&MA, S);
    
    MapPenyanyi MP;
    CreateMapPenyanyi(&MP, MA);

    ListPenyanyi PL;
    CreateListPenyanyi(&PL, MP);

    char *file = "../../config.txt";
    STARTWAYANGWAVE(&PL, file);
    printf("\n");

    DISPLAYPENYANYI(PL);

    DISPLAYALBUM(PL);

    DISPLAYLAGU(PL);

    // printf("DISPLAY SEMUA PENYANYI:\n");
    // for(int j = 0; j< Jumlahpenyanyi(PL); j++){
    //     printf("%d. ", j+1);
    //     printWord(PL.penyanyi_ke[j].namaPenyanyi);
    //     printf("\n");
    // }

    // printf("\n");
    // int choice;
    // printf("CHOICE: ");
    // scanf("%d", &choice);
    // printf("DISPLAY SEMUA ALBUM DARI ");
    // printWord(PL.penyanyi_ke[choice-1].namaPenyanyi);
    // printf("\n");
    // for(int j = 0; j < PL.penyanyi_ke[choice-1].countalbum; j++){
    //     printf("%d. ", j+1);
    //     printWord(PL.penyanyi_ke[choice-1].mapalbum[j].namaAlbum);
    //     printf("\n");
    // }
    // printf("\n");
    // int choice2;
    // printf("CHOICE: ");
    // scanf("%d", &choice2);
    // printWord(PL.penyanyi_ke[choice-1].mapalbum[choice2-1].namaAlbum);
    // printf(" DARI PENYANYI ");
    // printWord(PL.penyanyi_ke[choice-1].namaPenyanyi);
    // printf("\n");
    // for(int j = 0; j < PL.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Count; j++){
    //     printf("%d. ", j+1);
    //     printWord(PL.penyanyi_ke[choice-1].mapalbum[choice2-1].setlagu.Elements[j]);
    //     printf("\n");
    // }
    // return 0;
}