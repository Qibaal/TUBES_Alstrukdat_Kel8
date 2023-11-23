#include "console.h"

char s[] = "dummy.txt";

int main()
{
    Map Data;
    Set Penyanyi;
    ArrayDin PLAYLISTS = MakeAD();
    Stack HISTORY;
    Queue SONGQUEUE;
    int jumlah_penyanyi, jumlah_album, jumlah_lagu;
    Info CURRSONG;
    Word CURRPLAYLIST; CURRPLAYLIST.Length = 0;
    Info temp;
    boolean Session = false;
    char file[NMax];
    
    /*Inisiasi Program*/
    DISPLAYBANNER();
    while (true)
    {
        printf("\n>> "); GetInput(); CompressInput();
        /* Setiap memasukan input (every loop di check validitas) */
        if (CHECKCOMMAND(currentWord, Session))
        {
            /*Matching dengan command yang ada*/
            if (WordCompare(strToWord("START"), currentWord))
            {
                STARTCONSOLE(&Data, &Penyanyi, &SONGQUEUE, "konfigurasi.txt");
                printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
                Session = true;
            }
            else if (WordCompare(strToWord("LOAD"), currentWord))
            {
                printf("Masukkan nama file untuk di Load: ");
                GetInput(); CompressInput();
                WordToStr(currentWord, file);
                STARTCONSOLE(&Data, &Penyanyi, &SONGQUEUE, file);
                LOAD(&PLAYLISTS, &CURRSONG, &HISTORY, &SONGQUEUE);
                printf("Load Berhasil!\n");
                Session = true;
            }
            else if (WordCompare(strToWord("LIST DEFAULT"), currentWord))
            {
                LISTDEFAULT(&Data, &Penyanyi);
            }
            else if (WordCompare(strToWord("LIST PLAYLIST"), currentWord))
            {
                LISTPLAYLIST(PLAYLISTS);
            }
            else if (WordCompare(strToWord("PLAY SONG"), currentWord))
            {
                PLAYSONG(&CURRSONG, &CURRPLAYLIST, &Penyanyi, &Data, &SONGQUEUE, &HISTORY);
            }
            else if (WordCompare(strToWord("PLAY PLAYLIST"), currentWord))
            {
                PLAYPLAYLIST(&CURRSONG, &CURRPLAYLIST, &Penyanyi, &Data, &SONGQUEUE, &HISTORY, &PLAYLISTS);
            }
            else if (WordCompare(strToWord("QUEUE SONG"), currentWord))
            {
                QUEUESONG(&Penyanyi, &Data, &SONGQUEUE);
            }
            else if (WordCompare(strToWord("QUEUE PLAYLIST"), currentWord))
            {
                QUEUEPLAYLIST(&Penyanyi, &Data, &SONGQUEUE, &PLAYLISTS);
            }
            else if (WordCompare(strToWord("QUEUE SWAP"), currentWord))
            {
                QUEUESWAP(&SONGQUEUE);
            }   
            else if (WordCompare(strToWord("QUEUE REMOVE"), currentWord))
            {
                QUEUEREMOVE(&SONGQUEUE);
            }
            else if (WordCompare(strToWord("QUEUE CLEAR"), currentWord))
            {
                QUEUECLEAR(&SONGQUEUE);
            }
            else if (WordCompare(strToWord("SONG NEXT"), currentWord))
            {
                SONGNEXT(&CURRSONG, &SONGQUEUE, &HISTORY);
            }
            else if (WordCompare(strToWord("SONG PREVIOUS"), currentWord))
            {
                /*Re-Check pre submission*/
                SONGPREVIOUS(&CURRSONG, &SONGQUEUE, &HISTORY);
            }
            else if (WordCompare(strToWord("PLAYLIST CREATE"), currentWord))
            {   
                CREATEPLAYLIST(&PLAYLISTS);
            }
            else if (WordCompare(strToWord("PLAYLIST ADD SONG"), currentWord))
            {
                ADDSONGPLAYLIST(&PLAYLISTS, &Penyanyi, &Data);
            }
            else if (WordCompare(strToWord("PLAYLIST ADD ALBUM"), currentWord))
            {
                ADDALBUMPLAYLIST(&PLAYLISTS, &Penyanyi, &Data);
            }
            else if (WordCompare(strToWord("PLAYLIST SWAP"), currentWord))
            {
                /*Get ID, X, Y sudah ada di procedure*/
                PLAYLISTSWAP(&PLAYLISTS);
            }
            else if (WordCompare(strToWord("PLAYLIST REMOVE"), currentWord))
            {
                PLAYLISTREMOVE(&PLAYLISTS);
            }
            else if (WordCompare(strToWord("PLAYLIST DELETE"), currentWord))
            {
                PLAYLISTDELETE(&PLAYLISTS);
            }
            else if (WordCompare(strToWord("STATUS"), currentWord))
            {
                STATUS(&CURRSONG, SONGQUEUE, &CURRPLAYLIST);
            }
            else if (WordCompare(strToWord("HELP"), currentWord))
            {
                HELP(Session);
            }
            else if(WordCompare(strToWord("QUIT"), currentWord))
            {
                printf("Selamat tinggal");
                Session = false;
                exit(0);
            }
            else
            {
                printf("Input Tidak Valid! Silahkan masukkan command lagi: \n");
                // printf(">> "); GetInput(); CompressInput();
                // while (!CHECKCOMMAND(currentWord, Session))
                // {

                // }
            }
        }
    }
}