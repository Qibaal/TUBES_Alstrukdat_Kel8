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
        printf("    %d. ", i+1);
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

void PLAYSONG(Info *CURR, Set A, Map D, Queue *QS, Stack *hist)
{
    // masukin currentsong ke dalam history
    Push(hist, *CURR);
    /*pemilihan Lagu*/
    printf("Daftar Penyanyi :\n");
    for (int i=0; i<A.Count_Lagu; i++)
    {
        printf("    %d. ", i+1);
        PRINTWORD(A.Elements[i]);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    GetInput();
    printf("Daftar Album oleh %s:\n", currentWord.TabWord);
    for (int i=0; i<D.Count_Album; i++)
    {
        if (WordCompare(D.Elements[i].Nama_Penyanyi, currentWord))
        {
            printf("    %d. ", i+1);
            PRINTWORD(D.Elements[i].Nama_Album);
        }
    }
    /*Ambil nama album*/
    printf("Masukkan Nama Album yang dipilih : ");
    GetInput();
    int i = 0;
    for (i=0; i<D.Count_Album; i++)
    {
        if (WordCompare(D.Elements[i].Nama_Album, currentWord))
            break;
    }
    printf("Daftar Lagu Album %s oleh %s :\n", D.Elements[i].Nama_Album, D.Elements[i].Nama_Penyanyi);
    for (int j=0; j<D.Elements[i].Info_Lagu.Count_Lagu; j++)
    {
        printf("    %d. ", j+1);
        PRINTWORD(D.Elements[i].Info_Lagu.Elements[j]);
    }
    /*Ambil lagu untuk dimasukin*/
    printf("Masukkan ID Lagu yang dipilih :\n");
    GetInput();
    printf("Memutar lagu “%s” oleh “%s”.", D.Elements[i].Info_Lagu.Elements[stringToInt(currentWord.TabWord)-1],
            D.Elements[i].Nama_Penyanyi);
    
    /*Update ke currentsong*/
    CreateInfo(CURR,  D.Elements[i].Nama_Penyanyi,  D.Elements[i].Nama_Album, D.Elements[i].Info_Lagu.Elements[stringToInt(currentWord.TabWord)-1]);

    /*pengosongan queue dan stack riwayat lagu*/
    ClearQueue(QS); 
    while (!IsEmptyStack(*hist))
    {
        Info temp;
        Pop(hist, &temp);
    }
}

void HELP(boolean inSesh)
{
    printf("=====[ Menu Help WayangWave ]=====\n");
    if (!inSesh)
    {
        printf("1. LIST -> Untuk menampilkandaftar lagu, playlist, daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
        printf("2. PLAY -> Untuk memutar lagu atau playlist yang dipilih.\n");
        printf("3. QUEUE -> Untuk memanipulasi queue lagu.\n");
        printf("4. SONG -> Untuk navigasi lagu yang ada pada queue lagu saat ini.\n");
        printf("5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.\n");
        printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
        printf("7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
        printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave.\n");
        printf("9. HELP -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.\n");
    }
    else
    {
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
}
