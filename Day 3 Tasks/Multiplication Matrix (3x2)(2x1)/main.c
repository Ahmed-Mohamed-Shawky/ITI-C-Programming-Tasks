#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrex_1[3][2]={ {5 ,3},
                     {4 ,9},
                     {2 ,6} };
    int Matrex_2[2][1] = {{4},
                          {3} };

    int result[3][1] = {{0},{0},{0}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            result[i][0]+=Matrex_1[i][j]*Matrex_2[j][0];
        }
    }
    printf("Result Matrix is : ");
    for(int i=0;i<3;i++)
    {
        printf("%i  ",result[i][0]);
    }
    return 0;
}
