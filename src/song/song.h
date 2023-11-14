#ifndef SONG_H
#define SONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/Queue/queue.c"

#define MAX_SONG_NAME_LENGTH 50

typedef struct {
    char name[MAX_SONG_NAME_LENGTH];
} Song;

typedef struct SongNode {
    Song song;
    struct SongNode* next;
} SongNode;

typedef struct {
    SongNode* front;
    SongNode* rear;
} SongQueue;


void nextSong(SongQueue* queue);
void previousSong(SongQueue* queue);

#endif
