#include <stdio.h>
#include "..\header\stack.h"

void CreateEmptyStack(Stack *S) 
{
    S->TOP = NilS;
}

boolean IsEmptyStack(Stack S) 
{
    return S.TOP == NilS;
}

int LengthStack(Stack S) 
{
    int res = 0; Info temp;
    while (!IsEmptyStack(S))
    {
        Pop(&S, &temp);
        res++;
    }
    return res;
}

boolean IsFullStack(Stack S) 
{
    return S.TOP == MaxEl - 1;
}

void Push(Stack *S, Info X) 
{
    Top(*S)++;
    CreateInfo(&(*S).T[S->TOP], X.Penyanyi, X.Album, X.Lagu);
}

void Pop(Stack *S, Info *X) 
{
    CreateInfo(X, InfoTop(*S).Penyanyi, InfoTop(*S).Album, InfoTop(*S).Lagu);
    Top(*S)--;
}

void DisplayStack(Stack S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack kosong\n");
        return;
    }
    Info temp;
    while (!IsEmptyStack(S))
    {
        Pop(&S, &temp);
        DisplayInfo(temp);
    }

}

// int main()
// {
//     Stack s; CreateEmptyStack(&s);

//     Info I, I2, I3, Temp;
//     Word w1, w2, w3, w4, w5, w6, w7, w8, w9;
//     w1.Length = 5; w2.Length = 5; w3.Length = 5;
//     w4.Length = 3; w5.Length = 3; w6.Length = 3;
//     w7.Length = 1; w8.Length = 1; w9.Length = 1;

//     w1.TabWord[0] = 'i';
//     w1.TabWord[1] = 'q';
//     w1.TabWord[2] = 'b';
//     w1.TabWord[3] = 'a';
//     w1.TabWord[4] = 'l';
//     w2.TabWord[0] = 'f';
//     w2.TabWord[1] = 'a';
//     w2.TabWord[2] = 'r';
//     w2.TabWord[3] = 'e';
//     w2.TabWord[4] = 'l';
//     w3.TabWord[0] = 'z';
//     w3.TabWord[1] = 'a';
//     w3.TabWord[2] = 'r';
//     w3.TabWord[3] = 'e';
//     w3.TabWord[4] = 'i';
//     w4.TabWord[0] = 'a';
//     w4.TabWord[1] = 'b';
//     w4.TabWord[2] = 'c';
//     w5.TabWord[0] = 'd';
//     w5.TabWord[1] = 'e';
//     w5.TabWord[2] = 'f';
//     w6.TabWord[0] = 'x';
//     w6.TabWord[1] = 'y';
//     w6.TabWord[2] = 'z';
//     w7.TabWord[0] = 'q';
//     w8.TabWord[0] = 'w';
//     w9.TabWord[0] = 'e';

//     CreateInfo(&I, w1, w2, w3);
//     CreateInfo(&I2, w4, w5, w6);
//     CreateInfo(&I3, w7, w8, w9);

//     Push(&s, I); Push(&s, I2); Push(&s, I3);
//     // Pop(&s, &Temp);
//     Pop(&s, &Temp);
//     Pop(&s, &Temp);
//     DisplayStack(s);
//     // DisplayInfo(Temp);

//     return 0;
// }
