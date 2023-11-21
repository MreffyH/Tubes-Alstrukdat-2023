/* File: listdinamis.h */

#ifndef __LISTDINAMIS_H_
#define __LISTDINAMIS_H_

#include "boolean.h"
#include "mesinkata.h"

#define IdxTypeLD int 
#define MaxElLD 100

typedef struct 
{
    Word *WORDLD;
    int NeffLD;
} ListDinamis;

void CREATEEMPTYLD(ListDinamis *LD);

void DEALLOCATELD(ListDinamis *LD);

boolean ISEMPTYLD(ListDinamis LD);

int LENGTHLD(ListDinamis LD);

Word GETLD(ListDinamis LD, IdxTypeLD IDXLD);

int GETCAPACITYLD(ListDinamis LD);

void INSERTATLD(ListDinamis *LD, Word ELLD, IdxTypeLD IDXLD);

void DELETEATLD(ListDinamis *LD, IdxTypeLD IDXLD);
#endif