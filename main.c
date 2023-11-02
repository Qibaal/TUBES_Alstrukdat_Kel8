
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main(){
    FILE *file;
    char dump[MAX_LINE_LENGTH];
    int c_penyanyi,c_album,c_lagu;

    file = fopen("dummy.txt", "r");
    if (file == NULL) {
        printf("File konfigurasi aplikasi tidak berhasil dibaca.\n");
        exit(0);
    }

    printf("Isi file:\n");

    // fgets(line, MAX_LINE_LENGTH, file) membaca satu baris teks dari file
    // fgets(buffer, MAX_LINE_LENGTH, file);
    fscanf(file, "%d", &c_penyanyi);
    for(int i=0; i<c_penyanyi; i++){
        fscanf(file, "%d %s", &c_album, dump);
        printf("%s1\n", dump);
        for (int j=0; j<c_album; j++){
            fscanf(file, "%d %s", &c_lagu, dump);
            printf("%s2\n", dump);
            for(int k=0; k<c_lagu; k++){
                fscanf(file, "%s", dump);
                printf("%s3\n", dump);
            }
        }
    }
    // sscanf(buffer, "%d %c", &N, &dump);
    // int i;
    // while(dump[i]!='\0'){
    //     printf("%s4\n", dump);
    //     i++;
    // }
    

    fclose(file);
    return 0;
}

