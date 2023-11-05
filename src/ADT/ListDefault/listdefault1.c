#include <stdio.h>
#include "listdefault1.h"


void listPenyanyi(TabInt daftarPenyanyi)
{
    int i = 0;
    for (i; i < daftarPenyanyi.Neff; i++)
    {
        printf("%d. ", i+1);
        PrintWord(daftarPenyanyi.TI[i]);
        printf("\n");
    }
}

void listLagu(Album albumLagu)
{
    int i = 0;
    for (i; i < albumLagu.jumlahLagu; i++)
    {
        printf("%d. ", i+1);
        PrintWord(albumLagu.namaLagu.Elements[i]);
        printf("\n");
    }
}

