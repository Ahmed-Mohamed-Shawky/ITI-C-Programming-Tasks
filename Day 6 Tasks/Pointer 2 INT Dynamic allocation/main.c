#include <stdio.h>
#include <stdlib.h>

int* Creat_Array(int _size)
{
    int *_ptr = (malloc(_size * sizeof(int)));
    for(int _i=0;_i<_size;_i++)
        _ptr[_i]=_i;
    return _ptr;
}

void Mult_Arr(int* _arr_ptr,int _size,int _Mult)
{
    for(int _i=0;_i<_size;_i++)
        _arr_ptr[_i]*=_Mult;
}

int main()
{
    int *arr_1 = Creat_Array(8);
    int *arr_2 = Creat_Array(12);
    Mult_Arr(arr_1,8,2);
    Mult_Arr(arr_2,12,10);
    printf("Array_1 : ");
    for(int i=0;i<8;i++)
    {
        printf("%i ",arr_1[i]);
    }
    printf("\nArray_2 : ");
    for(int i=0;i<12;i++)
    {
        printf("%i ",arr_2[i]);
    }

    return 0;
}
