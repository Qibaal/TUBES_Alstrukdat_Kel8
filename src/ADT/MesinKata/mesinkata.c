#include <stdio.h>
#include "..\header\mesinkata.h"

boolean EndWord;
Word currentWord;
char currentInput;
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

void STARTWORD(char* path)
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(path);
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

void GetInput()
{
    currentWord.Length = 0;
    currentInput = getc(stdin);
    while (currentInput != EOI)
    {
        currentWord.TabWord[currentWord.Length] = currentInput;
        currentWord.Length++;
        currentInput = getc(stdin);
    }
}

int stringToInt(char* str) {
    int res = 0;
    for (int i = 0; i < currentWord.Length; ++i){
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

int WordToInt(Word w)
{
    int res = 0;
    for (int i = 0; i < w.Length; ++i){
        res = res * 10 + (w.TabWord[i] - '0');
    }
    return res;
}

Word strToWord(char* str)
{
    Word t; t.Length = 0;
    for (int i=0; str[i] != '\0'; ++i)
    {
        t.TabWord[i] = str[i];
        t.Length++;
    }
    return t;
}

void WordToStr(Word w, char* input)
{
    int i;
    for (i=0; i<w.Length; i++)
        input[i] = w.TabWord[i];
    input[i+1] = '\0';
}

void ParsePlaylist(Word *penyanyi, Word *album, Word *lagu)
{
    ADVNEXT(false);
    int i=0, next = 0;
    int idx[3];
    while (currentWord.TabWord[i] != Newline)
    {
        if (currentWord.TabWord[i] == ';')
        {
            idx[next] = i;
            next++;
        }
        i++;
    }
    penyanyi->Length = 0;
    for (int j=0; j<idx[0]; j++)
    {
        penyanyi->TabWord[j] = currentWord.TabWord[j];
        penyanyi->Length++;
    }
    album->Length = 0;
    for (int j=idx[0]+1; j<idx[1]; j++)
    {
        album->TabWord[j-idx[0]-1] = currentWord.TabWord[j];
        album->Length++;
    }
    lagu->Length = 0;
    for (int j=idx[1]+1; j<currentWord.Length; j++)
    {
        lagu->TabWord[j-idx[1]-1] = currentWord.TabWord[j];
        lagu->Length++;
    }
}

void InsertWord(Word *t, Word w)
{
    t->Length = w.Length;
    for (int i=0; i<w.Length; i++)
    {
        t->TabWord[i] = w.TabWord[i];
    }
}

void PRINTWORD(Word w) 
{
    for (int i=0; i<w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

void PRINTWORD2(Word w)
{
    for (int i=0; i<w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
    printf(" ");
}

void ConcatString(char* res, char* a, char* b)
{
    int i;
    for (i = 0; a[i] != '\0'; ++i)
    {
        res[i] = a[i];
    }
    for (int j = 0; b[j] != '\0'; ++j)
    {
        res[i] = b[j];
        i++;
    }
    res[i] = '\0';
}

boolean WordCompare(Word w, Word input)
/* Menerima dua input berupa tipe Word dan mengembalikan sebuah boolean yang menyatakan apakah kedua Word tersebut sama atau tidak */
{
    // KAMUS LOKAL
    int i = 0;
    // ALGORITMA
    while (i<w.Length)
    {
        if (w.TabWord[i] == input.TabWord[i] || w.TabWord[i] == input.TabWord[i] + 32 || w.TabWord[i] == input.TabWord[i] - 32)
        {
            i++;
        }
        else return false;
    }
    return true;
}

void CompressInput()
{
   if (currentWord.TabWord[0] == '\n' || currentWord.TabWord[0] == ' ')
   {
        for (int i=1; i<currentWord.Length; i++)
        {
            currentWord.TabWord[i-1] = currentWord.TabWord[i];
        }
   }
   currentWord.Length--;
}

// int main()
// {
//     Word w1, w2;
//     w1.Length = 5; w2.Length = 5;
//     w1.TabWord[0] = 'z';
//     w1.TabWord[1] = 'q';
//     w1.TabWord[2] = 'b';
//     w1.TabWord[3] = 'a';
//     w1.TabWord[4] = 'l';

//     w2.TabWord[0] = 'Z';
//     w2.TabWord[1] = 'Q';
//     w2.TabWord[2] = 'B';
//     w2.TabWord[3] = 'A';
//     w2.TabWord[4] = 'L';

//     if (WordCompare(w1,w2)) printf("sama\n");
//     else printf("ngga\n");

//     return 0;
// }