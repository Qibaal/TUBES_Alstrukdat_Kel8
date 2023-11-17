#include <stdio.h>
#include "..\header\map.h"

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

void InsertAlbum(Map *M, keytype nama_penyanyi, valuetype nama_album)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    CreateEmpty(M);
    M->Elements[M->Count_Album].Nama_Penyanyi = nama_penyanyi;
    M->Elements[M->Count_Album].Nama_Album = nama_album;
    M->Count_Album++;
    // saat mau masukin lagu gausah create empty lagi
    CreateEmpty(&M->Elements[M->Count_Album].Info_Lagu);
}

void InsertLagu(Map *M, infotype lagu)
{
    
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika penyanyi dan adalah member dari M */
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

void PrintMap(Map M)
// print nama penyanyi, album, dan lagu-lagu
{
    for (int i=0; i<M.Count_Album; i++)
    {
        printf("%s\n---------------\n", M.Elements[i].Nama_Penyanyi);
        printf("%s\n---------------\n", M.Elements[i].Nama_Album);
        for (int j=0; j<M.Elements[i].Info_Lagu.Count_Lagu; j++)
        {
            printf("%s\n", M.Elements[i].Info_Lagu.Elements[j]);
        }
    }
}
int main() {
    Map m; CreateEmpty(&m);
    Insert(&m, "iqbal", "ganteng");
    Insert(&m, "adli", "jelek");
    PrintMap(m);

    return 0;
}