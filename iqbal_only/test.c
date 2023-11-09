#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
    // mulai
    STARTWORD();
    // ambil jumlah penyanyi -- line paling atas
    int jumlah_penyanyi = GetVal(currentWord.TabWord);
    printf("jumlah penyanyi: %d\n", jumlah_penyanyi);
    ADVNEXT();
    // lanjut pembacaan
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        int jumlah_album;
        CopyGet(&jumlah_album);
        PRINTWORD();
        // loop nama album
        for (int i=0; i<jumlah_album; i++)
        {
            int jumlah_lagu;
            ADVNEXT();
            CopyGet(&jumlah_lagu);
            PRINTWORD();
            for (int i=0; i<jumlah_lagu; i++)
            {
                PRINTWORD();
                ADVNEXT();
            }
        }
    }
    printf("kelar");
    return 0;
}