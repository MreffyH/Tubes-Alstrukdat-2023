#include <stdio.h>
#include "listmapset.h"

int main(){
    ListPenyanyi Singer;
    CreateListPenyanyi(&Singer);
    STARTFILE("user1.txt");
    ADV();
    ADVWORD();
    int jumlahpenyanyi = strToInteger(currentWord);
    Jumlahpenyanyi(Singer) = jumlahpenyanyi;
    printf("Jumlah penyanyi: %d\n", Jumlahpenyanyi(Singer));
    ADV();
    IgnoreEnter();
    for (int i = 0; i < jumlahpenyanyi; i++){
        ADVWORD();
        int jumlahalbum = strToInteger(currentWord);
        Jumlahalbum(Singer.penyanyi_ke[i]) = jumlahalbum;
        printf("Jumlah album penyanyi ke-%d: %d\n", i+1, Jumlahalbum(Singer.penyanyi_ke[i]));
        ADVSENTENCE();
        IgnoreEnter();
        printf("Nama penyanyi ke-%d: ", i+1);
        Singer.penyanyi_ke[i].namaPenyanyi = kalimat;
        printWord(Singer.penyanyi_ke[i].namaPenyanyi);
        printf("\n");
        for (int j = 0; j < jumlahalbum; j++){
            ADVWORD();
            int jumlahlagu = strToInteger(currentWord);
            Singer.penyanyi_ke[i].listalbum[j].setlagu.Count = jumlahlagu;
            printf("Jumlah lagu album ke-%d: %d\n", j+1, Singer.penyanyi_ke[i].listalbum[j].setlagu.Count);
            ADVSENTENCE();
            IgnoreEnter();
            printf("Nama album ke-%d: ", j+1);
            Singer.penyanyi_ke[i].listalbum[j].namaAlbum = kalimat;
            printWord(Singer.penyanyi_ke[i].listalbum[j].namaAlbum);
            printf("\n");
            for(int k = 0; k < jumlahlagu; k++){
                if((i == jumlahpenyanyi-1) && (j == jumlahalbum-1) && (k == jumlahlagu-1)){
                    ADVSENTENCE();
                    printf("Nama lagu ke-%d: ", k+1);
                    InsertSet(&(Singer.penyanyi_ke[i].listalbum[j].setlagu), kalimat);
                    printWord(kalimat);
                }
                else{
                    ADVSENTENCE();
                    IgnoreEnter();
                    printf("Nama lagu ke-%d: ", k+1);
                    InsertSet(&(Singer.penyanyi_ke[i].listalbum[j].setlagu), kalimat);
                    printWord(kalimat);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}