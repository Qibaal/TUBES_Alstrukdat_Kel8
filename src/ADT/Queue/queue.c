#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q) {
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return q.idxTail == CAPACITY - 1;
}

int length(Queue q) {
    return (q.idxTail-q.idxHead) + 1;
}

void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else 
    {
        if (q->idxTail == CAPACITY-1) { 
            for (int i=q->idxHead; i<=q->idxTail; i++) {
                q->buffer[i-q->idxHead] = q->buffer[i];
            }
            q->idxTail -= q->idxHead;
            q->idxHead = 0;
        }
        q->idxTail++;
    }
    TAIL(*q) = val;
    
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (q->idxHead == q->idxTail) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        q->idxHead++;
    }
}

void displayQueue(Queue q) {
    for (int i=q.idxHead; i<=q.idxTail; i++) {
        q.buffer[i-q.idxHead] = q.buffer[i];
    }
    q.idxTail -= q.idxHead;
    q.idxHead = 0;
    if (isEmpty(q)) 
    {
        printf("[]\n");
    } else
    {
        printf("[");
        for (int i=0; i<length(q)-1; i++) 
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", TAIL(q));
    }
}

Queue tanpaBomb(Queue queue, ElType bomb) {
    Queue q;
    CreateQueue(&q);
    int i, len = length(queue);
    ElType temp;
    int nums[len];
    i=0;
    while (i<len) 
    {
        temp = 0;
        dequeue(&queue, &temp);
        if (temp == bomb) nums[i] = -9999;
        else nums[i] = temp;
        i++;
    }
    i=0;
    while (i<len)
    { 
        if (nums[i] != -9999) enqueue(&q, nums[i]);
        i++;
    }
    return q;
}

void copyQueue(Queue *queueInput, Queue *queueOutput) {
    ElType temp;
    int len = length(*queueInput);
    if (!isEmpty(*queueInput))
    {
        int i=0;
        while (i<len)
        {   
            dequeue(queueInput, &temp);
            enqueue(queueOutput, temp);
            enqueue(queueInput, temp);
            i++;
        }
    }
}

ElType minValue(Queue q) {
    ElType min = 0;
    int temp, len = length(q);
    int nums[len];
    for (int i=0; i<len; i++)
    {
        dequeue(&q, &temp);
        nums[i] = temp;
        if (min == 0 || min > temp) min = temp;
        enqueue(&q, temp);
    }
    return min;
}

ElType maxValue(Queue q) {
    ElType max = 0;
    int temp, len = length(q);
    int nums[len];
    for (int i=0; i<len; i++)
    {
        dequeue(&q, &temp);
        nums[i] = temp;
        if (max == 0 || max < temp) max = temp;
        enqueue(&q, temp);
    }
    return max;
}