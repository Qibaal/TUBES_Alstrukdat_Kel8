#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char** song_titles;
    int num_songs;
} Album;

typedef struct {
    char* name;
    Album* albums;
    int num_albums;
} Artist;

int main() {
    FILE* file = fopen("dummy.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    int num_artists;
    fscanf(file, "%d", &num_artists);

    Artist* artists = malloc(num_artists * sizeof(Artist));

    for (int i = 0; i < num_artists; i++) {
        artists[i].name = malloc(50 * sizeof(char));
        fscanf(file, "%d %[^\n]", &artists[i].num_albums, artists[i].name);
        printf("%d \n", artists[i].num_albums);

        artists[i].albums = malloc(artists[i].num_albums * sizeof(Album));

        for (int j = 0; j < artists[i].num_albums; j++) {
            artists[i].albums[j].song_titles = malloc(50 * sizeof(char*));

            char* album_name = malloc(50 * sizeof(char));
            fscanf(file, "%d %[^\n]", &artists[i].albums[j].num_songs, album_name);
            printf("%d \n", artists[i].albums[j].num_songs);

            for (int k = 0; k < artists[i].albums[j].num_songs; k++) {
                artists[i].albums[j].song_titles[k] = malloc(50 * sizeof(char));
                fscanf(file, " %[^\n]", artists[i].albums[j].song_titles[k]);
                printf("%s \n", artists[i].albums[j].song_titles[k]);
            }

            free(album_name);
        }
    }

    fclose(file);
    return 0;
}

