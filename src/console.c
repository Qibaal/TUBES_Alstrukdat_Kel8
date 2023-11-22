#include "console.h"

int jumlah_penyanyi, jumlah_album, jumlah_lagu;   

void STARTCONSOLE(Map* D, Set* A, Queue *QS, char* file)
{
    CreateEmptyMap(D);
    CreateEmptySet(A);
    CreateQueue(QS);
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
    CompressInput();

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

void PLAYSONG(Info *CURR, Word *CURRPL, Set *A, Map *D, Queue *QS, Stack *hist)
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

    if (i_lagu <= 0 || i_lagu > D->Elements[i].Info_Lagu.Count_Lagu)
    {
        printf("tidak ada lagu dengan id %d!\n", i_lagu);
        return;
    }

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
    
    /*Set Current playlist jadi kosong*/
    CURRPL->Length = 0;
}

void PLAYPLAYLIST(Info *CURR, Word *CURRPL, Set *A, Map *D, Queue *QS, Stack *hist, ArrayDin *LP)
{
    Info temp;

    /*Display Playlist yang dimiliki*/
    LISTPLAYLIST(*LP);
    printf("Masukkan ID Playlist: ");
    /*Ambil ID playlist*/
    GetInput();
    CompressInput();
    int i_pl = WordToInt(currentWord);

    /* out of range handling */
    if (i_pl <= 0 || i_pl > LP->Neff)
    {
        printf("tidak ada playlist dengan id %d!\n", i_pl);
        return;
    }

    printf("memainkan playlist: ");
    PRINTWORD(LP->A[i_pl-1].Nama);
    InsertWord(CURRPL, LP->A[i_pl-1].Nama);

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

    if (i_lagu <= 0 || i_lagu > D->Elements[i].Info_Lagu.Count_Lagu)
    {
        printf("tidak ada lagu dengan id %d!\n", i_lagu);
        return;
    }

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

    if (i_pl <= 0 || i_pl > LP->Neff)
    {
        printf("tidak ada playlist dengan id %d!\n", i_pl);
        return;
    }

    printf("Berhasil menambahkan playlist ");
    PRINTWORD2(LP->A[i_pl-1].Nama);
    printf(" ke queue.\n");

    address P = LP->A[i_pl-1].First;
    while (P != Nil)
    {
        CreateInfo(&temp, InfoPlaylist(P).Penyanyi, InfoPlaylist(P).Album, InfoPlaylist(P).Lagu);
        enqueue(QS, temp);
        P = Next(P);
    }
}

void QUEUESWAP(Queue *QS)
{
    printf("Masukkan x: ");
    GetInput(); CompressInput();
    int X = WordToInt(currentWord);
    printf("%d\n", X);

    if (X <= 0 || X > length(*QS))
    {
        printf("Tidak ada queue dengan ID %d!\n", X);
        return;
    }

    printf("Masukkan y: ");
    GetInput(); CompressInput();
    int Y = WordToInt(currentWord);
    printf("%d\n", Y);

    if (Y <= 0 || Y > length(*QS))
    {
        printf("Tidak ada queue dengan ID %d!\n", Y);
        return;
    }

    printf("Lagu ");
    PRINTWORD2(QS->buffer[X-1].Lagu);
    printf("berhasil ditukar dengan ");
    PRINTWORD(QS->buffer[Y-1].Lagu);
    printf("\n");
    /*Swap lagu dengan swap queue*/
    SwapQueue(QS, X, Y);
}

void QUEUEREMOVE(Queue *QS)
{
    Info temp;

    printf("Masukkan x: ");
    GetInput(); CompressInput();
    int X = WordToInt(currentWord);

    if (X > length(*QS))
    {
        /*Bakal throw error*/
        printf("Lagu dengan ID %d Tidak ada!\n", X);
    }
    else
    {
        printf("Lagu ");
        PRINTWORD2(QS->buffer[X-1].Lagu);
        printf("oleh ");
        PRINTWORD2(QS->buffer[X-1].Penyanyi);
        printf("telah dihapus dari queue!\n");

        RemoveQueue(QS, &temp, X);
    }
}

void QUEUECLEAR(Queue *QS)
{
    ClearQueue(QS);
    if (isEmptyQ(*QS))
        printf("Queue berhasil dikosongkan.\n");
    else
        printf("Queue TIDAK berhasil dikosongkan.\n");
}

void SONGNEXT(Info *CURR, Queue *QS, Stack *hist)
{
    if (isEmptyQ(*QS))
    {
        printf("Queue kosong, memutar kembali lagu\n");
    }
    else
    {
        printf("Memutar lagu selanjutnya\n");
        Push(hist, *CURR);
        dequeue(QS, CURR);
    }
    PRINTWORD2(CURR->Lagu);
    printf("oleh ");
    PRINTWORD2(CURR->Penyanyi);
}

void SONGPREVIOUS(Info *CURR, Queue *QS, Stack *hist)
{
    Queue temp; CreateQueue(&temp);
    Info iTemp;
    if (IsEmptyStack(*hist))
    {
        printf("Riwayat lagu kosong, memutar kembali lagu\n");
    }
    else
    {
        /*Masukin sementara ke dalam temp*/
        while (!isEmptyQ(*QS))
        {
            dequeue(QS, &iTemp);
            enqueue(&temp, iTemp);
        }

        /*Masukin lagi ke queue main dengan first el adalah curr song terakhir*/
        enqueue(QS, *CURR);
        while (!isEmptyQ(temp))
        {
            dequeue(&temp, &iTemp);
            enqueue(QS, iTemp);
        }

        /*Ngambil lagu terakhir dari stack*/
        Pop(hist, &iTemp);


        /*Curr song adalah lagu terakhir dari stack*/
        CreateInfo(CURR, iTemp.Penyanyi, iTemp.Album, iTemp.Lagu);
        printf("Memutar lagu sebelumnya: ");
    }
    PRINTWORD(CURR->Lagu);
    printf("oleh ");
    PRINTWORD(CURR->Penyanyi);
}

void CREATEPLAYLIST(ArrayDin *LP)
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    GetInput();
    CompressInput();
    
    InsertWord(&(*LP).A[LP->Neff].Nama, currentWord);
    CreateEmptyList(&(*LP).A[LP->Neff]);
    LP->Neff++;

    printf("Playlist ");
    PRINTWORD(currentWord);
    printf("berhasil dibuat!\n");
    printf("Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    printf("\n");
    LISTPLAYLIST(*LP);
}

void ADDSONGPLAYLIST(ArrayDin *LP, Set *A, Map *D)
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

    printf("Masukkan ID Lagu yang dipilih : ");
    GetInput();
    CompressInput();  
    int i_lagu = WordToInt(currentWord);

    LISTPLAYLIST(*LP);
    printf("Masukkan ID Playlist yang dipilih :");
    GetInput();
    CompressInput();  
    int i_pl = WordToInt(currentWord);

    CreateInfo(&temp, D->Elements[i-1].Nama_Penyanyi, D->Elements[i-1].Nama_Album, D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);
    InsVLast(&(*LP).A[i_pl-1], temp);
    
    /*Print info penambahan pada playlist*/
    printf("Lagu dengan judul ");
    PRINTWORD2(D->Elements[i-1].Info_Lagu.Elements[i_lagu-1]);
    printf("pada album ");
    PRINTWORD2(D->Elements[i-1].Nama_Album);
    printf("oleh penyanyi ");
    PRINTWORD2(D->Elements[i-1].Nama_Penyanyi);
    printf("berhasil ditambahkan ke dalam playlist ");
    PRINTWORD(LP->A[i_pl-1].Nama);
}

void ADDALBUMPLAYLIST(ArrayDin *LP, Set *A, Map *D)
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
    printf("Daftar Playlist Pengguna : \n");
    
    LISTPLAYLIST(*LP);
    printf("Masukkan ID Playlist yang dipilih :");
    GetInput();
    CompressInput();  
    int i_pl = WordToInt(currentWord);

    for (int k=0; k<D->Elements[i-1].Info_Lagu.Count_Lagu; k++)
    {
        CreateInfo(&temp, D->Elements[i-1].Nama_Penyanyi, D->Elements[i-1].Nama_Album, D->Elements[i-1].Info_Lagu.Elements[k]);
        InsVLast(&(*LP).A[i_pl-1], temp);
    }
    DisplayPlaylist(LP->A[i_pl-1]);
}

void PLAYLISTSWAP(ArrayDin *LP)
{
    printf("Daftar Playlist Pengguna : \n");
    LISTPLAYLIST(*LP);

    printf("Masukkan ID Playlist: ");
    GetInput();
    CompressInput();
    int id = WordToInt(currentWord);
    printf("%d\n", id);

    if (id <= 0 || id > LP->Neff)
    {
        printf("Tidak ada playlist dengan id %d!\n", id);
        return;
    }

    printf("Masukkan ID lagu pertama: ");
    GetInput();
    CompressInput();
    int X = WordToInt(currentWord);
    printf("%d\n", X);

    if (X <= 0 || X > NbElmt(LP->A[id-1]))
    {
        printf("Tidak ada lagu dengan Id %d!\n", X);
        return;
    }

    printf("Masukkan ID lagu kedua: ");
    GetInput();
    CompressInput();
    int Y = WordToInt(currentWord);
    printf("%d\n", Y);

    if (Y <= 0 || Y > NbElmt(LP->A[id-1]))
    {
        printf("Tidak ada lagu dengan Id %d!\n", Y);
        return;
    }
}

void PLAYLISTREMOVE(ArrayDin *LP)
{
    LISTPLAYLIST(*LP);

    printf("Masukkan ID Playlist: ");
    GetInput();
    CompressInput();
    int id = WordToInt(currentWord);

    if (id <= 0 || id > LP->Neff)
    {
        printf("Tidak ada playlist dengan id %d!\n", id);
        return;
    }

    printf("Masukkan ID lagu pertama: ");
    GetInput();
    CompressInput();
    int X = WordToInt(currentWord);

    if (X <= 0 || X > NbElmt(LP->A[id-1]))
    {
        printf("Tidak ada lagu dengan Id %d!\n", X);
        return;
    }

    int i = 1;
    address Prev = Nil;
    address P = LP->A[id-1].First;
    if (X == 1)
    {
        printf("Lagu ");
        PRINTWORD(InfoPlaylist(P).Lagu);
        printf("oleh ");
        PRINTWORD(InfoPlaylist(P).Penyanyi);
        printf("telah dihapus dari playlist ");
        PRINTWORD(LP->A[id-1].Nama);
        DelFirst(&(*LP).A[id-1], &P);
    }
    else
    {
        while (P != Nil)
        {
            if (i == X - 1)
            {
                printf("Lagu ");
                PRINTWORD2(InfoPlaylist(Next(P)).Lagu);
                printf("oleh ");
                PRINTWORD2(InfoPlaylist(Next(P)).Penyanyi);
                printf("telah dihapus dari playlist ");
                PRINTWORD(LP->A[id-1].Nama);
                break;
            }
            else
            {
                Prev = P;
                P = Next(P);
                i++;
            }
        }
        DelAfter(&(*LP).A[id-1], &Prev, P);
    }
}

void PLAYLISTDELETE(ArrayDin *LP)
{
    LISTPLAYLIST(*LP);

    printf("Masukkan ID Playlist yang ingin dihapus: ");
    GetInput();
    CompressInput();
    int id = WordToInt(currentWord);

    if (id <= 0 || id > LP->Neff)
    {
        printf("Tidak ada playlist dengan id %d!\n", id);
        return;
    }

    if (id < LP->Neff)
    {
        DeleteAt(LP, id-1);
    }
    else
    {
        CreateEmptyList(&(*LP).A[id-1]);
        LP->Neff--;
    }
    LISTPLAYLIST(*LP);
}

void STATUS(Info *CURR, Queue QS, Word *CURRPL)
{
    Info temp;

    if (CURRPL->Length != 0)
    {
        printf("\nCurrent Playlist: ");
        PRINTWORD(*CURRPL);
    }
    printf("\n");
    printf("Now Playing:\n");
    if (!IsEmptyD(*CURR))
    {
        PRINTWORD2(CURR->Penyanyi);
        printf("- ");
        PRINTWORD2(CURR->Lagu);
        printf("- ");
        PRINTWORD2(CURR->Album);
    }
    else
    {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    printf("\n\n");
    printf("Queue:\n");
    if (!isEmptyQ(QS))
    {
        int i = 1;
        while (!isEmptyQ(QS))
        {
            dequeue(&QS, &temp);
            printf("%d. ", i);
            PRINTWORD2(temp.Penyanyi);
            printf("- ");
            PRINTWORD2(temp.Lagu);
            printf("- ");
            PRINTWORD2(temp.Album);
            printf("\n");
            i++;
        }
    }
    else
    {
        printf("Your queue is empty.\n");
    }
}

void HELP(boolean inSesh)
{
    printf("=====[ Menu Help WayangWave ]=====\n");
    if (inSesh)
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
    if (found)
    {
        /*Jika belum masuk session dan memilih command selain start & load*/
        /* ATAU Memilih start / load ketika sudah masuk session*/
        /* untuk help */
        if (i == 22) return true;
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
