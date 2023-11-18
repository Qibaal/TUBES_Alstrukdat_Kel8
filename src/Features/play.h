#ifndef PLAY_H
#define PLAY_H

#include <stdio.h>
/* DEFINISI INSTRUKTOR SONG*/
typedef struct {
    char artist[50];
    char album[50];
    char songTitle[50];
} Song;

Song songs[] = {
    {"New Jeans", "First Album", "Song A"},
    {"New Jeans", "First Album", "Song B"},
    {"BLACKPINK", "BORN PINK", "Pink Venom"},
    {"BLACKPINK", "BORN PINK", "Shut Down"},
    {"BLACKPINK", "BORN PINK", "Typa Girl"},
    {"BLACKPINK", "BORN PINK", "Yeah Yeah Yeah"},
    {"BLACKPINK", "BORN PINK", "Hard to Love"},
    {"BLACKPINK", "BORN PINK", "The Happiest Girl"},
    {"BLACKPINK", "BORN PINK", "Tally"},
    {"BLACKPINK", "BORN PINK", "Ready for Love"},
    {"Central Cee", "Central Album", "Central Song"},
    {"Rich Brian", "Rich Album", "Rich Song"},
    {"Denny Caknan", "Denny Album", "Denny Song"},
    {"Via Vallen", "Via Album", "Via Song"}
};

int compareStrings(char *s1, char *s2);
/*Fungsi untuk membandingkan dua string*/
void displayArtists();
// Fungsi untuk menampilkan daftar penyanyi
void displayAlbumsByArtist(char *artist);
// Fungsi untuk menampilkan daftar album berdasarkan penyanyi
void displaySongsByAlbum(char *artist, char *album);
// Fungsi untuk menampilkan daftar lagu berdasarkan penyanyi dan album

#endif