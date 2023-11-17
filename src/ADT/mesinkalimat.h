/* File: mesinkalimat.h */

#ifndef _MESINKALIMAT_H_
#define _MESINKALIMAT_H_

#include "boolean.h"
#include "mesinkata.h"

#define NMax 10
#define MARKSENTENCE '\n'
#define BLANK ' '

typedef struct
{
   Word TabSentence[280]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Sentence;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void AcquireBlanks();

void AcquireSentence();

void PrintSentence();
#endif