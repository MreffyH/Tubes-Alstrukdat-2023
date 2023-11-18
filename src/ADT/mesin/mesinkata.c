#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

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
        IgnoreBlanks();
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
    while (currentChar != BLANK && currentChar != MARK)
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

Word SalinKata(Word Kata){
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
    printf("\n");
}
