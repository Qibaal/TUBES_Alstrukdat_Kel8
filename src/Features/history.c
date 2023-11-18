/* File: history.c */

#include <stdio.h>
#include "history.h"

void history (Stack historySong, Word Command)
/* Menampilkan seluruh riwayat lagu yang telah diputar oleh user 
    I.S. sembarang
    F.S. menampilkan seluruh current song yang sudah dimainkan. History mungkun kosong */
{
    // KAMUS LOKAL
    int currentSong, count = 0;
    InfoStack x;

    // ALGORITMA
    currentSong = WordToInt(Command);
    count = 1;
    if (currentSong <= 0) {
        printf("Tidak ada lagu yang diputar.\n\n");
    } else {
        if (IsEmpty(historySong)) {
            printf("Belum ada lagu yang dimainkan.\n\n");
        } else {
            printf("Daftar lagu yang telah diputar\n");
            while (!IsEmpty(historySong) && currentSong > 0) {
                printf("  %d. ", count);
                PRINTWORD(InfoTop(historySong));
                Pop(&historySong, &x);
                count++;
                currentSong--;
                printf("\n");
            }
            printf("\n");
        }
    }
}