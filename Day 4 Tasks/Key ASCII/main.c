#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Press Any button: ");
    char ch = getch();
    printf("\nThe Key u pressed is %s ASCII and it's Value is:%i",(ch==-32)?"Extended":"Normal",(ch==-32)?getch():ch);
    /*for(int i =0;i<12;i++)
    {
        printf("%i",i);
    }*/
    return 0;
}
