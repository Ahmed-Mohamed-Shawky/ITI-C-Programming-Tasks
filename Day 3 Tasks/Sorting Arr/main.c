#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10]={0};
    for (int i=0;i<10;i++)
    {
        printf("Enter Input in index[%i]: ",i);
        scanf("%i",&arr[i]);
    }
    int Min_Temp=0;
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(arr[i]<arr[j])
            {
                //int temp = arr[i];
                //arr[i]=arr[j];
                //arr[j]=temp;

                arr[i]+=arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]-=arr[j];
            }

        }
    }
    for(int i=0;i<10;i++)
    {
        printf("Arr[%i]= %i\n",i,arr[i]);
    }
    return 0;
}
