#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;
int val;

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
    while ((currentChar == Newline) && (!IsEOF()))
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
}

void ADVNEXT(boolean readDigit) {
    IgnoreBlanks();
    IgnoreNewLines();
    if (currentChar == Newline)
    {
        EndWord = true;
        IgnoreNewLines();
    }
    else
    {
        EndWord = false;
        CopyGet(readDigit);
        IgnoreBlanks();
        IgnoreNewLines();
    }
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
    while ((currentChar != Newline) && (!IsEOF()))
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

void CopyGet(boolean readDigit)
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    if (readDigit)
    {
        while(currentChar != BLANK && currentChar != Newline && !IsEOF())
        {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
            ADV();
        }
        val = stringToInt(currentWord.TabWord);
        currentWord.Length = 0;
    }
    while(currentChar == BLANK) ADV();

    while(currentChar != Newline && !IsEOF())
    {
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
    }
    currentWord.TabWord[currentWord.Length] = '\0';
}

int stringToInt(char* str){
    int res = 0;
    for (int i = 0; i < currentWord.Length; ++i){
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

void PRINTWORD() {
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}