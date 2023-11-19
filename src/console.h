#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ADT\header\arrayDin.h"
#include "ADT\header\mesinkar.h"
#include "ADT\header\mesinkata.h"
#include "ADT\header\listsirkuler.h"
#include "ADT\header\map.h"
#include "ADT\header\queue.h"
#include "ADT\header\stack.h"
#include "ADT\header\info.h"
#include "ADT\header\set.h"

extern ArrayDin LOPlaylist; // list of playlists
extern List PlayList;
extern Map Data;
extern Queue QOSongs; // queue of songs
extern Stack SongHistory; // history of played songs
extern Set Artists;
extern Info CurrSong;
extern int jumlah_penyanyi, jumlah_album, jumlah_lagu; 



void START(Map* D, Set* A, char* file);
void LOAD();
void LISTDEFAULT();
void LISTPLAYLIST();
void PLAYSONG();
void PLAYPLAYLIST();
void QUEUESONG();
void QUEUEPLAYLIST();
void QUEUESWAP();
void QUEUEREMOVE();
void QUEUECLEAR();
void SONGNEXT();
void SONGPREVIOUS();
void PLAYLISTCREATE();
void PLAYLISTADDSONG();
void PLAYLISTADDALBUM();
void PLAYLISTSWAP();
void PLAYLISTREMOVE();
void PLAYLISTDELETE();
void STATUS();
void SAVE();
void QUIT();
void HELP();
void INVALIDCOMMAND();
void DISPLAY();

#endif