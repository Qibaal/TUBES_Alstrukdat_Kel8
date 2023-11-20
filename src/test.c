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

    // create empty untuk setiap ADT
    // CreateEmptyMap(&Data);
    // CreateEmptySet(&Penyanyi);
    CreateEmptyList(&PlayList);

    // STARTINPUT();
    // CopyWord();
    // PRINTWORD(currentWord);

    // STARTWORD(s); // mulai

    // // ambil jumlah penyanyi -- line paling atas
    // ADVNEXT(true);
    // jumlah_penyanyi = val;
    // // lanjut pembacaan
    // for (int i=0; i<jumlah_penyanyi; i++)
    // {
    //     ADVNEXT(true); // maju ke line album
    //     jumlah_album = val; // ngambil jumlah album
    //     InsertSet(&Penyanyi, currentWord); // masukin nama penyanyi
        
    //     Word artist;
    //     InsertWord(&artist, currentWord);

    //     for (int i=0; i<jumlah_album; i++) // loop nama album
    //     {
    //         // ngambil jumlah lagu yang ada di album dan print nama album
    //         ADVNEXT(true);
    //         jumlah_lagu = val;
            
    //         Word album_name;
    //         InsertWord(&album_name, currentWord);
    //         InsertAlbum(&Data, artist, album_name); // masukin nama penyanyi dan album ke ADT
    //         CreateEmptySet(&Data.Elements[Data.Count_Album].Info_Lagu);
    //         for (int i=0; i<jumlah_lagu; i++)
    //         {
    //             ADVNEXT(false);
    //             InsertSet(&Data.Elements[Data.Count_Album].Info_Lagu, currentWord);
    //         }
    //         Data.Count_Album++;
    //     }
    // }
    // test start
    STARTCONSOLE(&Data, &Penyanyi, s);
    // PRINTWORD(Data.Elements[4].Nama_Penyanyi);
    // PRINTWORD(Data.Elements[4].Nama_Album);
    // PrintSet(Data.Elements[4].Info_Lagu);

    //test load
    LOAD(&PLAYLISTS, &CURRSONG, &HISTORY, &SONGQUEUE);
    // printf("lagu yg sedang dimainkan: \n");
    // DisplayInfo(CURRSONG);
    // printf("-------------------------\n");
    // printf("lagu-lagu yg telah dimainkan - paling atas lagu terakhir: \n");
    // DisplayStack(HISTORY);
    // printf("-------------------------\n");
    // printf("lagu-lagu dalam queue: \n");
    // displayQueue(SONGQUEUE);
    // printf("-------------------------\n");
    // printf("playlist yang dimiliki: \n");
    // DisplayAD(PLAYLISTS);


    // LOAD lagu yg sedang dimainin
    // ParsePlaylist(&p, &a, &l);
    // PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);

    // //LOAD ke queue
    // ADVNEXT(true);
    // int jumlah_queue = val;
    // printf("-----------Queue----------\n");
    // printf("%d\n", jumlah_queue);
    // for (int i=0; i<jumlah_queue; i++)
    // {
    //     ParsePlaylist(&p, &a, &l);
    //     PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);
    // }

    // // LOAD ke history (stack)
    // ADVNEXT(true);
    // int jumlah_stack = val;
    // printf("%d\n", jumlah_stack);
    // printf("-----------Stack----------\n");
    // for (int i=0; i<jumlah_stack; i++)
    // {
    //     ParsePlaylist(&p, &a, &l);
    //     PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);
    // }

    // // LOAD KE PLAYLIST
    // ADVNEXT(true);
    // int jumlah_playlist = val;
    // for (int i=0; i<jumlah_playlist; i++)
    // {
    //     ADVNEXT(true);
    //     jumlah_lagu = val;
    //     InsertWord(&PlayList.Nama, currentWord);
    //     PRINTWORD(currentWord);
    //     for (int j=0; j<jumlah_lagu; j++)
    //     {
    //         ParsePlaylist(&p, &a, &l);
    //         CreateInfo(&temp, p, a, l);
    //         InsVLast(&PlayList, temp);
    //     }
    //     DisplayPlaylist(PlayList);
    // }

    // test list default
    // LISTDEFAULT(Data, Penyanyi);

    // test listplaylist
    LISTPLAYLIST(PLAYLISTS);

    return 0;
}
