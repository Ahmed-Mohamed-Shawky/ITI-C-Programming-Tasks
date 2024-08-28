#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    int Row=1,Col=2;
    for(int i=1;i<=9;i++)
    {
        gotoxy(Col*2,Row);
        printf("%i",i);
        if((i%3)!=0)
            {Row--; Col--;}
        else
            Row++;
        Row = (Row<1) ? 3 : Row;
        Col = (Col<1) ? 3 : Col;
    }
    printf("\n");
    return 0;
}
