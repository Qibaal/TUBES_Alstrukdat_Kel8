#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
    START();
    int jumlah_penyanyi = GetVal(currentWord.TabWord);
    for (int i=0; i<jumlah_penyanyi; i++)
    {
        int jumlah_album;
        ADVNEXT();
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
                ADVNEXT();
                PRINTWORD();
            }
        }
    }
    printf("kelar");
    return 0;
}