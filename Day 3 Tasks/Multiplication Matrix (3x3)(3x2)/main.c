#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrex_1[3][3]={ {5 ,3 ,7},
                         {4 ,9 ,1},
                         {2 ,6 ,3} };
    int Matrex_2[3][2] = {{4 ,7},
                          {3 ,2},
                          {1 ,6} };

    int result[3][2] = {{0},{0},{0}};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                result[i][j]+=Matrex_1[i][k]*Matrex_2[k][j];
                printf("%i * %i\n",Matrex_1[i][k],Matrex_2[k][j]);
            }
            printf("------\n");
        }
        printf("*****\n");
    }

    //printf("Result : ")
    for(int i=0;i<3;i++)
    {
        printf("Result :");
        for(int j=0;j<2;j++)
        {
            printf("  %i",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
