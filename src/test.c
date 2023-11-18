#include <stdio.h>
#include "boolean.h"
#include "ADT\header\mesinkar.h"
#include "ADT\header\mesinkata.h"
#include "ADT\header\map.h"

void InsertWord(Word *t, Word w)
{
    t->Length = w.Length;
    for (int i=0; i<w.Length; i++)
    {
        t->TabWord[i] = w.TabWord[i];
    }
}

int main() {
    // LOAD ke ADT
    Map Data;
    Set Penyanyi;
    int jumlah_penyanyi, jumlah_album, jumlah_lagu;
    Word p, a, l;

    // create empty untuk setiap ADT
    CreateEmptyMap(&Data);
    CreateEmptySet(&Penyanyi);

    STARTWORD(); // mulai

    // ambil jumlah penyanyi -- line paling atas
    ADVNEXT(true);
    jumlah_penyanyi = val;
    // lanjut pembacaan
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        ADVNEXT(true); // maju ke line album
        jumlah_album = val; // ngambil jumlah album
        InsertSet(&Penyanyi, currentWord.TabWord); // masukin nama penyanyi
        
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
                InsertSet(&Data.Elements[Data.Count_Album].Info_Lagu, currentWord.TabWord);
            }
            Data.Count_Album++;
        }
    }
    // PrintMap(Data);

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
    printf("%d\n", jumlah_playlist);
    printf("-----------Playlist----------\n");
    for (int i=0; i<jumlah_playlist; i++)
    {
        ADVNEXT(true);
        jumlah_lagu = val;
        printf("%d\n", jumlah_lagu);
        printf("nama album: ");
        PRINTWORD(currentWord);
        for (int j=0; j<jumlah_lagu; j++)
        {
            ParsePlaylist(&p, &a, &l);
            PRINTWORD(p); PRINTWORD(a); PRINTWORD(l);
        }
        printf("-----------\n");
    }
    return 0;
}
