#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
boolean ENDINPUT;
Word currentWord;
Word kalimat;
Word currentInput;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}
void IgnoreEnter()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == ENTER)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != ENTER)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

boolean IsKataEqual(Word Kata1, Word Kata2){
    boolean sama = true;
    if (Kata1.Length == Kata2.Length){
        int i = 0;
        while ((i < Kata1.Length) && (sama)){
            if (Kata1.TabWord[i] != Kata2.TabWord[i]){
                sama = false;
            }
            else{
                i++;
            }
        }
    }
    else{
        sama = false;
    }
    return sama;
}


int strToInteger(Word Kata){
    int kataToInt = 0;
    for (int i = 0; i < Kata.Length; i++){
        kataToInt = kataToInt * 10 + (Kata.TabWord[i] - '0');
    }
    return kataToInt;
}

Word DuplicateKata(Word Kata){
    Word HasilCopyK;
    HasilCopyK.Length = Kata.Length;
    for (int i = 0; i < Kata.Length; i++){
        HasilCopyK.TabWord[i] = Kata.TabWord[i];
    }
    return HasilCopyK;
}

void printWord(Word Kata){
    for(int i = 0; i < Kata.Length; i++){
        printf("%c", Kata.TabWord[i]);
    }
}


void ADVSENTENCE(){
    kalimat.Length = 0;
    ADVWORD();
    for (int i = 0; i < currentWord.Length; i++){
            kalimat.TabWord[kalimat.Length] = currentWord.TabWord[i];
            kalimat.Length++;
    }
    while(currentChar != ENTER && currentChar != MARK){
        if(currentChar == BLANK){
            kalimat.TabWord[kalimat.Length] = currentChar;
            kalimat.Length++;
        }
        ADVWORD();
        for (int i = 0; i < currentWord.Length; i++){
            kalimat.TabWord[kalimat.Length] = currentWord.TabWord[i];
            kalimat.Length++;
        }
    }
}

// void ADVPLAYING(){
//     kalimat.Length = 0;
//     IgnoreEnter();
//     if(currentChar != NONE){
//         ADVLOAD();
//     }
//     else{
        
//     }
    
// }

boolean isNotNone(Word kalimat){
    boolean none = false;
    if(kalimat.Length != 0){
        none = true;
    }
    return none;
}

void ADVLOAD(){
    kalimat.Length = 0;
    while((currentChar != SEMICOLON) && (currentChar != ENTER) && (currentChar != NONE) && (currentChar != MARK)){
        kalimat.TabWord[kalimat.Length] = currentChar;
        kalimat.Length++;
        ADV();
    }
    if(currentChar == SEMICOLON){ 
        ADV();
    }
    /* ELSE KALO currentChar == NONE gak ngelakuin apa apa */
}

void IGNORENEWLINE() {
    while (currentChar == ' ')
    {
        ADV();
    }
    
}

void STARTKATAFILE(char *filestart) {
    STARTFILE(filestart);
    IgnoreBlanks();
    if (currentChar == '\0') {
        endWord = true;
    } else
    {
        endWord = false;
        CopyWord();
    }
    
}

void STARTINPUT() {
    START();
    IGNORENEWLINE();
    if (currentChar == ';')
    {
        ENDINPUT = true;
    } else {
        ENDINPUT = false;
        COPYINPUT();
    }
    
}

void COPYINPUT() {
    RESETINPUT();
    int i = 0;
    while ((currentChar != '\n') && (currentChar != EOF))
    {
        currentInput.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentInput.Length = i;
}

void RESETINPUT() {
    for (int i = 0; i < sizeof(currentInput); i++)
    {
        currentInput.TabWord[i] = '\0';
        currentInput.Length = 0;
    }
}

void ADVINPUT() {
    IgnoreBlanks();
    if (currentChar == ';') {
        ENDINPUT = true;
    } else {
        ENDINPUT = false;
        COPYINPUT();
    }
}

boolean INPUTEQUAL(Word I, char *K) {
    boolean sama = true;
    int i = 0;
    if (I.Length == FUNGSILENGTH(K)) {
        while (i < I.Length && sama)
        {
            if (I.TabWord[i] != K[i]) {
                sama = false;
            } else {
                i++;
            }
        }
        
    } else {
        sama = false;
    }
    return sama;

}

int FUNGSILENGTH(char *K) {
    int i = 0;
    while (K[i] != '\0')
    {
        i++;
    }
    return i;
}

// int main() {
//     // Word DuplicateKata(Word Kata){
//     // Word HasilCopyK;
//     // HasilCopyK.Length = Kata.Length;
//     // for (int i = 0; i < Kata.Length; i++){
//     //     HasilCopyK.TabWord[i] = Kata.TabWord[i];
//     // }
//     // return HasilCopyK;
//     STARTINPUT();
//     Word kata = DuplicateKata(currentInput);
//     printWord(kata);
// }