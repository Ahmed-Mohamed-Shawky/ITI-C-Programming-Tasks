#include <stdio.h>
#include <stdlib.h>

void _Swap(int *x,int *y);

int main()
{
    int Num_1=5,Num_2=12;
    printf("Before Swap Num_1: %i   Num_2: %i\n",Num_1,Num_2);
    _Swap(&Num_1,&Num_2);
    printf("After Swap Num_1: %i   Num_2: %i\n",Num_1,Num_2);
    return 0;
}

void _Swap(int *x,int *y)
{
    *x+=*y;
    *y=*x-*y;
    *x-=*y;
}
