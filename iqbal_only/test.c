#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
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
        printf("---------------------\n");
        printf("jumlah album: %d\n", jumlah_album);
        PRINTWORD();
        // loop nama album
        for (int i=0; i<jumlah_album; i++)
        {
            // ngambil jumlah lagu yang ada di album dan print nama album
            ADVNEXT(true);
            int jumlah_lagu = val;
             printf("---------------------\n");
            printf("jumlah lagu: %d\n", jumlah_lagu);
            PRINTWORD();
            for (int i=0; i<jumlah_lagu; i++)
            {
                ADVNEXT(false);
                PRINTWORD();
            }
        }
    }
    printf("kelar");
    return 0;
}