#include <stdio.h>
#include <stdlib.h>

void Arry_Mult(int _array[],int _size,int Mult_Num);
void Arry_Mult_V2(int *_array,int _size,int Mult_Num);

int main()
{
    int arr[5]={1,2,3,4,5};
    printf("Before Mult : ");
    for(int i=0;i<5;i++)
        printf("%i ",arr[i]);

    Arry_Mult(arr,5,2);
    printf("\nAfter Mult : ");
    for(int i=0;i<5;i++)
        printf("%i ",arr[i]);

    Arry_Mult(arr,5,10);
    printf("\nAfter Mult again : ");
    for(int i=0;i<5;i++)
        printf("%i ",arr[i]);

    return 0;
}


void Arry_Mult(int _array[],int _size,int Mult_Num)
{
    for(int i=0;i<_size;i++)
        _array[i]*= Mult_Num;
}

void Arry_Mult_V2(int *_array,int _size,int Mult_Num)
{
    for(int i=0;i<_size;i++)
        _array[i]*= Mult_Num;
}
