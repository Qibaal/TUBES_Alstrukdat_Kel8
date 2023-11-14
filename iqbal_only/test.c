#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "..\src\ADT\Set\set.h"

int main() {
    Set Penyanyi, Album, Lagu;
    CreateEmptySet(&Penyanyi); CreateEmptySet(&Album); CreateEmptySet(&Lagu);
    // mulai
    STARTWORD();
    // ambil jumlah penyanyi -- line paling atas
    ADVNEXT(true);
    int jumlah_penyanyi = val;
    printf("jumlah penyanyi: %d\n", jumlah_penyanyi);
    // lanjut pembacaan
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        // maju ke line album
        ADVNEXT(true);
        // ngambil jumlah album dan print nama penyanyi
        int jumlah_album = val;
        printf("jumlah album: %d\n", jumlah_album);
        // masukin nama penyanyi
        InsertSet(&Penyanyi, currentWord.TabWord);
        // PRINTWORD();
        // loop nama album
        for (int i=0; i<jumlah_album; i++)
        {
            // ngambil jumlah lagu yang ada di album dan print nama album
            ADVNEXT(true);
            int jumlah_lagu = val;
            printf("jumlah lagu: %d\n", jumlah_lagu);
            // masukin nama album
            InsertSet(&Album, currentWord.TabWord);
            // PRINTWORD();
            for (int i=0; i<jumlah_lagu; i++)
            {
                ADVNEXT(false);
                // masukin nama lagu
                InsertSet(&Lagu, currentWord.TabWord);
                // PRINTWORD();
            }
        }
    }
    PrintSet(Penyanyi);
    printf("-----\n");
    PrintSet(Album);
    printf("-----\n");
    PrintSet(Lagu);
    printf("-----\n");
    printf("kelar");
    return 0;
}