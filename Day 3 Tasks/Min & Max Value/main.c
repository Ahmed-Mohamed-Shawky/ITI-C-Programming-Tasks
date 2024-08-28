#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10]={0};
    for (int i=0;i<10;i++)
    {
        printf("Enter Input in indix[%i]: ",i);
        scanf("%i",&arr[i]);
    }
    int Min=arr[0],Max=arr[0];
    for (int i=1;i<10;i++)
    {
        Min = (arr[i]<Min)?arr[i]:Min;
        Max = (arr[i]>Max)?arr[i]:Max;
    }
    printf("Max Value is: %i\n",Max);
    printf("Min Value is: %i\n",Min);
    return 0;
}
