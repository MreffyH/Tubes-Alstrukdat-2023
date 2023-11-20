#include <stdio.h>

/* Include ADT */
#include"mesinkarakter.h"
#include "mesinkata.h"

/* Include WayangWave */
#include"start.h"

int main(){
    boolean mulaiWayangWave = true;
    while (mulaiWayangWave)
    {
        STARTINPUT();
        if (INPUTEQUAL(currentInput, "START")) {
            printf("masuk ke start\n");
            char *file = "user1.txt";
            STARTWAYANGWAVE(file);
        }
    }
}