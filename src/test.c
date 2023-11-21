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
    printf("----------------\n");

    // test listplaylist
    // LISTPLAYLIST(PLAYLISTS);
    // printf("----------------\n");

    //test playsong
    PLAYSONG(&CURRSONG, &Penyanyi, &Data, &SONGQUEUE, &HISTORY);
    printf("----------------\n");
    DisplayInfo(CURRSONG);
    printf("----------------\n");

    // test play playlist
    PLAYPLAYLIST(&CURRSONG, &Penyanyi, &Data, &SONGQUEUE, &HISTORY, &PLAYLISTS);
    DisplayInfo(CURRSONG);
    printf("----------------\n");
    
    DisplayStack(HISTORY);
    printf("-------- History --------\n");

    displayQueue(SONGQUEUE);
    printf("-------- Queue --------\n");

    // for (int i=0; i<Data.Count_Album; i++)
    // {
    //     printf("%d\n", Data.Elements[i].Nama_Album.Length);
    //     for (int j=0; j<Data.Elements[i].Nama_Album.Length; j++)
    //     {
    //         printf("%c-", Data.Elements[i].Nama_Album.TabWord[j]);
    //     }
    //     printf("\n");
    // }
    // GetInput();
    // if (WordCompare(Data.Elements[0].Nama_Album, currentWord))
    //     printf("sama blok;");
    // else 
    //     printf("beda");
    // printf("%d\n", currentWord.Length);

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
