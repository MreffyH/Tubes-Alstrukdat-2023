/* File: mesinkalimat.h */

#ifndef _MESINKALIMAT_H_
#define _MESINKALIMAT_H_

#include "boolean.h"
#include "mesinkata.h"

#define MARKSENTENCE '\n'
#define BLANK ' '

typedef struct
{
   char TabSentence[280]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Sentence;


/* State Mesin Word */
extern boolean EndSentence;
extern Sentence currentKalimat;


void AcquireBlanks();

void CopySentence();

void NewSentence();

void PrintSentence(Sentence currentKalimat);

boolean IsKalimatEqual(Sentence s1, Sentence s2);
#endif