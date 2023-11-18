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
void InsertSet(Set *S, char* Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMemberSet(*S, Elmt))
    {
        return;
    }
    int n = StrLen(Elmt);
    for (int i=0; i<n; i++)
    {
        S->Elements[S->Count_Lagu][i] = Elmt[i];
    }
    S->Count_Lagu++;
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

boolean IsMemberSet(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    int idx = 0, iterator;
    while (!found && idx < S.Count_Lagu)
    {
        if (isSame(S.Elements[idx], Elmt))
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

boolean isSame(char* s1, char* s2) {
    boolean IsSame = true;
    int n1 = StrLen(s1), n2 = StrLen(s2);
    if (n1 != n2) {
        IsSame = false;
    }
    else {
        int i = 0;
        while (IsSame && i < n1) {
            if (s1[i] != s2[i]) {
                IsSame = false;
            }
            i++;
        }
    }
    return IsSame;
}

int StrLen(char* s) {
    int i;
    for (i=0; s[i] != '\0'; ++i);
    return i;
}

void PrintSet(Set S) {
    for (int i=0; i<S.Count_Lagu; i++)
    {
        printf("%s\n", S.Elements[i]);
    }
}

// int main() {
//     Set s;
//     CreateEmptySet(&s);
//     InsertSet(&s, "iqbal");
//     InsertSet(&s, "favian");
//     InsertSet(&s, "favian");
//     InsertSet(&s, "iqbal");
//     PrintSet(s);
//     return 0;
// }