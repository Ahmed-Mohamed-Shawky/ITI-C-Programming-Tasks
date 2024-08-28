#include <stdio.h>
#include <stdlib.h>



int main()
{
    float Students[4][5]={{43,37,28,19,26},{14,42,32,16,38},{25,26,48,31,18},{9,12,39,47,3}};
    for(int i=0;i<5;i++)
    {
        printf("\n----------------Subject %i----------------\n\n",i+1);
        float average=0;
        for(int j=0;j<4;j++)
        {
            average+=Students[j][i];
            printf("Student_%i score in subject_%i= %.1f\n",j+1,i+1,Students[j][i]);
        }
        average/=4;
        printf("\nAverage Value of Subject_%i is: %.2f\n",i+1,average);
        average=0;
    }
    return 0;
}
