/* File: play.c */
#include <stdio.h>
#include <stdlib.h>
#include "play.h"

int songCount = sizeof(songs) / sizeof(Song);

// Fungsi untuk membandingkan dua string
int compareStrings(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 == *s2) {
        return 0; // String sama
    } else if (*s1 < *s2) {
        return -1; // String pertama lebih kecil
    } else {
        return 1; // String pertama lebih besar
    }
}

// Fungsi untuk menampilkan daftar penyanyi
void displayArtists() {
    for (int i = 0; i < songCount; i++) {
        if (i == 0 || compareStrings(songs[i].artist, songs[i - 1].artist) != 0) {
            printf("%s\n", songs[i].artist);
        }
    }
}

// Fungsi untuk menampilkan daftar album berdasarkan penyanyi
void displayAlbumsByArtist(char *artist) {
    for (int i = 0; i < songCount; i++) {
        if (compareStrings(songs[i].artist, artist) == 0) {
            printf("%s\n", songs[i].album);
        }
    }
}

// Fungsi untuk menampilkan daftar lagu berdasarkan penyanyi dan album
void displaySongsByAlbum(char *artist, char *album) {
    for (int i = 0; i < songCount; i++) {
        if (compareStrings(songs[i].artist, artist) == 0 && compareStrings(songs[i].album, album) == 0) {
            printf("%s\n", songs[i].songTitle);
        }
    }
}
