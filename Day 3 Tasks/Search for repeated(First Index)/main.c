#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10]={0};
    for (int i=0;i<10;i++)
    {
        printf("Enter Input in index[%i]: ",i);
        scanf("%i",&arr[i]);
        _flushall();
    }

    int search_Num;
    printf("Enter the Number u want to search: ");
    scanf("%i",&search_Num);
    char found = 0;
    for (int i=0;i<10;i++)
    {
        if(arr[i]==search_Num)
        {
            printf("Number (%i) found in index: %i\n",search_Num,i);
            found++;
            break;
        }
    }
    if(found==0)
        printf("Number (%i) not found",search_Num);

    return 0;
}
