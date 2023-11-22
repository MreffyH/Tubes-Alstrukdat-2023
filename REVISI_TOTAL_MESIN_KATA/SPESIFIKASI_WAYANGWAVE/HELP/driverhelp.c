#include <stdio.h>
#include <stdlib.h>
#include "help.h"
// gcc -o driverhelp driverhelp.c help.c ../../mesinkata.c ../../mesinkarakter.c 

int main(){
    STARTINPUT();
    if (INPUTEQUAL(currentInput, "HELPBEFORE"))
    {
        helpBefore();
    }
    if (INPUTEQUAL(currentInput, "HELPAFTER"))
    {
        helpAfter();
    }
    return 0;
}