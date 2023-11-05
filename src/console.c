#include <console.h>

void listDefault()
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