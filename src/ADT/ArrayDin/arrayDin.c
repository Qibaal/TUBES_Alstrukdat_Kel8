#include <stdio.h>
#include "..\header\arrayDin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    ArrayDin arr;
    arr.A = (ElType*) malloc(InitialSize* sizeof(Word));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
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
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    if (array->Neff == array->Capacity){
        array->A = (ElType *) realloc (array->A, array -> Capacity * 2 * sizeof(char));
        array->Capacity *= 2;
    }
    int j;
    for(j=array->Neff;j>i;j--){
        array->A[j]=array->A[j-1];
    }
    array->A[i]=el;
    array->Neff+=1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    int j;
    for(j=i;j<array->Neff;j++){
        array->A[j]=array->A[j+1];
    }
    array->Neff-=1;
}