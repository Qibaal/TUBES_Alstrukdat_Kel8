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

    M->Elements[M->Count_Album].Nama_Penyanyi = nama_penyanyi;
    M->Elements[M->Count_Album].Nama_Album = nama_album;
    // M->Count_Album++;
    
    // saat mau masukin lagu gausah create empty lagi
    // CreateEmptySet(M->Elements[M->Count_Album].Info_Lagu);
}

// void InsertLagu(Map *M, infotype lagu)
// {
//     int len = M->Elements[M->Count_Album-1].Info_Lagu.Count_Lagu;
//     int jumlah_lagu = M->Elements[M->Count_Album].Info_Lagu.Count_Lagu;
//     // InsertSet(M->Elements[M->Count_Album]->Info_Lagu, lagu);
//     // tiap insert tambahin jumlah lagu
//     M->Elements[M->Count_Album].Info_Lagu.Count_Lagu++;
// }

boolean IsMemberMap(Map M, keytype nama_penyanyi, valuetype nama_album)
/* Mengembalikan true jika penyanyi dan album adalah member dari M */
{
    boolean found = false;
    int i = 0;
    while (i < M.Count_Album && !found)
    {
        if (isSame(M.Elements[i].Nama_Penyanyi, nama_penyanyi) && isSame(M.Elements[i].Nama_Album, nama_album))
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