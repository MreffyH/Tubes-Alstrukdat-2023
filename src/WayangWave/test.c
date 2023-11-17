#include <stdio.h>
#include "bacaConfig.h"
#include "bacaConfig.c"
#include "../ADT/map.c"
#include "../ADT/mesinkalimat.c"
#include "../ADT/set.c"
#include "../ADT/list.c"

void PrintSet(Set S)
/* Mencetak elemen-elemen Set S ke layar */
{
    if (IsEmptySet(S))
    {
        printf("Set is empty.\n");
    }
    else
    {
        printf("{ ");
        for (addrSer i = 0; i < S.Count; i++)
        {
            PrintSentence(S.Elements[i]);
            if (i < S.Count - 1)
            {
                printf(", ");
            }
        }
        printf(" }\n");
    }
}



void PrintMap(Map M)
/* Mencetak elemen-elemen Map M ke layar */
{
    if (IsEmptyMap(M))
    {
        printf("Map is empty.\n");
    }
    else
    {
        printf("{ ");
        for (addr i = 0; i < M.Count; i++)
        {
            PrintSentence(M.Elements[i].Key);
            printf(": ");
            PrintSentence(M.Elements[i].Value);
            if (i < M.Count - 1)
            {
                printf(", ");
            }
        }
        printf(" }\n");
    }
}

int main() {
    List Penyanyi;
    Map Album;
    Set Lagu;

    MakeList(&Penyanyi);
    CreateEmptyMap(&Album);
    CreateEmptySet(&Lagu);

    bacaConfig("bacaConfig.txt", &Penyanyi, &Album, &Lagu);

    // Print the contents of Penyanyi list
    printf("Penyanyi:\n");
    PrintList(&Penyanyi);

    // Print the contents of Album map
    printf("\nAlbum:\n");
    PrintMap(Album);

    // Print the contents of Lagu set
    printf("\nLagu:\n");
    PrintSet(Lagu);

    return 0;
}