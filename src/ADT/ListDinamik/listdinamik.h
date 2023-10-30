#ifndef LIST_DINAMIK_H
#define LIST_DINAMIK_H

#include "boolean.h"

#define InitialSize 10

typedef int IdxType;
typedef int ElType;
typedef struct {
    ElType *Content;
    int Capacity;
    int Neff;
} ListDinamik;

ListDinamik MakeArrayDin();
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */

void DeallocateArrayDin(ListDinamik *array);
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */

boolean IsEmpty(ListDinamik array);
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */

int Length(ListDinamik array);
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */

ElType Get(ListDinamik array, IdxType i);
/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */

int GetCapacity(ListDinamik array);
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */

void InsertAt(ListDinamik *array, ElType el, IdxType i);
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteAt(ListDinamik *array, IdxType i);
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

#endif