#include <stdio.h>
#include <stdlib.h>
//#define int_to_bin(x) (while(x!=0)

long int int_to_bin(int x)
{
    long int result = 0;
    while(x!=0)
    {
        result = result*10 + (x%2);
        x/=2;
    }
    return result;
}

long int int_to_bin_v2(int x)
{
    if(x!=0)
        return(int_to_bin_v2(x/2)*10+(x%2));
    //return ()
}

int main()
{
    printf("Hello world!\n");
    printf("------------------------------\n");
    int num;
    printf("Enter any Number u want: ");
    scanf("%i",&num);
    //scanf("\n");
    printf("The Number u Entered is: %i \t dec \n\t\t\t %x \t Hexa \n\t\t\t %o \t oct \n\t\t\t %ld \t binary\n",num,num,num,int_to_bin_v2(num));
    printf("------------------------------\n");
    char ch;
    printf("Enter any character u want: ");
    scanf(" %c",&ch);
    printf("The character u Entered is: %c and it's ASCII is: %i\n",ch,ch);
    printf("------------------------------\n");
    printf("The int variable 'num' address in memory is: %i\n",&num);
    printf("The char variable 'ch' address in memory is: %i\n",&ch);

    return 0;
}
