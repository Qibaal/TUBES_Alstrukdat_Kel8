#include <stdio.h>
#include <stdlib.h>
#include "..\header\listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return First(L) == Nill;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
    First(*L) = Nill;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (Info X)
{
    address p = (address) malloc(sizeof(ElmtList));
    if (p != Nill) {
        CreateInfo(&(*p).InfoPlay, X.Penyanyi, X.Album, X.Lagu);
        Next(p) = Nill;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, Info X)
{
    address P = First(L);
    boolean found = false;

    if (!IsEmpty(L)){
        while (!found && P != Nill)
        {
            if (isSame(X.Penyanyi, P->InfoPlay.Penyanyi) &&
                isSame(X.Lagu, P->InfoPlay.Lagu))
            {
                found = true;
            }
            else
            {
                P = Next(P);
            }
        }
    }
    if (!found){
        P = Nill;
    } 
    return P;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast (List *L, Info X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  address P = Alokasi(X);
  if (P != Nill) {
    InsertLast(L, P);
  }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  address Last;

  if (IsEmpty(*L)) {
    InsertFirst(L, P);
  } else {
    Last = First(*L);
    while (Next(Last) != Nill) {
      Last = Next(Last);
    }
    InsertAfter(L, P, Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = Nill;
}

void DelP (List *L, Info X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address Prec;
    address P;
    boolean bFound = false;
    if (!IsEmpty(*L)) 
    {
        P = First(*L);
        if (isSame(X.Penyanyi, P->InfoPlay.Penyanyi) &&
            isSame(X.Lagu, P->InfoPlay.Lagu)) 
        {
            DelFirst(L, &P);
            Dealokasi(&P);
        } 
        else 
        {
            P = First(*L);
            while (!bFound && P != Nill) 
            {
                if (isSame(X.Penyanyi, P->InfoPlay.Penyanyi) &&
                    isSame(X.Lagu, P->InfoPlay.Lagu))
                {
                    bFound = true;
                } 
                else 
                {
                    Prec = P;
                    P = Next(P);
                }
            }
            if (bFound) 
            {
                DelAfter(L, &P, Prec);
                Dealokasi(&P);
            }
        }   
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = Nill;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void DisplayPlaylist (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
{
    if (IsEmpty(L))
    {
        printf("playlist kosong\n");
    }
    else
    {
        address P = First(L);
        while (P != Nill)
        {
            DisplayInfo(P->InfoPlay);
            P = Next(P);
        }
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    address P;

    if (!IsEmpty(L)) 
    {
        P = First(L);
        while (P != Nill) 
        {
            cnt++;
            P = Next(P);
        }
    }
    return cnt;
}