#ifndef START_BacaConfig_H
#define START_BacaConfig_H

#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"
#include "../ADT/set.h"
#include "../ADT/map.h"
#include "../ADT/list.h"
#include "../ADT/mesinkalimat.h"

void bacaConfig(char *filesrc, List *Penyanyi, Map *Album, Set *Lagu);
/* Membaca file .txt dan menyimpan isinya ke dalam array of Word
I.S. list terdefinisi mungkin kosong tetapi tidak penuh
F.S. Isi listGame bertambah dari isi file .txt
*/
#endif