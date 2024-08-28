#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5]= {1,2,3,4,5};
    int *ptr = arr;

    printf("ptr = arr adress = %i\n",ptr);
    printf("ptr value= first item value = %i\n",*ptr);
    printf("ptr value= second item value = %i\n",*(ptr+1));
    printf("ptr value= second item value +1 = %i\n",++*(ptr+1));
    printf("-----------------------\n");
    printf("ptr value= first item value = %i\n",ptr[0]);
    printf("ptr value= second item value = %i\n",ptr[1]);
    printf("ptr value= second item value +2 = %i\n",ptr[1]+2);
    return 0;
}
