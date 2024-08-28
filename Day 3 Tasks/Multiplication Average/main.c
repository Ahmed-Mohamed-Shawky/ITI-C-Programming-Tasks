#include <stdio.h>
#include <stdlib.h>

#define M_1_row 3
#define M_1_col 4

#define M_2_row 4
#define M_2_col 3

int main()
{
    int Matrex_1[M_1_row][M_1_col]={ {5 ,3 ,1, 4},
                                     {4 ,9 ,2 ,3},
                                     {2 ,6 ,5 ,1} };

    int Matrex_2[M_2_row][M_2_col] = { {4 , 2, 5},
                                       {3 , 4, 1},
                                       {4 , 3, 6},
                                       {5 , 1, 2} };

    int result[3][1] = {{0},{0},{0}};
    for(int i=0;i<M_1_row;i++)
    {
        for(int j=0;j<M_2_col;j++)
        {
            for(int k=0;k<M_1_col;k++)
            {
                result[i][j]+=Matrex_1[i][k]*Matrex_2[k][j];
            }
        }
    }
    //printf("Result Matrix is : ");
    for(int i=0;i<M_1_row;i++)
    {
        printf("Result : ");
        for(int j=0;j<M_2_col;j++)
            printf("%i  ",result[i][j]);
        printf("\n");
    }
    return 0;
}
