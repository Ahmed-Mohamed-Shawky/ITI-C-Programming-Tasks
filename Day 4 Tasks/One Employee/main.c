#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int line )
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

struct Employee
{
    char name[15];
    int id;
    int age;
    int salary;
    int commission;
    int deduction;
};

int main()
{
    struct Employee emp_1;

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

    //Line 1
    gotoxy(14,5);
    scanf("%i",&emp_1.id);
    _flushall();
    gotoxy(66,5);
    gets(emp_1.name);
    _flushall();
    //Line 2
    gotoxy(15,10);
    scanf("%i",&emp_1.age);
    _flushall();
    gotoxy(68,10);
    scanf("%i",&emp_1.salary);
    _flushall();
    //Line 3
    gotoxy(22,15);
    scanf("%i",&emp_1.commission);
    _flushall();
    gotoxy(71,15);
    scanf("%i",&emp_1.deduction);
    _flushall();

    gotoxy(30,20);
    printf("Press Enter to continue...");
    getch();

    system("cls");

    printf("Name: ");
    puts(emp_1.name);
    int netsalary = emp_1.salary+emp_1.commission-emp_1.deduction;
    printf("Salary: %i\n",netsalary);

    return 0;
}
