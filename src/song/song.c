#include "song.h"

void nextSong(SongQueue* queue) {
    if (!isEmpty(*queue)) {
        Song currentSong = dequeue(queue);
        enqueue(queue, currentSong);
    }
}

void previousSong(SongQueue* queue) {
    if (!isEmpty(*queue)) {
        Song currentSong = dequeue(queue);
        SongNode* newNode = (SongNode*)malloc(sizeof(SongNode));
        if (newNode == NULL) {
            fprintf(stderr, "Memory allocation failed. Cannot move to the previous song.\n");
            exit(1);
        }

        newNode->song = currentSong;
        newNode->next = queue->front;
        queue->front = newNode;

        if (queue->rear == NULL) {
            queue->rear = newNode;
        }
    }
}
