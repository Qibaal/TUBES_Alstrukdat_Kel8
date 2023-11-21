#include <stdio.h>
#include "..\header\queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;  IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQ(Queue q)
{
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q)
{
    if (IDX_HEAD(q) > IDX_TAIL(q)) {
        return IDX_HEAD(q) - IDX_TAIL(q) == 1;
    } else {
        return IDX_HEAD(q) == 0 && IDX_TAIL(q) == IDX_MAX; 
    }
}

int length(Queue q)
{
    if (isEmptyQ(q)) {
        return 0;
    } else if (IDX_HEAD(q) > IDX_TAIL(q)) {
        return IDX_MAX - IDX_HEAD(q) + IDX_TAIL(q) + 2;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Info val)
{
    if (isEmptyQ(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if (IDX_TAIL(*q) == IDX_MAX)
        {
            IDX_TAIL(*q) = 0;
        }
        else
        {
            IDX_TAIL(*q) += 1;
        }
    }
    CreateInfo(&TAIL(*q), val.Penyanyi, val.Album, val.Lagu);
}

void dequeue(Queue *q, Info *val)
{
    CreateInfo(val, HEAD(*q).Penyanyi, HEAD(*q).Album, HEAD(*q).Lagu);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        if (IDX_HEAD(*q) == IDX_MAX) 
        {
            IDX_HEAD(*q) = 0;
        }
        else
        {
            IDX_HEAD(*q) += 1;
        }
    }
}

void RemoveQueue(Queue *q, Info *del, int idx)
{
    Queue temp; CreateQueue(&temp);
    Info iTemp;
    if (idx <= 0 || idx > length(*q))
    {
        printf("Lagu dengan urutan ke %d tidak ada.\n", idx);
        return;
    }
    int ctr = 0;
    while (!isEmptyQ(*q))
    {
        if (ctr == idx - 1)
        {
            dequeue(q, del);
        }
        else
        {
            dequeue(q, &iTemp);
            enqueue(&temp, iTemp);
        }
        ctr++;
    }
    if (!isEmptyQ(*q)) printf("gagal\n");
    else
    {
        while (!isEmptyQ(temp))
        {
            dequeue(&temp, &iTemp);
            enqueue(q, iTemp);
        }
    }
}

// void SwapQueue(Queue *q, int x, int y)
// {
//     Queue temp; CreateQueue(&temp);
//     Info iTemp, xTemp, yTemp;
//     int ctr;
//     if (x > y)
//     {
//         int temp = x;
//         x = y;
//         y = temp;
//     }
//     if (x <= 0 || x > length(*q))
//     {
//         printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
//         return;
//     }
//     else if (y <= 0 || y > length(*q))
//     {
//         printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
//         return;
//     }
//     RemoveQueue(q, &xTemp, x);
//     RemoveQueue(q, &yTemp, y-1);
//     // masukin balik lagi
//     ctr = 0;
//     if (!isEmptyQ(*q)) printf("gagal\n");
//     else
//     {
//         while (!isEmptyQ(temp))
//         {
//             if (ctr + 1 == x)
//             {
//                 enqueue(q, yTemp);
//             }
//             else if (ctr + 1 == y)
//             {
//                 enqueue(q, xTemp);
//             }
//             else
//             {
//                 dequeue(&temp, &iTemp);
//                 enqueue(q, iTemp);
//             }
//             ctr++;
//         }
//     }
// }

void ClearQueue(Queue *q)
{
    Info temp;
    while (!isEmptyQ(*q)) dequeue(q, &temp);
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isEmptyQ(q)) printf("kosong\n");
    else
    {
        int i = IDX_HEAD(q);
        while (i != IDX_TAIL(q)+1)
        {
            DisplayInfo(q.buffer[i]);
            i = (i+1) % (IDX_MAX);
        }
    }
}

void SwapQueue(Queue *q, int x, int y)
{
    Info temp; int iTemp;
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    /*Out of range handling*/
    if (x <= 0 || x > length(*q))
    {
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        return;
    }
    else if (y <= 0 || y > length(*q))
    {
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        return;
    }
    for (int i=0; i<IDX_MAX+1; i++)
    {
        if (i == x + IDX_HEAD(*q) - 1)
        {
            iTemp = i;
            CreateInfo(&temp, q->buffer[i].Penyanyi, q->buffer[i].Album, q->buffer[i].Lagu);
        }
        else if (i == y + IDX_HEAD(*q) - 1)
        {
            CreateInfo(&(*q).buffer[iTemp], q->buffer[i].Penyanyi, q->buffer[i].Album, q->buffer[i].Lagu);
            CreateInfo(&(*q).buffer[i], temp.Penyanyi, temp.Album, temp.Lagu);
        }
    }
}

// int main()
// {
//     Queue Q; CreateQueue(&Q);
    
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

//     enqueue(&Q, I); enqueue(&Q, I2); enqueue(&Q, I3);
//     displayQueue(Q);
//     printf("---------------------\n");
//     SwapQueue(&Q, 3, 2);
//     displayQueue(Q);
//     return 0;
// }