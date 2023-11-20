#ifndef SONG_H
#define SONG_H

#include <stdio.h>
#include "stack.h"
#include "queue.h"

typedef struct Song {
    char artist[100];
    char album[100];
    char songTitle[100];
} Song;


void playNextSong(Queue *queue);
void playPreviousSong(Stack *history); 

#endif /* SONG_H */
