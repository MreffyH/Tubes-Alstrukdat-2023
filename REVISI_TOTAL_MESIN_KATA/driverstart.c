/* File: driverstart.c */

#include "start.h"
#include "mesinkata.h"

#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("masuk ke main\n");
    char *file = "config.txt";
    STARTWAYANGWAVE(file);
    return 0;
}