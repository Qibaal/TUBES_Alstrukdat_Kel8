#include <stdio.h>
#include <string.h>
#include "song.h"

void playNextSong(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No songs to play next.\n");
        return;
    }

    Song currentSong = peek(queue);
    dequeue(queue); 
    printf("Playing next song: %s by %s from the album %s\n", currentSong.songTitle, currentSong.artist, currentSong.album);
}

void playPreviousSong(Stack *history) {
    if (isEmpty(history)) {
        printf("History is empty. No previous songs.\n");
        return;
    }

    Song previousSong = pop(history); 
    printf("Playing previous song: %s by %s from the album %s\n", previousSong.songTitle, previousSong.artist, previousSong.album);
}
