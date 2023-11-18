/* File history.h */

/* ADT History berfungsi untuk menampilkan lagu-lagu yang pernah dimainkan oleh user selama */
#ifndef HISTORY_H
#define HISTORY_H

#define Newline '\n'

#include <stdio.h>
#include "stack.h"
#include "mesinkata.h"
#include "queue.h"

void history (Stack historySong, Word Command);
/* Menampilkan seluruh riwayat lagu yang telah diputar oleh user 
    I.S. sembarang
    F.S. menampilkan seluruh current song yang sudah dimainkan. History mungkun kosong */

#endif

