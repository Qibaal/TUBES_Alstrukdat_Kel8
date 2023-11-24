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