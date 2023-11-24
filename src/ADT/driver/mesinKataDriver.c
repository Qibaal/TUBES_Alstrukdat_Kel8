#include <stdio.h>
#include "..\header\mesinkata.h"

int main()
{
    Word w1, w2;
    w1.Length = 5; w2.Length = 5;
    w1.TabWord[0] = 'z';
    w1.TabWord[1] = 'q';
    w1.TabWord[2] = 'b';
    w1.TabWord[3] = 'a';
    w1.TabWord[4] = 'l';

    w2.TabWord[0] = 'Z';
    w2.TabWord[1] = 'Q';
    w2.TabWord[2] = 'B';
    w2.TabWord[3] = 'A';
    w2.TabWord[4] = 'L';

    if (WordCompare(w1,w2)) printf("sama\n");
    else printf("ngga\n");

    return 0;
}