#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreNewLines()
{
    while((!IsEOF()) && (currentChar == Newline))
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreNewLines();
    ADVNEXT();
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVNEXT() {
    IgnoreBlanks();
    IgnoreNewLines();
    CopyWord();
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != Newline)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

void CopyGet(int *n) {
    CopyWord();
    *n = GetVal(&currentWord);
    currentWord.Length = 0;
    ADV();

    while(currentChar != Newline)
    {
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
    }
}

int GetVal(char *str) {
    int i = 0, res = 0;
    while (str[i] != '\0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

void PRINTWORD() {
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}