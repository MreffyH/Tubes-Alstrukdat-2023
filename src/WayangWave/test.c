#include <stdio.h>
#include <stdlib.h>
#include "bacaConfig.h"
#include "../ADT/list.h"
#include "../ADT/set.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkalimat.h"
#include "../ADT/map.h"



// void PrintSet(Set S)
// /* Mencetak elemen-elemen Set S ke layar */
// {
//     if (IsEmptySet(S))
//     {
//         printf("Set is empty.\n");
//     }
//     else
//     {
//         printf("{ ");
//         for (addrSer i = 0; i < S.Count; i++)
//         {
//             PrintSentence(S.Elements[i]);
//             if (i < S.Count - 1)
//             {
//                 printf(", ");
//             }
//         }
//         printf(" }\n");
//     }
// }

// void PrintMap(Map M);
/* Mencetak elemen-elemen Map M ke layar */
// {
//     if (IsEmptyMap(M))
//     {
//         printf("Map is empty.\n");
//     }
//     else
//     {
//         printf("{ ");
//         for (addr i = 0; i < M.Count; i++)
//         {
//             PrintSentence(M.Elements[i].Key);
//             printf(": ");
//             PrintSentence(M.Elements[i].Value);
//             if (i < M.Count - 1)
//             {
//                 printf(", ");
//             }
//         }
//         printf(" }\n");
//     }
// }

int main() {
    // List Penyanyi;
    // Map Album;
    // Set Lagu;

    // MakeList(&Penyanyi);
    // CreateEmptyMap(&Album);
    // CreateEmptySet(&Lagu);

    // bacaConfig("config.txt", &Penyanyi, &Album, &Lagu);

    // // Print the contents of Penyanyi list
    // printf("Penyanyi:\n");
    // PrintList(&Penyanyi);

    // // Print the contents of Album map
    // printf("\nAlbum:\n");
    // PrintMap(Album);

    // // Print the contents of Lagu set
    // printf("\nLagu:\n");
    // PrintSet(Lagu);

    List Penyanyi;
    Map Album;
    Set Lagu;

    MakeList(&Penyanyi);
    CreateEmptyMap(&Album);
    CreateEmptySet(&Lagu);
    printf("Cekkkk\n");
    bacaConfig(&Penyanyi, &Album, &Lagu);

    return 0;
}