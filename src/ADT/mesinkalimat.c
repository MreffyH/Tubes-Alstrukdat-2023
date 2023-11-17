#include <stdio.h>
#include "mesinkalimat.h"
/* File: mesinkalimat.c */
/* Implementasi Mesin Karakter */

Sentence currentKalimat;

void AcquireBlanks()
{
    int i = 0;
    currentWord.Length = 0;
    while (currentChar == BLANK)
    {
        currentWord.TabWord[i] = currentChar;
        currentWord.Length++;
        ADV();
        i++;
    }
}
/*  Membaca blank spaces
    I.S :   currentChar adalah blank pertama
    F.S :   currentWord adalah kumpulan blank
            currentChar adalah sebuah character atau MARK
    */

void AcquireSentence()
{
    currentKalimat.Length = 0;
    int i = 0;
    while (currentChar != MARKSENTENCE)
    {
        if (currentChar == BLANK)
        {
            AcquireBlanks();
        }
        else
        {
            CopyWord();
        }
        currentKalimat.TabSentence[i] = currentWord;
        currentKalimat.Length++;
        ADV();
        i++;
    }
}
/* Membaca seluruh pita dan mengakuisisi kalimat
   I.S. : currentChar adalah karakter pertama dari pita
   F.S. : sentence berisi kalimat yang sudah diakuisisi dengan format array of words.
          Contoh: "Saya suka     babi" akan disimpan dengan format ["Saya", " ", "suka", "     ", "babi"]
          currentChar = MARKSENTENCE; */

void PrintSentence(Sentence currentKalimat)
{
    int i = 0;
    for (i = 0; i < currentKalimat.Length; i++)
    {
        printWord(currentKalimat.TabSentence[i]);
    }
}

boolean IsKalimatEqual(Sentence s1, Sentence s2)
/* Mengembalikan true jika dua kalimat s1 dan s2 sama */
{
    if (s1.Length != s2.Length)
    {
        return false;
    }

    for (int i = 0; i < s1.Length; i++)
    {
        if (!IsKataEqual(s1.TabSentence[i], s2.TabSentence[i]))
        {
            return false;
        }
    }

    return true;
}