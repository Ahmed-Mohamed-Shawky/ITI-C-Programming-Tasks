#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char firstName[10],lastName[10],fullName[21];
    printf("Enter ur First_Name: ");
    gets(firstName);
    printf("Enter ur Last_Name: ");
    gets(lastName);
    strcpy(fullName,firstName);
    strcat(fullName," ");
    strcat(fullName,lastName);
    printf("Hello Mr.");
    puts(fullName);
    return 0;
}
