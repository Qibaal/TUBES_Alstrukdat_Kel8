#include <stdio.h>
#include "..\header\mesinkata.h"

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
        // printf("mashok\n");
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

int stringToInt(char* str) {
    int res = 0;
    for (int i = 0; i < currentWord.Length; ++i){
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

void ParsePlaylist(char* penyanyi, char* album, char* lagu)
{
    ADVNEXT(false);
    int i=0;
    int idx[3];
    int next = 0;
    while (currentWord.TabWord[i] != Newline)
    {
        if (currentWord.TabWord[i] == ';')
        {
            idx[next] = i;
            next++;
        }
        i++;
    }
    for (int j=0; j<idx[0]; j++)
    {
        penyanyi[j] = currentWord.TabWord[j];
    }
    for (int j=idx[0]+1; j<idx[1]; j++)
    {
        album[j-idx[0]-1] = currentWord.TabWord[j];
    }
    for (int j=idx[1]+1; j<currentWord.Length; j++)
    {
        lagu[j-idx[1]-1] = currentWord.TabWord[j];
    }
}

void PRINTWORD() {
    printf("%s\n", currentWord.TabWord);
}

int WordToInt(Word currentWord) {
/* Menerima input berupa string dan mengembalikannya dalam bentuk integer*/
    int kata = 0;
    int result = 0;
    while (kata < currentWord.Length)
    {
        result = result * 10 + (currentWord.TabWord[kata] - '0');
        kata += 1;
    }
    return result;
}