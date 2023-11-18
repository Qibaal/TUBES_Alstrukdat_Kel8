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
    // inisialisasi ADT
    Map Data;
    Set Penyanyi;
    int jumlah_penyanyi, jumlah_album, jumlah_lagu;

    // create empty untuk setiap ADT
    CreateEmptyMap(&Data);
    CreateEmptySet(&Penyanyi);

    STARTWORD(); // mulai

    // ambil jumlah penyanyi -- line paling atas
    ADVNEXT(true);
    jumlah_penyanyi = val;
    // printf("jumlah penyanyi: %d\n", jumlah_penyanyi);
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
    PrintMap(Data);




    // char penyanyi[MaxEl];
    // char album[MaxEl];
    // char lagu[MaxEl];
    // while (!IsEOF())
    // {
    //     ParsePlaylist(penyanyi, album, lagu);
    // }
    // printf("%s\n", penyanyi);
    // printf("%s\n", album);
    // printf("%s\n", lagu);
    return 0;
}
