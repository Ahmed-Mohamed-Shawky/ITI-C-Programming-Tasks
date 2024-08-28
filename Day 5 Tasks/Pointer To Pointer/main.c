#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int *ptr_x = &x;
    int **ptr_ptr = &ptr_x;

    printf("X Value: %i\n",x);
    printf("X Addressee: %i\n",&x);
    printf("-----------------------------\n");
    printf("ptr->x Value: %i\n",ptr_x);
    printf("ptr->x Addressee: %i\n",&ptr_x);
    printf("ptr->x pointed Value: %i\n",*ptr_x);
    printf("-----------------------------\n");
    printf("ptr->ptr Value: %i\n",ptr_ptr);
    printf("ptr->ptr Addressee: %i\n",&ptr_ptr);
    printf("ptr->ptr pointed Value: %i\n",*ptr_ptr);
    printf("ptr->ptr->x pointed pointed Value: %i\n",(*(*ptr_ptr)));
    return 0;
}
