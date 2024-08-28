#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------------Calculator App------------------------\n");
    char exit_ch='n',first_run=0;
    do
    {
        if(first_run!=0)
            printf("\n\t\t*-*-*-*-*-*-*-* Do u like it :D *-*-*-*-*-*-*-*-*\n\n");
        else
            printf("\n");
        float Num_1=5.2,Num_2=3.7;
        char op;
        printf("Enter your equation with this form 'X+Y': ");
        scanf("%f%c%f",&Num_1,&op,&Num_2);
        _flushall();
        //scanf(" %c",&op);
        //printf("%.2f %c %.2f\n",Num_1,op,Num_2);
        double result=5;
        switch(op)
        {
            case'+':
                result = Num_1+Num_2;
                break;
            case'-':
                result = Num_1-Num_2;
                break;
            case'*':
                result = Num_1*Num_2;
                break;
            case'/':
                if(Num_2==0)
                    {printf("Can't Divide by Zero"); break;}
                result = (Num_1)/(Num_2);
                break;
        }
        if(Num_2!=0)
            printf("%.2f %c %.2f = %.3lf\n",Num_1,op,Num_2,result);
        printf("\nDo u want to Exit?? Y/N ? ");
        scanf("%c",&exit_ch);
        _flushall();
        first_run=1;
    }while( exit_ch!='Y' && exit_ch!='y');
    return 0;
}
