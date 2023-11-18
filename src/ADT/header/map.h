#ifndef map_H
#define map_H
#include <stdio.h>
#include "..\..\boolean.h"
#include "set.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100
#define Undefined ""

// typedef int bool;
typedef int idxtype;
typedef char* keytype;
typedef char* valuetype;

typedef struct {
	keytype		 Nama_Penyanyi;
	valuetype    Nama_Album;
	Set			 Info_Lagu;
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

void InsertAlbum(Map *M, keytype nama_penyanyi, valuetype nama_album);

void InsertLagu(Map *M, infotype lagu);

boolean IsMemberMap(Map M, keytype nama_penyanyi, valuetype nama_album);

void PrintMap(Map M);

#endif