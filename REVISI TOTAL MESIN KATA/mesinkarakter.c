#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
static FILE *pita;
static int retval;

boolean EOP;

void STARTFILE(char *input){
    pita = fopen(input,"r");
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    pita = stdin;
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK */
    retval = fscanf (pita, "%c", &currentChar);
}

void ADVFILE() {
    retval = fscanf (pita, "%c", &currentChar);
    if (feof(pita)) {
        fclose(pita);
    } 
}

char GetCC() {
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP() {
/* Mengirimkan true jika currentChar = MARK */
    return (currentChar == MARK);
}

boolean ISENDFILE(){
    return feof(pita);
}

void TUTUPFILE(){
    fclose(pita);
}

void ADVMARK() {
    if (pita == NULL) {
        EOP = true;
    } else {
        retval = fscanf (pita, "%c", &currentChar);
        EOP = feof(pita);
        if (EOP) {
            fclose(pita);
        }
    }
}