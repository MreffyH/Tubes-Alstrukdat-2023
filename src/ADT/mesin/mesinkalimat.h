/* File: mesinkalimat.h */

#ifndef _MESINKALIMAT_H_
#define _MESINKALIMAT_H_

#include "boolean.h"
#include "mesinkata.h"

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
extern Sentence currentKalimat;


void AcquireBlanks();

void AcquireSentence();

void PrintSentence(Sentence currentKalimat);

boolean IsKalimatEqual(Sentence s1, Sentence s2);
#endif