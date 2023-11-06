#include <stdio.h>
#include "src/boolean.h"
#include "src/ADT/header/mesinkar.h"
#include "src/ADT/header/mesinkata.h"

void GetVal(int *n) {
    int idx=0;
    while (currentWord.TabWord[idx] != BLANK)
    {
        *n *= 10;
        *n = n + (currentWord.TabWord[idx] - '0');
        idx++;
    }
    for (int i=idx; i<currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    } 
    printf('\n');
}

int main() {
    while (!EOF)
    {
        int penyanyi, album;
        STARTWORD();
        GetVal(&penyanyi);
        for (int i=0; i<penyanyi; i++)
        {
            ADVNEXT();
            GetVal(&album);
            for (int i=0; i<album; i++)
            {
                ADVNEXT();
                PRINTWORD();
            }
        }

    }
    printf("kelar");
    return 0;
}