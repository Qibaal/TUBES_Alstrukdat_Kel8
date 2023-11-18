#ifndef info_H
#define info_H

#include <stdio.h>
#include "..\..\boolean.h"
#include "mesinkata.h"

/*playlist type*/
typedef Word PType;

typedef struct {
    PType Penyanyi;
    PType Album;
    PType Lagu;
} Info;

void CreateInfo (Info *I, Word penyanyi, Word album, Word lagu);
/* I.S. d sembarang. penyanyi, album, dan lagu yang terdefinisi (mungkin kosong). */
/* F.S. d menjadi detail dengan isi pennyanyi, album, dan lagu. */

boolean IsEmptyD (Info I);
/* Fungsi untuk mengecek jika isi d kosong (penyanyi kosong, album kosong, dan lagu kosong) */
/* Prekondisi d terdefinisi. */

void InsertInfoType(PType *I, Word w);
/* Set Masing2 infotype dengan Word */

void DisplayInfo (Info I);

#endif