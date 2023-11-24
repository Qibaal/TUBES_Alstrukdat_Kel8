#include "mesinkar.h"
#include "..\header\stdio.h"

char currentChar;
boolean EOP;
int retval;
boolean EOL;

int main(){
    char *file = "file.txt";
 printf("Test ADT Mesin Karakter\n");
 
 /* Tes Mesin Karakter */
 printf("Tes Mesin Karakter\n");
 printf("----------------------\n");

 printf("Tes START dari file\n");
 START(file);
 printf("Tes GetCC dan ADV\n");
    printf("%c\n", currentChar);
    ADV();
    printf("%c", currentChar);
 while (currentChar != '\n')
 {
  printf("%c\n", currentChar);
  ADV();
 }
 printf("----------------------\n\n");

}
