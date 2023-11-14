#ifndef map_H
#define map_H
#include <stdio.h>
#include "boolean.h"
#include "..\src\ADT\Set\set.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100
#define Undefined ""

// typedef int bool;
typedef char* keytype;
typedef char* valuetype;

typedef struct {
	keytype 	 Nama_Album;
	Set			 Lagu;    ;
} Lagu;

typedef struct {
	Lagu  Elements[MaxEl];
	int   Count_Album;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

void CreateEmptyMap(Map *M);

boolean IsEmptyMap(Map M);

void InsertMap(Map *M, keytype Nama_Album, char* Nama_lagu);

#endif