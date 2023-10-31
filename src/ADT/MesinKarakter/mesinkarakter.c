#include "mesinkarakter.h"
#include <stdio.h>

char CurrentChar;
boolean EOP;

FILE *pita;
static int retval;

void Start() {
    pita = stdin;
    Adv();
}

void Adv() {
    retval = fscanf(pita, "%c", &CurrentChar);
    EOP = (CurrentChar == Mark);
    if (EOP) 
    {
        fclose(pita);
    }
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return (CurrentChar == Mark);
}