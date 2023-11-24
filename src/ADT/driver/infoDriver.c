#include <stdio.h>
#include "..\header\info.h"

int main() 
{
    Info I;
    Word p, a, l;
    p.Length = 5; a.Length = 5; l.Length = 5;
    scanf("%s", &p.TabWord);
    scanf("%s", &a.TabWord);
    scanf("%s", &l.TabWord);
    CreateInfo(&I, p, a, l);
    DisplayInfo(I);
    return 0;
}