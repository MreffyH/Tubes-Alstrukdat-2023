/* File = inputmachine.c */
#include "inputmachine.h"

#include<stdio.h>
#include<stdlib.h>

boolean ENDINPUT;
Input currentInput;

void IGNORENEWLINE() {
    while (currentChar == ' ')
    {
        ADV();
    }
    
}

void STARTINPUT() {
    START();
    IGNORENEWLINE();
    if (currentChar == ';')
    {
        ENDINPUT = true;
    } else {
        ENDINPUT = false;
        COPYINPUT();
    }
    
}

void COPYINPUT() {
    RESETINPUT();
    int i = 0;
    while ((currentChar != ';') && (currentChar != '\n') && (currentChar != EOF))
    {
        currentInput.TabInput[i] = currentChar;
        i++;
        ADV();
    }
    currentInput.LengthInput = i;
}

void RESETINPUT() {
    for (int i = 0; i < sizeof(currentInput); i++)
    {
        currentInput.TabInput[i] = '\0';
        currentInput.LengthInput = 0;
    }
}

