#ifndef __LISTDEFAULT2_H__
#define __LISTDEFAULT2_H__

#include <stdio.h>
#include "../src/boolean.h"
#include "../../ADT/ListStatik/liststatik.h"
#include "../../ADT/MesinKata/mesinkata.h"

typedef struct
{
    Word namaPenyanyi;
    List namaAlbum;
    int jumlahAlbum;
} AlbumPenyanyi;

void listAlbum(AlbumPenyanyi albumPenyanyi);

#endif