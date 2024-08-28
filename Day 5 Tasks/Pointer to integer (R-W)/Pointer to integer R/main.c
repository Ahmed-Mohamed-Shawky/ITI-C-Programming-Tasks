#include <stdio.h>
#include <stdlib.h>

int main()
{
    int _integer= 5;
    int *ptr = &_integer;

    printf("ptr = integer adress = %i\n",ptr);
    printf("ptr value= integer value = %i\n",*ptr);
    *ptr += 2;
    printf("ptr value= integer value +2 = %i\n",*ptr);
    return 0;
}
