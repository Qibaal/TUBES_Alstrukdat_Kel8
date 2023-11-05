#include <stdio.h>
#include "listdefault2.h"

void listAlbum(AlbumPenyanyi albumPenyanyi)
{
    int i = 0;
    for (i; i < albumPenyanyi.jumlahAlbum; i++)
    {
        printf("%d. ", i+1);
        PrintWord(albumPenyanyi.namaAlbum.A[MaxEl]);
        printf("\n");
    }
}