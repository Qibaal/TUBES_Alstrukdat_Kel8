#include <stdio.h>
#include <stdlib.h>
#include "..\header\listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L)==Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L)=Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address p = (address) malloc(sizeof(infotype));
    if (p!=NULL) {
        Info(p) = X;
        Next(p) = Nil;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P;
    P=First(L);
    boolean found=false;
    if (!IsEmpty(L)){
        do{
            if ((Info(P).Nama_Penyanyi == X.Nama_Penyanyi) && (Info(P).Nama_Album == X.Nama_Album) && (Info(P).Info_Lagu).Elements[MaxEl] == (X.Info_Lagu).Elements[MaxEl]) { 
                found = true;
            } else {
                P = Next(P);
            }
        } while ((!found) && (P != First(L)));
    }
    if (!found){
        P=Nil;
    } 
    return (P);
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P;
    P=Alokasi(X);
    if (P!=Nil){
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P;
    P=Alokasi(X);    
    if (P!=Nil){
        InsertLast(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
	address P;
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(P);
}

/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    InsertLast(L, P);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        First(*L)=P;
        Next(P)=P;
    } else{
        address P1=First(*L);
        while (Next(P1)!=First(*L)){
            P1=Next(P1);
        }
        Next(P1)=P;
        Next(P)=First(*L);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    Next(P)=Next(Prec);
    Next(Prec)=P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    address last = First(*L);
    if (Next(last) == First(*L))
    {
        (*P) = First(*L);
        CreateEmpty(L);
    }
    else
    {
        while (Next(last) != First(*L))
        {
            last = Next(last);
        }
        DelAfter(L, P, last);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    address last = First(*L);
    if (Next(last) == First(*L))
    {
        (*P) = First(*L);
        CreateEmpty(L);
    }
    else
    {
        while (Next(Next(last)) != First(*L))
        {
            last = Next(last);
        }
        DelAfter(L, P, last);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    if (Next(Prec) == First(*L))
    {
        First(*L) = Next(Next(Prec));
    }
    if (Next(First(*L)) == First(*L))
        CreateEmpty(L);
    else
    {
        (*Pdel) = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    }    
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
    address P = Search(*L, X);
    if (P != Nil)
    {
        address prev = First(*L);
        if (Next(prev) == First(*L))
            CreateEmpty(L);
        else
        {
            while (Next(prev) != P)
            {
                prev = Next(prev);
            }
            DelAfter(L, &P, prev);
            Dealokasi(P);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address P=First(L);
        printf("%d",Info(P));
        P=Next(P);
        while (P!=First(L)){
            printf(",%d",Info(P));
            P=Next(P);
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */