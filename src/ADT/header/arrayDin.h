#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include <stdio.h>
#include <stdlib.h>
// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#include "..\..\boolean.h"
#include "listsirkuler.h" 

#define InitialSize 20

typedef int IdxType;

typedef struct {
    List *A;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeAD();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateAD(ArrayDin *arr);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyAD(ArrayDin arr);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthAD(ArrayDin arr);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Word GetPlayListName(ArrayDin arr, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAD(ArrayDin *arr, List el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *arr, IdxType i);

/**
 * Prosedur untuk mengoutput semua isi array dynamic
 */
void DisplayAD(ArrayDin arr);

#endif