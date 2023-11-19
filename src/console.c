#include "console.h"

ArrayDin LOPlaylist;
List PlayList;
Map DATA;
Queue QOSongs;
Stack SongHistory;
Set Artists;
Info CurrSong;
int jumlah_penyanyi, jumlah_album, jumlah_lagu;

void STARTCONSOLE(Map* D, Set* A, char* file)
{
    CreateEmptyMap(D);
    CreateEmptySet(A);
    /*Pembentukan path file untuk di read*/
    char pth[] = "ADT/MesinKarakter/", dest[MaxEl];
    ConcatString(dest, pth, file);
    /*start pembacaan untuk file*/
    STARTWORD(dest);
    /*ambil jumlah penyanyi -- line paling atas*/
    ADVNEXT(true);
    jumlah_penyanyi = val;
    /*lanjut pembacaan*/
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        ADVNEXT(true); // maju ke line album
        jumlah_album = val; // ngambil jumlah album
        InsertSet(A, currentWord); // masukin nama penyanyi
        
        Word artist;
        InsertWord(&artist, currentWord);

        for (int i=0; i<jumlah_album; i++) // loop nama album
        {
            // ngambil jumlah lagu yang ada di album dan print nama album
            ADVNEXT(true);
            jumlah_lagu = val;
            
            Word album_name;
            InsertWord(&album_name, currentWord);
            InsertAlbum(D, artist, album_name); // masukin nama penyanyi dan album ke ADT
            CreateEmptySet(&(*D).Elements[D->Count_Album].Info_Lagu);
            for (int i=0; i<jumlah_lagu; i++)
            {
                ADVNEXT(false);
                InsertSet(&(*D).Elements[D->Count_Album].Info_Lagu, currentWord);
            }
            D->Count_Album++;
        }
    }
}

void LOAD();

// void PLAYSONG() {
//     // KAMUS LOKAL
//     Queue queue;
//     List Artist, Album, Songs;
//     int currentSong, loop; // inisiasi fitur loop
//     int songID;
//     // ALGORITMA
//     CreateQueue(&queue);
//     if (isEmpty(queue)) {
//         printf("Tidak ada lagu yang diputar\n");
//     } else {
//         currentSong = dequeue(&queue);
//         if (loop) {
//             printf("Masukkan Nama Penyanyi yang dipilih : %c;\n", Artist);
//             DisplayPlaylist(Album);
//             printf("Masukkan Nama Album yang dipilih : %c;\n", Album);
//             DisplayPlaylist(Songs);
//             printf("Masukkan ID Lagu yang dipilih: %d;\n", songID);
//             enqueue(&queue, currentSong);
//             printf("Memutar lagu %c oleh %c.\n", currentSong, Artist);
//         } else {
//             printf("Memutar lagu %c oleh %c.\n", currentSong, Artist);
//         }
//     }
// }

// void QUEUESONG() {
//     // KAMUS LOKAL
//     Queue queue;
//     List Artist, Album, Songs;
//     int songID;

//     // ALGORITMA
//     CreateQueue(&queue);
//     if (isFull(queue)) {
//         printf("Queue penuh\n");
//     } else {
//         printf("Masukkan Nama Penyanyi: %c;\n", Artist);
//         DisplayPlaylist(Album);
//         printf("Masukkan Nama Album yang dipilih : %c;\n", Album);
//         DisplayPlaylist(Songs);
//         printf("Masukkan ID Lagu yang dipilih: %d;\n", songID);
//         enqueue(&queue, songID);
//         printf("Berhasil menambahkan lagu %c oleh %c ke queue\n", Songs, Artist);
//     }
// }

// void QUEUEPLAYLIST() {
//     // KAMUS LOKAL
//     Queue queue;
//     int playlistID;
//     int m;
//     int song[m][3]; /* Matriks playlist */

//     // ALGORITMA
//     CreateQueue(&queue);
//     printf("Masukkan ID Playlist: %d;\n",playlistID);
//     for (int i = 0; i < 3; i++) {
//         Queue q;
//         if (isFull(queue)) {
//             printf("Queue penuh\n");
//             break;
//         } enqueue(&q, song[playlistID][i]);
//         printf("Berhasil menambahkan playlist %c ke queue.\n");
//     } 
// }
// void QUEUESWAP();
// void QUEUEREMOVE() {
//     // KAMUS LOKAL
//     Queue queue;
//     Word Artist;
//     Word Songs;
//     boolean found = true;
//     int id = 0; /*ID lagu yang dimasukkan*/
//     int i;
    
//     // ALGORITMA
//     CreateQueue(&queue);
//     while (!isEmpty(queue)) {
//         for (i = 0; i < length(queue); i++) {
//             while (id != HEAD(queue) & !found) {
//                 found = false;
//             }
//             printf("Lagu dengan urutan ke %d tidak ada.\n", id);
//         }
//         if (found) {
//             printf("Lagu %c oleh %c telah dihapus dari queue!\n", Songs, Artist);
//         } else {
//             printf("Lagu dengan urutan ke %d tidak ada.\n", id);
//         }
//     }
// }
// void QUEUECLEAR() {
//     // KAMUS LOKAL
//     Queue queue;

//     // ALGORITMA
//     while (!isEmpty(queue)) {
//         CreateQueue(&queue);
//     }
//     printf("Queue berhasil dikosongkan.\n");
// }
