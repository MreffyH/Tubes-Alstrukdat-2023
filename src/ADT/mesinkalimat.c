#include "mesinkalimat.h"
#include<stdio.h>

void CopySentence() {
    int i = 0;
    while (currentChar != MARK && i < 99)
    {
        currentSentence[i] = currentChar;
        i++;
        currentChar = getchar();
    }
    currentSentence[i] = '\0';
}

void ADVSENTENCE() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        endSentence = true;
    } else {
        endSentence = false;
        CopySentence();
        IgnoreBlanks();
    }
}