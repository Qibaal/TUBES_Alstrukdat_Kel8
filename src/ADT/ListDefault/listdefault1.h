#ifndef __LISTDEFAULT_H__
#define __LISTDEFAULT_H__

#include <stdio.h>
#include "../src/boolean.h"
#include "../../ADT/Set/set.h"
#include "../../ADT/MesinKata/mesinkata.h"
#include "../../ADT/Array/array.h"

typedef struct 
{
    Word namaAlbum;
    Set namaLagu;
    int jumlahLagu;
} Album;

void listPenyanyi(TabInt daftarPenyanyi);

void listLagu(Album albumLagu);

#endif