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
        int jumlah_album = GetVal(currentWord.TabWord);
        PRINTWORD();
        // loop nama album
        for (int i=0; i<jumlah_album; i++)
        {
            ADVNEXT();
            int jumlah_lagu = GetVal(currentWord.TabWord);
            PRINTWORD();
            for (int i=0; i<jumlah_lagu; i++)
            {
                ADVNEXT();
                PRINTWORD();
            }
        }
    }
    
    printf("kelar");
    return 0;
}