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
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
boolean isFull(Queue q)
{
    return (IDX_TAIL(q) - IDX_HEAD(q) + 1 == CAPACITY);
}

int length(Queue q)
{
    if (isEmpty(q)) 
    {
        return 0;
    }
    else
    {
        if (IDX_TAIL(q) >= IDX_HEAD(q))
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
        else
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1 + CAPACITY);
        }
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if (IDX_TAIL(*q) == CAPACITY - 1)
        {
            IDX_TAIL(*q) = 0;
        }
        else
        {
            IDX_TAIL(*q) += 1;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        if (IDX_HEAD(*q) == CAPACITY - 1) 
        {
            IDX_HEAD(*q) = 0;
        }
        else
        {
            IDX_HEAD(*q) += 1;
        }
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");

        if (IDX_TAIL(q) - IDX_HEAD(q) < 0)
        {
            for (i = IDX_HEAD(q); i <= CAPACITY - 1; i++)
            {
                printf("%c,", q.buffer[i]);
            }
            for (i = 0; i < IDX_TAIL(q); i++)
            {
                printf("%c,", q.buffer[i]);
            }
        }

        else 
        {
            for (i = IDX_HEAD(q); i < IDX_TAIL(q); i++)
            {
                printf("%c,", q.buffer[i]);
            }
        }
    }
    printf("%c]\n", TAIL(q));
}