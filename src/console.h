#ifndef console_H
#define console_H
#include <stdio.h>
#include "boolean.h"
#include "map.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100

typedef int address;

typedef struct
{
    Map  Album;
    char Penyanyi[MaxEl][MaxEl];
    int  Count_Penyanyi;
} Data;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */


#endif 