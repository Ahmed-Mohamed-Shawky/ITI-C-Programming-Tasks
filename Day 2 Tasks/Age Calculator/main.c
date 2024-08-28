#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------------Age Calculator App------------------------\n");
    int DD,MM,YY;
    int C_DD=22,C_MM=10,C_YY=2023;
    int R_DD,R_MM,R_YY,MM_Days;
    do
    {
        printf("Enter Your B-Day with this format \"DD-MM-YY\": ");
        scanf("%i-%i-%i",&DD,&MM,&YY);
        _flushall();
        switch(MM)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                MM_Days = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                MM_Days = 30;
                break;
            case 2:
                MM_Days = (YY%4!=0) ? 28 : 29;
                break;
        }
    }while(DD<0||DD>MM_Days||MM<1||MM>12||YY<1980||YY>2023);

    R_YY = C_YY-YY;
    if(C_MM>DD)
        R_MM = C_MM-MM;
    else
    {
        R_YY--;
        R_MM = (C_MM+12)-MM;
    }
    if(C_DD>DD)
        R_DD = C_DD-DD;
    else
    {
        R_MM--;
        R_DD = (C_DD+MM_Days)-DD;
        if(MM=2)
        {
            if(YY%4!=0)R_DD+=2;
            else R_DD++;
        }
    }
    printf("day: %i Month: %i Year: %i",R_DD,R_MM,R_YY);
    return 0;
}
