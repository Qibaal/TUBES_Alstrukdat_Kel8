#include "help.h"
#include <stdio.h>

void help_before() //ketika perintah dipanggil sebelum memasuki sesi
{
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
}

void help_after() //ketika perintah dipanggil setelah memasuki sesi
{
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. LIST -> Untuk menampilkandaftar lagu, playlist, daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
    printf("2. PLAY -> Untuk memutar lagu atau playlist yang dipilih.\n");
    printf("3. QUEUE -> Untuk memanipulasi queue lagu.\n");
    printf("4. SONG -> Untuk navigasi lagu yang ada pada queue lagu saat ini.\n");
    printf("5. PLAYLIST -> Untuk melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE, dan DELETE.\n");
    printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
    printf("7. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
    printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave.\n");
    printf("9. HELP -> Untuk menampilkan daftar command yang ingin dieksekusi beserta deskripsinya.\n");

}
