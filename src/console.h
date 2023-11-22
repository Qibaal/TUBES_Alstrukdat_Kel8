#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "boolean.h"
#include "ADT\header\arrayDin.h"
#include "ADT\header\mesinkar.h"
#include "ADT\header\mesinkata.h"
#include "ADT\header\listsirkuler.h"
#include "ADT\header\map.h"
#include "ADT\header\set.h"
#include "ADT\header\queue.h"
#include "ADT\header\stack.h"
#include "ADT\header\info.h"

// extern ArrayDin LOPlaylist; // list of playlists
// extern List PlayList;
// extern Map DATA;
// extern Queue QOSongs; // queue of songs
// extern Stack SongHistory; // history of played songs
// extern Set Artists;
// extern Info CurrSong;
extern int jumlah_penyanyi, jumlah_album, jumlah_lagu; 


void STARTCONSOLE(Map* D, Set* A, char* file);
void LOAD(ArrayDin *LOP, Info *curr, Stack *hist, Queue *QS);
void LISTDEFAULT(Map *D, Set *P);
void LISTPLAYLIST(ArrayDin PL);
void PLAYSONG(Info *CURR, Set *A, Map *D, Queue *QS, Stack *hist);
void PLAYPLAYLIST(Info *CURR, Word *CURRPL, Set *A, Map *D, Queue *QS, Stack *hist, ArrayDin *LP);
void QUEUESONG(Set *A, Map *D, Queue *QS);
void QUEUEPLAYLIST(Set *A, Map *D, Queue *QS, ArrayDin *LP);
void QUEUESWAP(Queue *QS);
void QUEUEREMOVE(Queue *QS);
void QUEUECLEAR(Queue *QS);
void SONGNEXT(Info *CURR, Queue *QS, Stack *hist);
void SONGPREVIOUS(Info *CURR, Queue *QS, Stack *hist);
void CREATEPLAYLIST(ArrayDin *LP);
void ADDSONGPLAYLIST(ArrayDin *LP, Set *A, Map *D);
void ADDALBUMPLAYLIST(ArrayDin *LP, Set *A, Map *D);
void PLAYLISTSWAP(ArrayDin *LP);
void PLAYLISTREMOVE(ArrayDin *LP);
void PLAYLISTDELETE(ArrayDin *LP);
void STATUS(Info *CURR, Queue QS, Word *CURRPL);
void SAVE();
void QUIT();
void HELP(boolean inSesh);
boolean CHECKCOMMAND(Word W, boolean inSesh);

#endif