#include "..\header\map.h"

int main() {
    Map m; CreateEmptyMap(&m);
    InsertWord(&m.Elements[0].Nama_Penyanyi, strToWord("iqbal"));
    InsertWord(&m.Elements[0].Nama_Album, strToWord("album1"));
    InsertSet(&m.Elements[0].Info_Lagu, strToWord("lagu1"));
    InsertWord(&m.Elements[1].Nama_Penyanyi, strToWord("adli"));
    InsertWord(&m.Elements[1].Nama_Album, strToWord("album2"));
    InsertSet(&m.Elements[1].Info_Lagu, strToWord("lagu2"));
    m.Count_Album = 2;
    for (int i = 0; i<m.Count_Album; i++)
    {
        PRINTWORD(m.Elements[i].Nama_Penyanyi);
        PRINTWORD(m.Elements[i].Nama_Album);
        PrintSet(m.Elements[i].Info_Lagu);
    }

    return 0;
}
