#include <stdio.h>
#include "..\header\map.h"

int main(){
    printf("tes createempty map dan is empty\n");
    Map M;
    CreateEmptyMap(&M);
    printf("%d\n", IsEmptyMap(M));
    GetInput();
    Word namaP = currentWord;
    GetInput();
    Word namaA = currentWord;
    GetInput();
    Word namaL = currentWord;
    InsertAlbum(&M, namaP, namaA);
    M.Count_Album += 1;
    M.Elements[0].Nama_Album = namaA;
    M.Elements[0].Nama_Penyanyi = namaP;
    M.Elements[0].Info_Lagu.Count_Lagu += 1;
    M.Elements[0].Info_Lagu.Elements[0] = namaL;
    // M.Count_Album += 1;
    // M.Elements[0].Info_Lagu.Count_Lagu 
    PrintMap(M);
}
