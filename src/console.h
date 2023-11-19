#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT\header\mesinkar.h"
#include "ADT\header\mesinkata.h"
#include "ADT\header\listsirkuler.h"
#include "ADT\header\map.h"
#include "ADT\header\queue.h"
#include "ADT\header\stack.h"
#include "ADT\header\circular_queue.h"

void START();
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