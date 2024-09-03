#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------------Age Calculator App------------------------\n");
    int DD, MM, YY;
    int C_DD = 3, C_MM = 9, C_YY = 2024;
    int R_DD, R_MM, R_YY, MM_Days;

    do
    {
        printf("\nEnter Your Birth Date in the format \"DD-MM-YYYY\": ");
        scanf("%d-%d-%d", &DD, &MM, &YY);
        fflush(stdin);  // Flush input buffer

        switch(MM)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                MM_Days = 31;
                break;
            case 4: case 6: case 9: case 11:
                MM_Days = 30;
                break;
            case 2:
                MM_Days = (YY % 4 == 0 && (YY % 100 != 0 || YY % 400 == 0)) ? 29 : 28;
                break;
            default:
                MM_Days = 0;  // Invalid month
        }
    } while(DD < 1 || DD > MM_Days || MM < 1 || MM > 12 || YY < 1980 || YY > C_YY);

    // Calculate age
    R_YY = C_YY - YY;
    R_MM = C_MM - MM;
    R_DD = C_DD - DD;

    if (R_DD < 0)
    {
        R_MM--;
        R_DD += MM_Days;
    }

    if (R_MM < 0)
    {
        R_YY--;
        R_MM += 12;
    }

    printf("\nYour age is: %d years, %d months, and %d days\n", R_YY, R_MM, R_DD);

    return 0;
}
