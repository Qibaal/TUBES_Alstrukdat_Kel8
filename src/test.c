#include <stdio.h>
#include "console.h"

// char s[] = "ADT/MesinKarakter/dummy.txt";
char s[] = "dummy.txt";

int main() {
    // Kamus Lokal
    Map Data;
    Set Penyanyi;
    ArrayDin PLAYLISTS = MakeAD();
    Stack HISTORY;
    Queue SONGQUEUE;
    int jumlah_penyanyi, jumlah_album, jumlah_lagu;
    Word p, a, l;
    Info CURRSONG;
    Word CURRPLAYLIST; CURRPLAYLIST.Length = 0;

    Info temp;

    // test start
    STARTCONSOLE(&Data, &Penyanyi, s);
    // PRINTWORD(Data.Elements[4].Nama_Penyanyi);
    // PRINTWORD(Data.Elements[4].Nama_Album);
    // PrintSet(Data.Elements[4].Info_Lagu);

    //test load
    LOAD(&PLAYLISTS, &CURRSONG, &HISTORY, &SONGQUEUE);

    // test list default
    LISTDEFAULT(&Data, &Penyanyi);
    printf("----------------\n");

    // test listplaylist
    LISTPLAYLIST(PLAYLISTS);
    // printf("----------------\n");

    // test playsong
    PLAYSONG(&CURRSONG, &Penyanyi, &Data, &SONGQUEUE, &HISTORY);
    printf("----------------\n");
    DisplayInfo(CURRSONG);
    printf("----------------\n");

    // test play playlist
    PLAYPLAYLIST(&CURRSONG, &CURRPLAYLIST, &Penyanyi, &Data, &SONGQUEUE, &HISTORY, &PLAYLISTS);
    // DisplayInfo(CURRSONG);
    // printf("----------------\n");

    // DisplayStack(HISTORY);
    // printf("-------- History --------\n");

    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // // test Queue song
    QUEUESONG(&Penyanyi, &Data, &SONGQUEUE);

    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // // test queue playlist
    QUEUEPLAYLIST(&Penyanyi, &Data, &SONGQUEUE, &PLAYLISTS);

    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // test queue swap
    QUEUESWAP(&SONGQUEUE);

    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // test queue remove
    QUEUEREMOVE(&SONGQUEUE);

    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // test queue clear
    QUEUECLEAR(&SONGQUEUE);
    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // test song next
    SONGNEXT(&CURRSONG, &SONGQUEUE, &HISTORY);
    // displayQueue(SONGQUEUE);
    // printf("-------- Queue --------\n");

    // test song previous
    // DisplayStack(HISTORY);
    // printf("-------- history --------\n");
    SONGPREVIOUS(&CURRSONG, &SONGQUEUE, &HISTORY);
    // DisplayStack(HISTORY);
    // printf("-------- history --------\n");

    // test create playlist
    CREATEPLAYLIST(&PLAYLISTS);

    // test add song playlist
    ADDSONGPLAYLIST(&PLAYLISTS, &Penyanyi, &Data);

    // test add album playlist
    ADDALBUMPLAYLIST(&PLAYLISTS, &Penyanyi, &Data);

    // test playlist swap
    PLAYLISTSWAP(&PLAYLISTS);

    // test playlist remove
    PLAYLISTREMOVE(&PLAYLISTS);

    // test playlist delete
    PLAYLISTDELETE(&PLAYLISTS);

    // test status
    STATUS(&CURRSONG, SONGQUEUE, &CURRPLAYLIST);



    return 0;
}
