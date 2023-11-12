#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count_Lagu = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count_Lagu == Nil;
}

boolean IsFullSet(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count_Lagu == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, char* Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    S->Penyanyi[S->Count_Lagu] = Elmt;
    S->Count_Lagu++;
}

void DeleteSet(Set *S, char* Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count_Lagu)
    {
        if (S->Penyanyi[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count_Lagu; iterator++)
    {
        S->Penyanyi[iterator - 1] = S->Penyanyi[iterator];
    }
    S->Count_Lagu--;
}

boolean IsMemberSet(Set S, char* Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count_Lagu)
    {
        if (S.Penyanyi[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

void PrintSet(Set s) {
    for (int i=0; i<s.Count_Lagu; i++)
    {
        printf("%s\n", s.Penyanyi[i]);
    }
}

// int main() {
//     Set s;
//     CreateEmpty(&s);
//     Insert(&s, "abcd");
//     Insert(&s, "abcde");
//     Insert(&s, "abcdef");
//     PrintSet(s);
//     return 0;
// }