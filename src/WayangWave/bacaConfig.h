#ifndef START_BacaConfig_H
#define START_BacaConfig_H

#include "../adt/mesinkata.h"
#include "../ADT/stack.h"
#include "../adt/set.h"
#include "../adt/map.h"
#include "../adt/listlinier.h"

void BacaConfig(char *filesrc, List *Penyanyi, Map *Album, Set *Lagu);
/* Membaca file .txt dan menyimpan isinya ke dalam array of Word
I.S. list terdefinisi mungkin kosong tetapi tidak penuh
F.S. Isi listGame bertambah dari isi file .txt
*/
#endif