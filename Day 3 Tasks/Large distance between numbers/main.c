#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[]={1,9,1,3,4,6,1,9,7,9};

    int larg_Dist=0;
    for(int i=0;i<10;i++)
    {
        //printf("test\n");
        for(int j=i+1;j<10;j++)
        {
            if(arr[j]==arr[i])
            {
                printf("Distance between Number(%i) in indexs(%i,%i): (i-j): %i\n",arr[i],i,j,j-i-1);
                if(larg_Dist<j-i-1)
                    larg_Dist=j-i-1;
            }
        }
    }
    printf("Large Distance is : %i",larg_Dist);
    return 0;
}
