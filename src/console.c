#include <stdio.h>
#include "console.h"

/* *** Konstruktor/Kreator *** */
//void CreateEmptyData(Data *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
//{
 //   S->Count_Data = Nil;
//}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
//boolean IsEmptyData(Data S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count_Data == Nil;
}

boolean IsFullData(Data S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count_Data == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void InsertData(Data *S, char* penyanyi, char* album, char* lagu)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!IsMemberSet())

    S->Count_Data++;
}

// void DeleteSet(Set *S, char* Elmt)
// /* Menghapus Elmt dari Set S. */
// /* I.S. S tidak kosong
//         Elmt mungkin anggota / bukan anggota dari S */
// /* F.S. Elmt bukan anggota dari S */
// {
//     boolean found = false;
//     address idx = 0, iterator;
//     if (!IsMemberSet(*S, Elmt))
//     {
//         return;
//     }
//     while (!found && idx < S->Count_Lagu)
//     {
//         if (S->Penyanyi[idx] == Elmt)
//         {
//             found = true;
//         }
//         else
//         {
//             idx++;
//         }
//     }
//     for (iterator = idx + 1; iterator < S->Count_Lagu; iterator++)
//     {
//         S->Penyanyi[iterator - 1] = S->Penyanyi[iterator];
//     }
//     S->Count_Lagu--;
// }

//boolean IsMemberData(Set S, char* lagu)
/* Mengembalikan true jika Elmt adalah member dari S */
//{
//    for (int i=0; i<S.Count_Data; i++)
//  {
//      for (int j=0; j<S.Album.)
//  }
//}

void PrintSet(Set s) {}
void PLAYSONG() {
    // KAMUS LOKAL
    Queue queue;
    List Artist, Album, Songs;
    int currentSong, loop; // inisiasi fitur loop
    int songID;
    // ALGORITMA
    CreateQueue(&queue);
    if (isEmpty(queue)) {
        printf("Tidak ada lagu yang diputar\n");
    } else {
        currentSong = dequeue(&queue);
        if (loop) {
            printf("Masukkan Nama Penyanyi yang dipilih : %c;\n", Artist);
            DisplayPlaylist(Album);
            printf("Masukkan Nama Album yang dipilih : %c;\n", Album);
            DisplayPlaylist(Songs);
            printf("Masukkan ID Lagu yang dipilih: %d;\n", songID);
            enqueue(&queue, currentSong);
            printf("Memutar lagu %c oleh %c.\n", currentSong, Artist);
        } else {
            printf("Memutar lagu %c oleh %c.\n", currentSong, Artist);
        }
    }
}

void QUEUESONG() {
    // KAMUS LOKAL
    Queue queue;
    List Artist, Album, Songs;
    int songID;

    // ALGORITMA
    CreateQueue(&queue);
    if (isFull(queue)) {
        printf("Queue penuh\n");
    } else {
        printf("Masukkan Nama Penyanyi: %c;\n", Artist);
        DisplayPlaylist(Album);
        printf("Masukkan Nama Album yang dipilih : %c;\n", Album);
        DisplayPlaylist(Songs);
        printf("Masukkan ID Lagu yang dipilih: %d;\n", songID);
        enqueue(&queue, songID);
        printf("Berhasil menambahkan lagu %c oleh %c ke queue\n", Songs, Artist);
    }
}
void QUEUEPLAYLIST() {
    // KAMUS LOKAL
    Queue queue;
    int playlistID;
    int m;
    int song[m][3]; /* Matriks playlist */

    // ALGORITMA
    CreateQueue(&queue);
    printf("Masukkan ID Playlist: %d;\n",playlistID);
    for (int i = 0; i < 3; i++) {
        Queue q;
        if (isFull(queue)) {
            printf("Queue penuh\n");
            break;
        } enqueue(&q, song[playlistID][i]);
        printf("Berhasil menambahkan playlist %c ke queue.\n");
    } 
}
void QUEUESWAP();
void QUEUEREMOVE() {
    // KAMUS LOKAL
    Queue queue;
    Word Artist;
    Word Songs;
    boolean found = true;
    int id = 0; /*ID lagu yang dimasukkan*/
    int i;
    
    // ALGORITMA
    CreateQueue(&queue);
    while (!isEmpty(queue)) {
        for (i = 0; i < length(queue); i++) {
            while (id != HEAD(queue) & !found) {
                found = false;
            }
            printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        }
        if (found) {
            printf("Lagu %c oleh %c telah dihapus dari queue!\n", Songs, Artist);
        } else {
            printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        }
    }
}
void QUEUECLEAR() {
    // KAMUS LOKAL
    Queue queue;

    // ALGORITMA
    while (!isEmpty(queue)) {
        CreateQueue(&queue);
    }
    printf("Queue berhasil dikosongkan.\n");
}

