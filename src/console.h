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

extern int jumlah_penyanyi, jumlah_album, jumlah_lagu; 

void STARTCONSOLE(Map* D, Set* A, Queue *QS, char* file); // done
void LOAD(ArrayDin *LOP, Info *curr, Stack *hist, Queue *QS); // done
void LISTDEFAULT(Map *D, Set *P); // done
void LISTPLAYLIST(ArrayDin PL); // done
void PLAYSONG(Info *CURR, Word *CURRPL, Set *A, Map *D, Queue *QS, Stack *hist); // done
void PLAYPLAYLIST(Info *CURR, Word *CURRPL, Set *A, Map *D, Queue *QS, Stack *hist, ArrayDin *LP); // done
void QUEUESONG(Set *A, Map *D, Queue *QS); // done
void QUEUEPLAYLIST(Set *A, Map *D, Queue *QS, ArrayDin *LP); // done
void QUEUESWAP(Queue *QS); // done
void QUEUEREMOVE(Queue *QS); // done
void QUEUECLEAR(Queue *QS); // done
void SONGNEXT(Info *CURR, Queue *QS, Stack *hist); // done
void SONGPREVIOUS(Info *CURR, Queue *QS, Stack *hist); // done
void CREATEPLAYLIST(ArrayDin *LP); // done
void ADDSONGPLAYLIST(ArrayDin *LP, Set *A, Map *D); // done
void ADDALBUMPLAYLIST(ArrayDin *LP, Set *A, Map *D); // done
void PLAYLISTSWAP(ArrayDin *LP);
void PLAYLISTREMOVE(ArrayDin *LP); // done
void PLAYLISTDELETE(ArrayDin *LP); // done
void STATUS(Info *CURR, Queue QS, Word *CURRPL); // done
void SAVE(); 
void QUIT(); // done (perlu di combine sm save)
void HELP(boolean inSesh); // done
boolean CHECKCOMMAND(Word W, boolean inSesh); // done

#endif