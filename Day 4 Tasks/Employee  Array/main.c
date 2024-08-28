#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Employee_size 6

struct Employee
{
    char name[15];
    int id;
    int age;
    int salary;
    int commission;
    int deduction;
};

void gotoxy( int column, int line);
void textattr(int i);
void Print_Employee_Screen();
void Enter_Employee(struct Employee *P);
void auto_fill_Employee(struct Employee *emp,int x);
void print_Employee_at_xy(struct Employee *p,int col,int row);




int main()
{
    struct Employee emp_arr[Employee_size]={0};
    for(int i=0;i<Employee_size;i++)
    {
        system("cls");
        gotoxy(35,2);
        printf("Employee_%i",i+1);
        Print_Employee_Screen();
        //Enter_Employee(&emp_arr[i]);
        auto_fill_Employee(&emp_arr[i],i+1);
        gotoxy(30,20);
        printf("Press Enter to continue...");
        getch();
        _flushall();
    }

    system("cls");
    char Col=5,Row=5;
    for(int i=0;i<Employee_size;i++)
    {
        for(int z=0;z<10;z++)
        {
            gotoxy(Col+33,Row+z-4);
            printf("|");
        }

        gotoxy(Col+10,Row-3); //Title line
        printf("Employee_%i",i+1);

        print_Employee_at_xy(&emp_arr[i],Col,Row);

        Col+=35;
        if(Col>100)
        {
            Col=5;
            Row+=15;
            gotoxy(Col,Row-7);
            printf("--------------------------------------------------");
            printf("--------------------------------------------------");
            gotoxy(Col,Row);
        }
        /*gotoxy(30,20);
        printf("Press Enter to continue...");
        getch();
        _flushall();*/
        //printf("--------------------------");
    }

    return 0;
}


void gotoxy( int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void Print_Employee_Screen()
{
    //Line 1
    gotoxy(10,5);
    printf("ID: ");
    gotoxy(60,5);
    printf("Name: ");
    //Line 2
    gotoxy(10,10);
    printf("Age: ");
    gotoxy(60,10);
    printf("Salary: ");
    //line 3
    gotoxy(10,15);
    printf("Commission: ");
    gotoxy(60,15);
    printf("Deduction: ");
}

void Enter_Employee(struct Employee *P)
{
    //Line 1
    gotoxy(14,5);
    scanf("%i",&P->id);
    _flushall();
    gotoxy(66,5);
    gets(P->name);
    _flushall();
    //Line 2
    gotoxy(15,10);
    scanf("%i",&P->age);
    _flushall();
    gotoxy(68,10);
    scanf("%i",&P->salary);
    _flushall();
    //Line 3
    gotoxy(22,15);
    scanf("%i",&P->commission);
    _flushall();
    gotoxy(71,15);
    scanf("%i",&P->deduction);
    _flushall();
}

void auto_fill_Employee(struct Employee *emp,int x)
{
    emp->id=x;
    strcpy(emp->name,"Employee_");
    char itoa[10];
    sprintf(itoa, "%i",x);
    strcat(emp->name,itoa);
    emp->salary=1000*x;
    emp->age=x;
    emp->commission=100*x;
    emp->deduction=50*x;
}

void print_Employee_at_xy(struct Employee *p,int col,int row)
{
    //line 1
    gotoxy(col,row);
    printf("ID: %i",p->id);
    gotoxy(col+15,row);
    printf("Name: %s",p->name);
    //line 2
    gotoxy(col,row+5);
    printf("Salary: %i",p->salary);
    gotoxy(col+15,row+5);
    printf("Net_Salary: %i",p->salary+p->commission-p->deduction);
}


