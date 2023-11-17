#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
	M->Count_Album = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count_Album == Nil;
}
/* ********** Operator Dasar Map ********* */

void InsertMap(Map *M, keytype Nama_Album, char* Nama_lagu);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMember ((*M), k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    int i = 0;

    while (i < M.Count && !found)
    {
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return found;
}

int main() {
    Map m; CreateEmpty(&m);
    Insert(&m, "iqbal", "ganteng");
    Insert(&m, "adli", "jelek");
    PrintMap(m);

    return 0;
}