#include <stdio.h>
#include <stdlib.h>

/*int[] creat_array()//Compiler Error
{
    int arr[]= {1,2,3,4,5};
    return arr;
}*/

int creat_array_v2()
{
    int arr[]= {1,2,3,4,5};
    return arr;
}

int* creat_array_v3()
{
    int arr[]= {1,2,3,4,5};
    return arr;
}

int* creat_array_v4()
{
    static int arr[]= {1,2,3,4,5};
    return &arr;
}

int main()
{
    int _arr = creat_array_v2();
    int *_arr_2 = creat_array_v3();
    int *_arr_3 = creat_array_v4();
    printf("Array : ");
    for(int i=0;i<5;i++)
    {
        //printf("%i ",_arr[i]); //Compiler Error
        //printf("%i ",_arr_2[i]); //Logical Error "Run time Error"
        printf("%i ",_arr_3[i]);
    }
    return 0;
}
