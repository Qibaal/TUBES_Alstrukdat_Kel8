#include "..\header\info.h"
#include <stdio.h>

void CreateInfo (Info *I, Word penyanyi, Word album, Word lagu)
{
    I->Penyanyi.Length = 0; I->Album.Length = 0; I->Lagu.Length = 0;
    InsertInfoType(&(*I).Penyanyi, penyanyi);
    InsertInfoType(&(*I).Album, album);
    InsertInfoType(&(*I).Lagu, lagu);
}

boolean IsEmptyD (Info I)
{
    return I.Penyanyi.Length == 0 && I.Album.Length == 0 && I.Lagu.Length == 0;
}

void InsertInfoType(PType *I, Word w)
{
    for (int i=0; i<w.Length; i++)
    {
        I->TabWord[i] = w.TabWord[i];
        I->Length++;
    }
}

void DisplayInfo (Info I)
{
    printf("Penyanyi: ");
    PRINTWORD(I.Penyanyi);
    printf("Album: ");
    PRINTWORD(I.Album);
    printf("Lagu: ");
    PRINTWORD(I.Lagu);
    // printf("-----------------");
}

// int main() 
// {
//     Info I;
//     Word p, a, l;
//     p.Length = 5; a.Length = 5; l.Length = 5;
//     scanf("%s", &p.TabWord);
//     scanf("%s", &a.TabWord);
//     scanf("%s", &l.TabWord);
//     CreateInfo(&I, p, a, l);
//     DisplayInfo(I);
//     return 0;
// }