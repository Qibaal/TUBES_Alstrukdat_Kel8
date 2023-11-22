#include <stdio.h>
#include "..\header\arrayDin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeAD()
{
    ArrayDin arr;
    arr.A = (List*) malloc(InitialSize* sizeof(List));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateAD(ArrayDin *arr)
{
    free((*arr).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyAD(ArrayDin arr)
{
    return arr.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthAD(ArrayDin arr)
{
    return arr.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Word GetPlayListName(ArrayDin arr, IdxType i)
{
    return arr.A[i].Nama;
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAD(ArrayDin *arr, List el)
{
    if (arr->Neff == arr->Capacity)
    {
        int newCap = 2*(arr->Capacity);
        List *temp = (List *) realloc(arr->A, newCap * sizeof(List));
        CreateEmptyList(temp);
        if (temp != NULL)
        {
            arr->A = temp;
            arr->Capacity = newCap;
        }
    }
    arr->A[arr->Neff] = el;
    arr->Neff++;
}

/*
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *arr, IdxType i)
{
    for(int j = i ;j<arr->Neff; j++)
    {
        arr->A[j] = arr->A[j+1];
    }
    arr->Neff--;
}

void DisplayAD(ArrayDin arr)
{
    for (int i=0; i<arr.Neff; i++)
    {
        PRINTWORD(arr.A[i].Nama);
        DisplayPlaylist(arr.A[i]);
        printf("---------------------\n");
    }
}

// int main()
// {
//     ArrayDin a = MakeAD();

//     List L1, L2; 
//     CreateEmptyList(&L1); CreateEmptyList(&L2);

//     Info I, I2, I3, Temp;
//     Word w1, w2, w3, w4, w5, w6, w7, w8, w9;
//     w1.Length = 5; w2.Length = 5; w3.Length = 5;
//     w4.Length = 3; w5.Length = 3; w6.Length = 3;
//     w7.Length = 1; w8.Length = 1; w9.Length = 1;

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
//     w3.TabWord[0] = 'z';
//     w3.TabWord[1] = 'a';
//     w3.TabWord[2] = 'r';
//     w3.TabWord[3] = 'e';
//     w3.TabWord[4] = 'i';
//     w4.TabWord[0] = 'a';
//     w4.TabWord[1] = 'b';
//     w4.TabWord[2] = 'c';
//     w5.TabWord[0] = 'd';
//     w5.TabWord[1] = 'e';
//     w5.TabWord[2] = 'f';
//     w6.TabWord[0] = 'x';
//     w6.TabWord[1] = 'y';
//     w6.TabWord[2] = 'z';
//     w7.TabWord[0] = 'q';
//     w8.TabWord[0] = 'w';
//     w9.TabWord[0] = 'e';

//     CreateInfo(&I, w1, w2, w3);
//     CreateInfo(&I2, w4, w5, w6);
//     CreateInfo(&I3, w7, w8, w9);

//     InsertWord(&L1.Nama, I.Penyanyi); InsertWord(&L2.Nama, I2.Penyanyi);
//     InsVLast(&L1, I); InsVLast(&L1, I2); InsVLast(&L1, I3); 
//     InsVLast(&L2, I); InsVLast(&L2, I2); InsVLast(&L2, I3);
    
//     InsertAD(&a, L1); InsertAD(&a, L2);

//     DisplayAD(a);

//     DeleteAt(&a, 0);

//     DisplayAD(a); 

//     printf("%d", LengthAD(a));

//     return 0;
// }