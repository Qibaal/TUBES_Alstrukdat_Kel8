/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "..\header\mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean EOL;

static FILE *pita;
int retval = 1;

/*path ke dummy txt tergantung dari cd co: ini karena run di src*/
// char s[] = "ADT/MesinKarakter/dummy.txt";

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

/* Algoritma */
void START(char* path)
{
       pita = fopen(path, "r");
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       if (!retval)
       {
              fclose(pita);
       }
       if (currentChar == '\n')
       {
              EOL = true;
       }
}

boolean IsEOF() {
       return feof(pita);
}