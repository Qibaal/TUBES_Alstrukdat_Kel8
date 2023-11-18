#include <stdio.h>
#include "console.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyData(Data *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count_Data = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyData(Data S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count_Data == Nil;
}

boolean IsFullData(Data S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count_Data == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void InsertData(Data *S, char* penyanyi, char* album, char* lagu)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!IsMemberSet())

    S->Count_Data++;
}

// void DeleteSet(Set *S, char* Elmt)
// /* Menghapus Elmt dari Set S. */
// /* I.S. S tidak kosong
//         Elmt mungkin anggota / bukan anggota dari S */
// /* F.S. Elmt bukan anggota dari S */
// {
//     boolean found = false;
//     address idx = 0, iterator;
//     if (!IsMemberSet(*S, Elmt))
//     {
//         return;
//     }
//     while (!found && idx < S->Count_Lagu)
//     {
//         if (S->Penyanyi[idx] == Elmt)
//         {
//             found = true;
//         }
//         else
//         {
//             idx++;
//         }
//     }
//     for (iterator = idx + 1; iterator < S->Count_Lagu; iterator++)
//     {
//         S->Penyanyi[iterator - 1] = S->Penyanyi[iterator];
//     }
//     S->Count_Lagu--;
// }

boolean IsMemberData(Set S, char* lagu)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    for (int i=0; i<S.Count_Data; i++)
    {
        for (int j=0; j<S.Album.)
    }
}

void PrintSet(Set s) {
    
}
