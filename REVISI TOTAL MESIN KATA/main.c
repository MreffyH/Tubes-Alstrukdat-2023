#include <stdio.h>
#include "mesinkata.h"

int main(){
    STARTFILE("config.txt");
    printf("Jumlah penyanyi: %c\n", currentChar);
    ADV();
    // ADVFILE();
    // printf("%c", currentChar);
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVFILE();
    // printf("%c", currentChar);
    /* Mesin karakter AMANNN */
    ADVWORD();
    printf("Jumlah album penyanyi ke-1: ");
    printWord(currentWord);
    ADVWORD();
    printf("Nama penyanyi ke-1: ");
    printWord(currentWord);
    ADVWORD();
    printf("Jumlah lagu album ke-1: ");
    printWord(currentWord);
    ADVWORD();
    printf("Nama album ke-1: ");
    printWord(currentWord);
    // ADVWORD();
    // printWord(currentWord);
    // ADVFILE();
    // printf("%c", currentChar);
    // ADVWORD();
    // for(int i = 0; i < currentWord.Length; i++){
    //     printf("%c", currentWord.TabWord[i]);
    // }
    return 0;
}