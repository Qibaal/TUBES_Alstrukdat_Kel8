/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "..\..\boolean.h"
#include "mesinkar.h"

#define NMax 100
#define BLANK ' '
#define Newline '\n'
#define EOI ';'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;
extern char currentInput;
extern int val;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreNewLines();
/* Mengabaikan satu atau beberapa Newline
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ Newline*/


void STARTWORD(char* path);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVNEXT(boolean readDigit);
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin Newline
          Jika currentChar = Newline, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyGet(boolean readDigit);

void GetInput();

void ParsePlaylist(Word *penyanyi, Word *album, Word *lagu);

int stringToInt(char *str);

Word strToWord(char* str);

void InsertWord(Word *t, Word w);

void PRINTWORD(Word w);

void ConcatString(char* res, char* a, char* b);

boolean WordCompare(Word w, Word input);
/* Menerima dua input berupa tipe Word dan mengembalikan sebuah boolean yang menyatakan apakah kedua Word tersebut sama atau tidak */

#endif