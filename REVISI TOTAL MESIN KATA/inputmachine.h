/* File: inputmachine.h */
#ifndef __INPUTMACHINE_
#define __INPUTMACHINE_

#include "boolean.h"
#include "mesinkarakter.h"

#define MAXINPUT 80
#define ENTER '\n'

typedef struct {
    char TabInput[MAXINPUT + 1];
    int LengthInput;
} Input;

extern boolean ENDINPUT;
extern Input currentInput;

void IGNORENEWLINE();

void STARTINPUT();

void COPYINPUT();

void RESETINPUT();

boolean INPUTEQUAL(Input I, char *K);

int FUNGSILENGTH(char *K);
#endif