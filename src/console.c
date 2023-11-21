#include "console.h"

// ArrayDin LOPlaylist;
// List PlayList;
// Map DATA;
// Queue QOSongs;
// Stack SongHistory;
// Set Artists;
// Info CurrSong;
int jumlah_penyanyi, jumlah_album, jumlah_lagu;

Word WSTART, WLOAD, WLISTD, WLISTP, WPLAYS, WPLAYP, WQSONG, WQPL, WQSWAP, WQREMOVE, WQC, WSNEXT, WSPREV, WPCREATE, WPADDS, WPADDA, WPSWAP, WPREMOVE, WPDELETE, WSTATUS, WSAVE, WQUIT, WHELP;    

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

void LISTDEFAULT(Map *D, Set *P)
{
    Word Y; Y.Length = 1; Y.TabWord[0] = 'Y';

    printf("Daftar Penyanyi :\n");
    for (int i=0; i<P->Count_Lagu; i++)
    {
        printf("    %d. ", i+1);
        PRINTWORD(P->Elements[i]);
    }

    printf("Ingin melihat album yang ada?(Y/N): ");
    /*pilih ingin melihat atau tidak*/
    GetInput();

    if (WordCompare(Y, currentWord))
    {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        /*pilih nama penyanyi*/
        GetInput();
        CompressInput();

        /*Pemrosesan jika ada penyanyi yang sesuai di Set*/
        if (IsMemberSet(*P, currentWord))
        {
            /*Print nama album dengan penyanyi yang dipilih*/
            int k = 1;
            for (int i=0; i<D->Count_Album; i++)
            {
                if (WordCompare(D->Elements[i].Nama_Penyanyi, currentWord))
                {
                    printf("%d. ", k);
                    PRINTWORD(D->Elements[i].Nama_Album);
                    k++;
                }
            }
            /*pilih nama Album*/
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            GetInput();
            CompressInput();

            if (WordCompare(Y, currentWord))
            {
                printf("Pilih album untuk melihat lagu yang ada di album : ");
                /*pilih nama Album*/
                GetInput();
                CompressInput();
                boolean found = false; int idx = 0;
                while (idx < D->Count_Album && !found)
                {
                    if (WordCompare(D->Elements[idx].Nama_Album, currentWord))
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
                    for (int i=0; i<D->Elements[idx].Info_Lagu.Count_Lagu; i++)
                    {
                        printf("%d. ", i+1);
                        PRINTWORD(D->Elements[idx].Info_Lagu.Elements[i]);
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

void PLAYSONG(Info *CURR, Set *A, Map *D, Queue *QS, Stack *hist)
{
    // masukin currentsong ke dalam history
    Push(hist, *CURR);
    /*pemilihan Lagu*/
    printf("Daftar Penyanyi :\n");
    for (int i=0; i<A->Count_Lagu; i++)
    {
        printf("    %d. ", i+1);
        PRINTWORD(A->Elements[i]);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    GetInput();
    CompressInput();
    printf("Daftar Album oleh ");
    PRINTWORD(currentWord);

    int c = 1;
    for (int i=0; i<D->Count_Album; i++)
    {
        if (WordCompare(D->Elements[i].Nama_Penyanyi, currentWord))
        {
            printf("    %d. ", c);
            PRINTWORD(D->Elements[i].Nama_Album);
            c++;
        }
    }
    /*Ambil nama album*/
    printf("Masukkan Nama Album yang dipilih : ");
    GetInput();
    CompressInput();

    int i = 0;
    boolean found_album = false;
    while (i < D->Count_Album && !found_album)
    {
        if (WordCompare(D->Elements[i].Nama_Album, currentWord))
            found_album = true;
        i++;
    }
    printf("Daftar Lagu Album %s oleh %s :\n", D->Elements[i-1].Nama_Album.TabWord, D->Elements[i-1].Nama_Penyanyi.TabWord);
    for (int j=0; j<D->Elements[i-1].Info_Lagu.Count_Lagu; j++)
    {
        printf("    %d. ", j+1);
        PRINTWORD(D->Elements[i-1].Info_Lagu.Elements[j]);
    }
    /*Ambil lagu untuk dimasukin*/
    printf("Masukkan ID Lagu yang dipilih : ");
    GetInput();
    CompressInput();  
    int i_lagu = WordToInt(currentWord);

    printf("Memutar lagu: ");
    PRINTWORD(D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);
    printf("oleh: ");
    PRINTWORD(D->Elements[i-1].Nama_Penyanyi);
    
    /*Update ke currentsong*/
    CreateInfo(CURR, D->Elements[i-1].Nama_Penyanyi, D->Elements[i-1].Nama_Album, D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);

    /*pengosongan queue dan stack riwayat lagu*/
    ClearQueue(QS); 
    while (!IsEmptyStack(*hist))
    {
        Info temp;
        Pop(hist, &temp);
    }
}

void PLAYPLAYLIST(Info *CURR, Set *A, Map *D, Queue *QS, Stack *hist, ArrayDin *LP)
{
    Info temp;

    /*Display Playlist yang dimiliki*/
    LISTPLAYLIST(*LP);
    printf("Masukkan ID Playlist: ");
    /*Ambil ID playlist*/
    GetInput();
    CompressInput();
    int i_pl = WordToInt(currentWord);

    printf("memainkan playlist: ");
    PRINTWORD(LP->A[i_pl-1].Nama);

    /*Current song adalah lagu pertama playlist*/
    address P = LP->A[i_pl-1].First;
    CreateInfo(CURR, InfoPlaylist(P).Penyanyi, InfoPlaylist(P).Album, InfoPlaylist(P).Lagu);
    
    /*Masukin ke queue tanpa lagu pertama*/
    ClearQueue(QS);
    while (P != Nil)
    {
        enqueue(QS, InfoPlaylist(P));
        P = Next(P);
    }
    dequeue(QS, &temp);

    /*Masukin ke stack*/
    P = LP->A[i_pl-1].First->next;
    while (P != Nil)
    {
        Push(hist, InfoPlaylist(P));
        P = Next(P);
    }
}

void QUEUESONG(Set *A, Map *D, Queue *QS)
{
    Info temp;

    printf("Daftar Penyanyi :\n");
    for (int i=0; i<A->Count_Lagu; i++)
    {
        printf("    %d. ", i+1);
        PRINTWORD(A->Elements[i]);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    GetInput();
    CompressInput();
    printf("Daftar Album oleh ");
    PRINTWORD(currentWord);

    int c = 1;
    for (int i=0; i<D->Count_Album; i++)
    {
        if (WordCompare(D->Elements[i].Nama_Penyanyi, currentWord))
        {
            printf("    %d. ", c);
            PRINTWORD(D->Elements[i].Nama_Album);
            c++;
        }
    }

    printf("Masukkan Nama Album yang dipilih : ");
    GetInput();
    CompressInput();

    int i = 0;
    boolean found_album = false;
    while (i < D->Count_Album && !found_album)
    {
        if (WordCompare(D->Elements[i].Nama_Album, currentWord))
            found_album = true;
        i++;
    }
    printf("Daftar Lagu Album %s oleh %s :\n", D->Elements[i-1].Nama_Album.TabWord, D->Elements[i-1].Nama_Penyanyi.TabWord);
    for (int j=0; j<D->Elements[i-1].Info_Lagu.Count_Lagu; j++)
    {
        printf("    %d. ", j+1);
        PRINTWORD(D->Elements[i-1].Info_Lagu.Elements[j]);
    }
    /*Ambil lagu untuk dimasukin*/
    printf("Masukkan ID Lagu yang dipilih : ");
    GetInput();
    CompressInput();  
    int i_lagu = WordToInt(currentWord);

    printf("Berhasil menambahkan lagu: ");
    PRINTWORD(D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);
    printf("oleh: ");
    PRINTWORD(D->Elements[i-1].Nama_Penyanyi);

    /*Enqueue song*/
    CreateInfo(&temp, D->Elements[i-1].Nama_Penyanyi, D->Elements[i-1].Nama_Album, D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);
    enqueue(QS, temp);
}

void QUEUEPLAYLIST(Set *A, Map *D, Queue *QS, ArrayDin *LP)
{
    Info temp;

    /*Display Playlist yang dimiliki*/
    LISTPLAYLIST(*LP);
    printf("Masukkan ID Playlist: ");
    /*Ambil ID playlist*/
    GetInput();
    CompressInput();
    int i_pl = WordToInt(currentWord);

    printf("Berhasil menambahkan playlist ");
    PRINTWORD(LP->A[i_pl-1].Nama);
    printf(" ke queue.\n");

    address P = LP->A[i_pl-1].First;
    while (P != Nil)
    {
        CreateInfo(&temp, InfoPlaylist(P).Penyanyi, InfoPlaylist(P).Album, InfoPlaylist(P).Lagu);
        enqueue(QS, temp);
        P = Next(P);
    }
}

void QUEUESWAP(Queue *QS, int x, int y)
{
    printf("Lagu ");
    PRINTWORD(QS->buffer[x].Lagu);
    printf("berhasil ditukar dengan ");
    PRINTWORD(QS->buffer[y].Lagu);
    printf("\n");
    /*Swap lagu dengan swap queue*/
    SwapQueue(QS, x, y);
}

void QUEUEREMOVE(Queue *QS, int x)
{
    Info temp;

    printf("Lagu ");
    PRINTWORD(QS->buffer[x].Lagu);
    printf(" oleh ");
    PRINTWORD(QS->buffer[x].Penyanyi);
    printf("telah dihapus dari queue!\n");

    RemoveQueue(QS, &temp, x);
}

// Lagu “Kokoro wo Komete” oleh “Aoi Teshima” telah dihapus dari queue!

void HELP(boolean inSesh)
{
    printf("=====[ Menu Help WayangWave ]=====\n");
    if (!inSesh)
    {
        printf("    1. LIST -> Untuk menampilkandaftar lagu, playlist, daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
        printf("    2. PLAY -> Untuk memutar lagu atau playlist yang dipilih.\n");
        printf("    3. QUEUE -> Untuk memanipulasi queue lagu.\n");
        printf("    4. SONG -> Untuk navigasi lagu yang ada pada queue lagu saat ini.\n");
        printf("    5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.\n");
        printf("    6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
        printf("    7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
        printf("    8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave.\n");
        printf("    9. HELP -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.\n");
    }
    else
    {
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
}


boolean CHECKCOMMAND(Word W, boolean inSesh)
{
    char l[MaxEl][MaxEl] = {"START", "LOAD", "LIST DEFAULT", "LIST PLAYLIST", 
                            "PLAY SONG", "PLAY PLAYLIST", "QUEUE SONG", "QUEUE PLAYLIST",
                            "QUEUE SWAP", "QUEUE REMOVE", "QUEUE CLEAR",  "SONG NEXT",
                            "SONG PREVIOUS", "PLAYLIST CREATE", "PLAYLIST ADD SONG",
                            "PLAYLIST ADD ALBUM", "PLAYLIST SWAP", "PLAYLIST REMOVE",
                            "PLAYLIST DELETE", "STATUS", "SAVE", "QUIT", "HELP"};
    int i=0; boolean found = false;
    while (i < 23 && !found)
    {
        if (WordCompare(strToWord(l[i]), W))
            found = true;
        else 
            i++;
    }
    printf("%d\n", i);
    if (found)
    {
        /*Jika belum masuk session dan memilih command selain start & load*/
        /* ATAU Memilih start / load ketika sudah masuk session*/
        if ((!inSesh && (i>1) || (inSesh && (i<2))))
        {
            printf("Command tidak bisa dieksekusi!\n");
            return false;
        }
        else
            return true;
    }
    else
    {
        printf("Command tidak diketahui!\n");
        return false;
    }
}
