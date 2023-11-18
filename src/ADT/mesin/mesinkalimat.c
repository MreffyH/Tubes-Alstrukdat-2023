#include <stdio.h>
#include "mesinkalimat.h"
/* File: mesinkalimat.c */
/* Implementasi Mesin Kalimat */

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
    int idx = 0;
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
        
        for (int i = 0; i < currentWord.Length; i++){
            currentKalimat.TabSentence[idx+i] = currentWord.TabWord[i];
            currentKalimat.Length++;
        }
        idx = idx + currentWord.Length;
        ADV();
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
        printf("%c", currentKalimat.TabSentence[i]);
    }
    print("\n");
}

boolean IsKalimatEqual(Sentence s1, Sentence s2)
/* Mengembalikan true jika dua kalimat s1 dan s2 sama */
{
    boolean sama = true;
    if (s1.Length == s2.Length)
    {
        int i = 0;
        while ((i < s1.Length) && (sama))
        {
            if (s1.TabSentence[i] != s2.TabSentence[i])
            {
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