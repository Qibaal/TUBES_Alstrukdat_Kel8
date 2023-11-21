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
    List PlayList;
    Word p, a, l;
    Info CURRSONG;

    Info temp;

    CreateEmptyList(&PlayList);

    // test start
    STARTCONSOLE(&Data, &Penyanyi, s);
    // PRINTWORD(Data.Elements[4].Nama_Penyanyi);
    // PRINTWORD(Data.Elements[4].Nama_Album);
    // PrintSet(Data.Elements[4].Info_Lagu);

    //test load
    LOAD(&PLAYLISTS, &CURRSONG, &HISTORY, &SONGQUEUE);

    // test list default
    LISTDEFAULT(&Data, &Penyanyi);

    // test listplaylist
    // LISTPLAYLIST(PLAYLISTS);
    // PLAYSONG(&CURRSONG, Penyanyi, Data, &SONGQUEUE, &HISTORY);

    // test help
    // Word h; h.Length = 4;
    // h.TabWord[0] = 'H'; h.TabWord[1] = 'E'; h.TabWord[2] = 'L'; h.TabWord[3] = 'P';
    // printf(">> ");
    // GetInput();
    // if (WordCompare(h,currentWord))
    //     HELP(false);

    // test check command
    // GetInput();
    // if (CHECKCOMMAND(currentWord, true)) printf("sesuai\n");
    // else printf("ga sesuai\n");
    // int id  = currentWord.TabWord[currentWord.Length-1] - '0';
    // printf("%d\n", id);

    return 0;
}
