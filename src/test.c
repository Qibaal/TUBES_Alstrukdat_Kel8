#include <stdio.h>
#include "boolean.h"
#include "ADT\header\mesinkar.h"
#include "ADT\header\mesinkata.h"
#include "ADT\header\map.h"
#include "ADT\header\listsirkuler.h"

int main() {
    // LOAD ke ADT
    Map Data;
    Set Penyanyi;
    int jumlah_penyanyi, jumlah_album, jumlah_lagu;
    List PlayList;
    Word p, a, l;
    Info temp;

    // create empty untuk setiap ADT
    CreateEmptyMap(&Data);
    CreateEmptySet(&Penyanyi);
    CreateEmptyList(&PlayList);

    STARTWORD(); // mulai

    // ambil jumlah penyanyi -- line paling atas
    ADVNEXT(true);
    jumlah_penyanyi = val;
    // lanjut pembacaan
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        ADVNEXT(true); // maju ke line album
        jumlah_album = val; // ngambil jumlah album
        InsertSet(&Penyanyi, currentWord); // masukin nama penyanyi
        
        Word artist;
        InsertWord(&artist, currentWord);

        for (int i=0; i<jumlah_album; i++) // loop nama album
        {
            // ngambil jumlah lagu yang ada di album dan print nama album
            ADVNEXT(true);
            jumlah_lagu = val;
            
            Word album_name;
            InsertWord(&album_name, currentWord);
            InsertAlbum(&Data, artist, album_name); // masukin nama penyanyi dan album ke ADT
            CreateEmptySet(&Data.Elements[Data.Count_Album].Info_Lagu);
            for (int i=0; i<jumlah_lagu; i++)
            {
                ADVNEXT(false);
                InsertSet(&Data.Elements[Data.Count_Album].Info_Lagu, currentWord);
            }
            Data.Count_Album++;
        }
    }
    // PrintMap(Data);
    // PRINTWORD(Data.Elements[6].Nama_Penyanyi);
    // PRINTWORD(Data.Elements[5].Nama_Album);
    // PrintSet(Data.Elements[5].Info_Lagu);

    // LOAD lagu yg sedang dimainin
    ParsePlaylist(&p, &a, &l);
    PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);

    //LOAD ke queue
    ADVNEXT(true);
    int jumlah_queue = val;
    printf("-----------Queue----------\n");
    printf("%d\n", jumlah_queue);
    for (int i=0; i<jumlah_queue; i++)
    {
        ParsePlaylist(&p, &a, &l);
        PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);
    }

    // LOAD ke history (stack)
    ADVNEXT(true);
    int jumlah_stack = val;
    printf("%d\n", jumlah_stack);
    printf("-----------Stack----------\n");
    for (int i=0; i<jumlah_stack; i++)
    {
        ParsePlaylist(&p, &a, &l);
        PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);
    }

    // LOAD KE PLAYLIST
    ADVNEXT(true);
    int jumlah_playlist = val;
    for (int i=0; i<jumlah_playlist; i++)
    {
        ADVNEXT(true);
        jumlah_lagu = val;
        InsertWord(&PlayList.Nama, currentWord);
        PRINTWORD(currentWord);
        for (int j=0; j<jumlah_lagu; j++)
        {
            ParsePlaylist(&p, &a, &l);
            CreateInfo(&temp, p, a, l);
            InsVLast(&PlayList, temp);
        }
        DisplayPlaylist(PlayList);
    }
    return 0;
}
