#include <stdio.h>
#include "..\header\set.h"

int main() {
    Set s;
    CreateEmptySet(&s);
    Word w1, w2, w3;
    w1.Length = 5; w2.Length = 5; w3.Length = 5;
    w1.TabWord[0] = 'i';
    w1.TabWord[1] = 'q';
    w1.TabWord[2] = 'b';
    w1.TabWord[3] = 'a';
    w1.TabWord[4] = 'l';
    w2.TabWord[0] = 'f';
    w2.TabWord[1] = 'a';
    w2.TabWord[2] = 'r';
    w2.TabWord[3] = 'e';
    w2.TabWord[4] = 'l';
    w3.TabWord[0] = 'f';
    w3.TabWord[1] = 'a';
    w3.TabWord[2] = 'r';
    w3.TabWord[3] = 'e';
    w3.TabWord[4] = 'i';
    InsertSet(&s, w1);
    InsertSet(&s, w2);
    InsertSet(&s, w3);
    PrintSet(s);
    printf("%d", s.Count_Lagu);
    return 0;
}