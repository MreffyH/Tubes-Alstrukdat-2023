/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

// #include "boolean.h"
#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'
#define SEMICOLON ';'
#define NONE '-'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern boolean ENDINPUT;
extern Word currentWord;
extern Word kalimat;
extern Word currentInput;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreEnter();
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isEndWord();

boolean IsKataEqual (Word Kata1, Word Kata2);

int strToInteger(Word Kata);

Word DuplicateKata(Word Kata);

void printWord(Word Kata);

void ADVSENTENCE();

boolean isNotNone(Word kalimat);

void ADVLOAD();

/* Bagian File */
void STARTKATAFILE(char *filestart);

/* Bagian Input */
void IGNORENEWLINE();

void STARTINPUT();

void COPYINPUTLOAD();

void STARTINPUTMAIN();

void COPYINPUT();

void RESETINPUT();

void ADVINPUT();

boolean INPUTEQUAL(Word I, char *K);

int FUNGSILENGTH(char *K);

void wordToString(Word kata, char *string);

#endif