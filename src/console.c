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
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}

void LOAD(ArrayDin *LOP, Info *curr, Stack *hist, Queue *QS)
{
    Info tmp; List tmpL;
    // Inisialisasi tiap ADT
    CreateEmptyStack(hist);
    CreateQueue(QS);
    // LOAD lagu yg sedang dimainin
    ParsePlaylist(&(*curr).Penyanyi, &(*curr).Album, &(*curr).Lagu);
    //LOAD ke queue
    ADVNEXT(true);
    int jumlah_queue = val;
    for (int i=0; i<jumlah_queue; i++)
    {
        ParsePlaylist(&tmp.Penyanyi, &tmp.Album, &tmp.Lagu);
        enqueue(QS, tmp);
    }
    // LOAD ke history (stack)
    ADVNEXT(true);
    int jumlah_stack = val;
    for (int i=0; i<jumlah_stack; i++)
    {
        ParsePlaylist(&tmp.Penyanyi, &tmp.Album, &tmp.Lagu);
        Push(hist, tmp);
    }
    // LOAD KE PLAYLIST
    ADVNEXT(true);
    int jumlah_playlist = val;
    for (int i=0; i<jumlah_playlist; i++)
    {
        ADVNEXT(true);
        jumlah_lagu = val;
        CreateEmptyList(&tmpL);
        InsertWord(&tmpL.Nama, currentWord);
        for (int j=0; j<jumlah_lagu; j++)
        {
            ParsePlaylist(&tmp.Penyanyi, &tmp.Album, &tmp.Lagu);
            InsVLast(&tmpL, tmp);
        }
        InsertAD(LOP, tmpL);
    }
}

void LISTDEFAULT(Map D, Set P)
{
    Word Y; Y.Length = 1; Y.TabWord[0] = 'Y';
    /*Handling kalau gagal start-load*/
    if (IsEmptyMap(D))
    {
        printf("Gagal load untuk file konfigurasi.\n");
        return;
    }

    printf("Daftar Penyanyi :\n");
    for (int i=0; i<P.Count_Lagu; i++)
    {
        printf("%d. ", i+1);
        PRINTWORD(P.Elements[i]);
    }
    printf("Ingin melihat album yang ada?(Y/N): ");
    /*pilih ingin melihat atau tidak*/
    GetInput();
    if (WordCompare(Y, currentWord))
    {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        /*pilih nama penyanyi*/
        GetInput();
        /*Pemrosesan jika ada penyanyi yang sesuai di Set*/
        if (IsMemberSet(P, currentWord))
        {
            /*Print nama album dengan penyanyi yang dipilih*/
            for (int i=0; i<D.Count_Album; i++)
            {
                if (WordCompare(D.Elements[i].Nama_Penyanyi, currentWord))
                {
                    printf("%d. ", i+1);
                    PRINTWORD(D.Elements[i].Nama_Album);
                }
            }
            /*pilih nama Album*/
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            GetInput();
            if (WordCompare(Y, currentWord))
            {
                printf("Pilih album untuk melihat lagu yang ada di album : ");
                /*pilih nama Album*/
                GetInput();
                boolean found = false; int idx = 0;
                while (idx < D.Count_Album && !found)
                {
                    if (WordCompare(D.Elements[idx].Nama_Album, currentWord))
                    {
                        found = true;
                    }
                    else
                    {
                        idx++;
                    }
                }
                if (found)
                {
                    for (int i=0; i<D.Elements[idx].Info_Lagu.Count_Lagu; i++)
                    {
                        printf("%d. ", i+1);
                        PRINTWORD(D.Elements[idx].Info_Lagu.Elements[i]);
                    }
                }
                else
                {
                    printf("Album tidak ditemukan.\n");
                    return;
                }
            }
            else
            {
                return;
            }
        }
        /*Pemrosesan ketika tidak ada atau input salah*/
        else
        {
            printf("Tidak ada penyanyi tersebut.\n");
            return;
        }
    }
    /*Tidak mau melihat album*/
    /*Prosedur langsung dihentikan*/
    else
    {
        return;
    }
}

void LISTPLAYLIST(ArrayDin PL)
{
    printf("Daftar playlist yang kamu miliki:\n");
    if (IsEmptyAD(PL))
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    for (int i=0; i<PL.Neff; i++)
    {
        printf("    %d. ", i+1);
        PRINTWORD(PL.A[i].Nama);
    }    
}

// void PLAYSONG() 
// {
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
