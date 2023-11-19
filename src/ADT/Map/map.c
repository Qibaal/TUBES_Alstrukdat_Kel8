#include <stdio.h>
#include "..\header\map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
	M->Count_Album = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count_Album == NilMap;
}
/* ********** Operator Dasar Map ********* */

void InsertAlbum(Map *M, keytype nama_penyanyi, valuetype nama_album)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    InsertWord(&(*M).Elements[M->Count_Album].Nama_Penyanyi, nama_penyanyi);
    InsertWord(&(*M).Elements[M->Count_Album].Nama_Album, nama_album);
}

boolean IsMemberMap(Map M, keytype nama_penyanyi, valuetype nama_album)
/* Mengembalikan true jika penyanyi dan album adalah member dari M */
{
    boolean found = false;
    int i = 0;
    while (i < M.Count_Album && !found)
    {
        if (isSame(M.Elements[i].Nama_Penyanyi, nama_penyanyi) && 
            isSame(M.Elements[i].Nama_Album, nama_album))
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
        PRINTWORD(M.Elements[i].Nama_Penyanyi);
        printf("------------\n");
        PRINTWORD(M.Elements[i].Nama_Album);
        printf("------------\n");
        PrintSet(M.Elements[i].Info_Lagu);
        printf("///////////////////\n");
    }
}
// int main() {
//     Map m; CreateEmpty(&m);
//     InsertAlbum(&m, "Adli", "Apres");
//     InsertAlbum(&m, "Iqbal", "gokil");
//     // InsertAlbum(&m, "Radya", "Daffa");
//     // InsertAlbum(&m, "Farras", "Razin");
//     // InsertAlbum(&m, "Raihan", "Razin");
//     printf("%d\n", m.Count_Album);
//     // int n = m.Elements[m.Count_Album-1].Info_Lagu.Count_Lagu;
//     // CreateEmptySet(&m.Elements[m.Count_Album].Info_Lagu);
//     // InsertSet(&m.Elements[m.Count_Album-1].Info_Lagu, "lagu keren");
//     // InsertSet(&m.Elements[m.Count_Album-1].Info_Lagu, "lagu keren2");
//     // for (int i=0; i<3; i++)
//     // {
//     //     InsertLagu(&m, "lagu1", n);
//     //     InsertLagu(&m, "lagu2", n);
//     //     InsertLagu(&m, "lagu3", n);
//     // }
//     PrintMap(m);

//     return 0;
// }