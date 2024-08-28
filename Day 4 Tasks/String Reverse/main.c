#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str_array[50];
    printf("Enter Any text u want: ");
    //gets(str_array);
    int len=0;
    char ch;
    while((ch=getche()) != 13)
    {
        str_array[len++]=ch;
    }

    printf("\nYour revers Text is: ");
    //int len = strlen(str_array);
    /*for(int i=1;i<=len;i++)
    {
        printf("%c",str_array[len-i]);
    }*/
    while(len!=-1)
    {
        printf("%c",str_array[len--]);
    }
    printf("\n\n----Heheee... Now try to read it :>----\n");

    return 0;
}
