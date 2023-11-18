// File: circular_queue.c

#include <stdio.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
{
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
{
    return (Length(Q) == IDX_MAX + 1);
}

int Length (Queue Q)
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
{
    if (IsEmpty(Q)) {
        return 0;
    } else if (Q.idxHead <= Q.idxTail) {
        return (Q.idxTail - Q.idxHead + 1);
    } else {
        return (Q.idxTail - Q.idxHead + 1 + (IDX_MAX + 1));
    }
}

/* *** Kreator *** */
void CreateQueue (Queue * Q)
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */
{
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}

/* *** Primitif Add/Delete *** */
void enqueue (Queue * Q, ElType X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
{
    if (IsEmpty(*Q)) {
        Q->idxHead = 0;
        Q->idxTail = 0;
    } else {
        Q->idxTail = (Q->idxTail + 1) % (IDX_MAX + 1);
    }
    Q->Tab[Q->idxTail] = X;
}

ElType dequeue (Queue * Q)
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    // KAMUS LOKAL
    ElType X;
    // ALGORITMA
    X = Q->Tab[Q->idxHead];
    if (Q->idxHead == Q->idxTail) {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    } else {
        Q->idxHead = (Q->idxHead + 1) % (IDX_MAX + 1);
    }
}

/* *** Display Queue *** */
void displayQueue(Queue Q)
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer; */
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
{
    //KAMUS
    int i;

    // ALGORITMA
    if (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF) {
        printf("[]\n");
    } else {
        printf("[");
        if (Q.idxHead <= Q.idxTail) {
            for (i = Q.idxHead; i <= Q.idxTail; i++) {
                if (i == Q.idxTail) {
                    printf("%d", Q.Tab[i]);
                } else {
                    printf("%d,", Q.Tab[i]);
                }
            }
        } else {
            for (i = Q.idxHead; i < (IDX_MAX + 1); i++) {
                printf("%d,", Q.Tab[i]);
            }
            for (i = 0; i <= Q.idxTail; i++) {
                if (i == Q.idxTail) {
                    printf("%d", Q.Tab[i]);
                } else {
                    printf("%d,", Q.Tab[i]);
                }
            }
        }
        printf("]\n");
    }
}