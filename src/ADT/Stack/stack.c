#include <stdio.h>
#include "stack.h"

void CreateEmpty(Stack *S) {
    S->TOP = Nil;
}

boolean IsEmpty(Stack S) {
    return S.TOP == Nil;
}

int Length(Stack S) {
    if (IsEmpty(S)) return 0;
    else return Top(S) + 1;
}

boolean IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

void Push(Stack * S, InfoStack X) {
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack * S, InfoStack* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}

void PrintStack(Stack S) {
    InfoStack temp;
    while (!IsEmpty(S))
    {
        Pop(&S, &temp);
        
        printf("%d ", temp);
    }
}
