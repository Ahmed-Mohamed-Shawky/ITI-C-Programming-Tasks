#include <stdio.h>
#include <stdlib.h>

float Sum(float x,float y)
{
    return(x+y);
}
float Sub(float x,float y)
{
    return(x-y);
}
float Mul(float x,float y)
{
    return(x*y);
}
float Div(float x,float y)
{
    return(x/y);
}

int main()
{
    float Num_1,Num_2,result;
    char ch;
    printf("Enter the equation with this Ex-Form (x*y): ");
    scanf("%f%c%f",&Num_1,&ch,&Num_2);
    switch(ch)
    {
    case '+':
        result=Sum(Num_1,Num_2);
        break;
    case '-':
        result=Sub(Num_1,Num_2);
        break;
    case '*':
        result=Mul(Num_1,Num_2);
        break;
    case '/':
        result=Div(Num_1,Num_2);
        break;
    }
    printf("Result of (%.2f%c%.2f) = %.3f",Num_1,ch,Num_2,result);
    return 0;
}
