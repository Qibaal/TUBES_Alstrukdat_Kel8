#include "..\header\set.h"

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
void InsertSet(Set *S, Word Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!IsMemberSet(*S, Elmt))
    {
        // S->Elements[S->Count_Lagu].Length = 0;
        for (int i=0; i<Elmt.Length; i++)
        {
            S->Elements[S->Count_Lagu].TabWord[i] = Elmt.TabWord[i];
            S->Elements[S->Count_Lagu].Length++;
        }
        S->Count_Lagu++;
    }
}

// void Delete(Set *S, infotype Elmt)
// /* Menghapus Elmt dari Set S. */
// /* I.S. S tidak kosong
//         Elmt mungkin anggota / bukan anggota dari S */
// /* F.S. Elmt bukan anggota dari S */
// {
//     boolean found = false;
//     address idx = 0, iterator;
//     if (!IsMember(*S, Elmt))
//     {
//         return;
//     }
//     while (!found && idx < S->Count)
//     {
//         if (S->Elements[idx] == Elmt)
//         {
//             found = true;
//         }
//         else
//         {
//             idx++;
//         }
//     }
//     for (iterator = idx + 1; iterator < S->Count; iterator++)
//     {
//         S->Elements[iterator - 1] = S->Elements[iterator];
//     }
//     S->Count--;
// }

boolean IsMemberSet(Set S, Word Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    int idx = 0;
    while (idx < S.Count_Lagu)
    {
        if (WordCompare(Elmt, S.Elements[idx]))
        {
            return true;
        }
        idx++;
    }
    return false;
}

boolean isSame(Word w1, Word w2)
{
    boolean IsSame = true;
    if (w1.Length != w2.Length) 
    {
        IsSame = false;
    }
    else 
    {
        int i = 0;
        while (IsSame && i < w1.Length) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                IsSame = false;
            }
            i++;
        }
    }
    return IsSame;
}

void PrintSet(Set S) 
{
    for (int i=0; i<S.Count_Lagu; i++)
    {
        PRINTWORD(S.Elements[i]);
    }
}

// int main() {
//     Set s;
//     CreateEmptySet(&s);
//     Word w1, w2, w3;
//     w1.Length = 5; w2.Length = 5; w3.Length = 5;
//     w1.TabWord[0] = 'i';
//     w1.TabWord[1] = 'q';
//     w1.TabWord[2] = 'b';
//     w1.TabWord[3] = 'a';
//     w1.TabWord[4] = 'l';
//     w2.TabWord[0] = 'f';
//     w2.TabWord[1] = 'a';
//     w2.TabWord[2] = 'r';
//     w2.TabWord[3] = 'e';
//     w2.TabWord[4] = 'l';
//     w3.TabWord[0] = 'f';
//     w3.TabWord[1] = 'a';
//     w3.TabWord[2] = 'r';
//     w3.TabWord[3] = 'e';
//     w3.TabWord[4] = 'i';
//     InsertSet(&s, w1);
//     InsertSet(&s, w2);
//     InsertSet(&s, w3);
//     PrintSet(s);
//     printf("%d", s.Count_Lagu);
//     return 0;
// }