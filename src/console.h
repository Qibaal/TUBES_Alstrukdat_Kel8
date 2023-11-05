#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "boolean.h"
#include "./ADT/ListDinamik/listdinamik.h"
#include "./ADT/ListStatik/liststatik.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Set/set.h"
#include "./ADT/Map/map.h"
#include "./ADT/ListDefault/listdefault1.h"
#include "./ADT/ListDefault/listdefault2.h"

void listDefault1()
{
    char argument1, argument2;
    char str1[100], str2[100];
    printf("Daftar Penyanyi :\n");
    listPenyanyi();
    printf("Ingin melihat album yang ada?(Y/N):\n");
    scanf("%c", argument1);
    if (argument1 == 'Y' || argument1 == 'y')
    {
        printf("Pilih penyanyi untuk melihat album mereka:\n");
        scanf("%s", str1);
        listAlbum();
        printf("Ingin melihat lagu yang ada?(Y/N):\n");
        scanf("%c", argument2);
        if (argument2 == 'Y' || argument2 == 'y')
        {
            printf("Pilih album untuk melihat lagu yang ada di album:\n");
            scanf("%s", str2);
            printf("Daftar lagu di %s :", str2);
            listLagu();
        }
    }
}

#endif