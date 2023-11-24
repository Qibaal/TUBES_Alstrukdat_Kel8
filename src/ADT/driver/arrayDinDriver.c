#include <stdio.h>
#include "..\header\arrayDin.h"

int main()
{
    ArrayDin a = MakeAD();

    List L1, L2; 
    CreateEmptyList(&L1); CreateEmptyList(&L2);

    Info I, I2, I3, Temp;
    Word w1, w2, w3, w4, w5, w6, w7, w8, w9;
    w1.Length = 5; w2.Length = 5; w3.Length = 5;
    w4.Length = 3; w5.Length = 3; w6.Length = 3;
    w7.Length = 1; w8.Length = 1; w9.Length = 1;

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
    w3.TabWord[0] = 'z';
    w3.TabWord[1] = 'a';
    w3.TabWord[2] = 'r';
    w3.TabWord[3] = 'e';
    w3.TabWord[4] = 'i';
    w4.TabWord[0] = 'a';
    w4.TabWord[1] = 'b';
    w4.TabWord[2] = 'c';
    w5.TabWord[0] = 'd';
    w5.TabWord[1] = 'e';
    w5.TabWord[2] = 'f';
    w6.TabWord[0] = 'x';
    w6.TabWord[1] = 'y';
    w6.TabWord[2] = 'z';
    w7.TabWord[0] = 'q';
    w8.TabWord[0] = 'w';
    w9.TabWord[0] = 'e';

    CreateInfo(&I, w1, w2, w3);
    CreateInfo(&I2, w4, w5, w6);
    CreateInfo(&I3, w7, w8, w9);

    InsertWord(&L1.Nama, I.Penyanyi); InsertWord(&L2.Nama, I2.Penyanyi);
    InsVLast(&L1, I); InsVLast(&L1, I2); InsVLast(&L1, I3); 
    InsVLast(&L2, I); InsVLast(&L2, I2); InsVLast(&L2, I3);
    
    InsertAD(&a, L1); InsertAD(&a, L2);

    DisplayAD(a);

    DeleteAt(&a, 0);

    DisplayAD(a); 

    printf("%d", LengthAD(a));

    return 0;
}