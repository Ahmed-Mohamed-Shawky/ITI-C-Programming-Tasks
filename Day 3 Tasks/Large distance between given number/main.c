#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        printf("Enter Input in index[%i]",i);
        scanf("%i",&arr[i]);
        _flushall();
    }
    int Dist_Num;
    printf("Enter The Number u want to get the distance for: ");
    scanf("%i",&Dist_Num);
    int larg_Dist=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]==Dist_Num)
        {
            printf("test\n");
            for(int j=i+1;j<10;j++)
            {
                if(arr[j]==Dist_Num)
                {
                    printf("Distance between indexs(%i,%i): (i-j): %i\n",i,j,j-i-1);
                    if(larg_Dist<j-i-1)
                        larg_Dist=j-i-1;
                }
            }
        }
    }
    printf("Large Distance is : %i",larg_Dist);
    return 0;
}
