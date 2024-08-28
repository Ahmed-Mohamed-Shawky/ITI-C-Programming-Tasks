#include <stdio.h>
#include <stdlib.h>

/*int** Creat_2D_Array(int Row_size,int Col_size)
{
    int* *_ptr = (int**) (malloc(Row_size * sizeof(int*)));
    for(int _i=0;_i<_size;_i++)
        _ptr[i]=(malloc(Col_size*sizeof(int)));
    for(int _i=0;_i<Row_size;_i++)
        for(int _j=0;_j<Col_size;_j++)
            _ptr[_i][_j]=_j;
    return _ptr;
}*/
int* Creat_Array(int _size)
{
    int *_ptr = (malloc(_size * sizeof(int)));
    for(int _i=0;_i<_size;_i++)
        _ptr[_i]=_i+1;
    return _ptr;
}

int** Creat_2D_Array(int Row_size,int Col_size)
{
    int* *_ptr = (malloc(Row_size * sizeof(int*)));
    for(int _j=0;_j<Row_size;_j++)
        _ptr[_j]=Creat_Array(Col_size);
    return _ptr;
}

void Mult_Arr(int* _arr_ptr,int _size,int _Mult)
{
    for(int _i=0;_i<_size;_i++)
        _arr_ptr[_i]*=_Mult;
}

int main()
{

    int**arr = Creat_2D_Array(3,5);

    Mult_Arr(arr[0],5,2);
    Mult_Arr(arr[1],5,5);
    Mult_Arr(arr[2],5,10);

    printf("Array[0] : ");
    for(int i=0;i<5;i++)
    {
        printf("%i ",arr[0][i]);
    }
    printf("\nArray[1] : ");
    for(int i=0;i<5;i++)
    {
        printf("%i ",arr[1][i]);
    }
    printf("\nArray[2][3] : %i",arr[2][3]);

    return 0;
}
