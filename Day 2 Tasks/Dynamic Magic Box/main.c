#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Pow(x) ((x)*(x))

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    gotoxy(0,0);
    int Box_Size,Col,Row=1;

    printf("Enter the Box size \"Odd Number Between(3~19)\": ");
    scanf("%i",&Box_Size);
    while(Box_Size%2==0 || Box_Size==1 || Box_Size>19 /*--> CMD Screen limit */ )
        {
            printf("Plz Enter Odd Number Between(3~19): ");
            scanf("%i",&Box_Size);
        }
    Col = Box_Size/2+1;
    system("cls");
    for(int i=1;i<=Pow(Box_Size);i++)
    {
        gotoxy(Col*(3+Box_Size/10)+10,Row+10);
        printf("%i",i);
        if(i%Box_Size!=0)
            { Col--; Row--; }
        else
            Row++;
        Col = (Col<1) ? Box_Size : Col;
        Row = (Row<1) ? Box_Size : Row;
    }
    gotoxy(0,0);
    return 0;
}
