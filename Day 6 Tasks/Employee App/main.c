#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Line_Editor.h"

//#define Color_Num 9  //9
//#define Employee_size 10
#define Main_Menu_size 8

//Normal ASCII
#define Enter 13
#define esc 27
//Extended ASCII
#define Extended -32
#define Up 72
#define Down 80
#define Home 71
#define End 79
#define Pg_Up 73
#define Pg_Dn 81


struct Employee
{
    char name[20];
    int id;
    int age;
    int salary;
    int commission;
    int deduction;
};

//void gotoxy( int column, int line);
//void textattr(int i);
void textattr(int ForgC, int BackC);
void Print_Employee_Screen();
void Enter_Employee(struct Employee *P);
void delete_Employee(struct Employee *p);
void Enter_Employee_V2(struct Employee *P);
void Employee_Screen(struct Employee *p,int emp_i);
void auto_fill_Employee(struct Employee *emp,int x);
void print_Employee_at_xy(struct Employee *p,int col,int row);

int main()
{
    char Main_Menu[Main_Menu_size][15] = {"New","DisplayAll","DisplayById","DisplayByName","DeleteAll","DeleteById","DeleteByName","Exit"};

    gotoxy(20,15);
    printf("Enter The Number Of Employees: ");
    int Employee_size = atoi(Line_Editor(4,50,15,Num_Start,Num_End));
    struct Employee *employees = malloc(Employee_size*sizeof(struct Employee));
    for(int i=0;i<Employee_size;i++)
        delete_Employee(&employees[i]);
    //*employees = 0;
    int cursor=0;
    char q_flag=10;
    char pressed_Button;
    do
    {
        system("cls");
        for(int i=0;i<8;i++)
        {
            if(cursor==i)
                textattr(BLACK,LIGHTCYAN);
            else
                textattr(WHITE,BLACK);
            gotoxy(15,15+i);
            puts(Main_Menu[i]);
            printf("\n");
        }
        textattr(WHITE,BLACK);
        pressed_Button=getch();
        switch(pressed_Button)
        {
            case Extended:
                pressed_Button=getch();
                switch(pressed_Button)
                {
                    case Up:
                        cursor--;
                        if(cursor<0)
                            cursor=Main_Menu_size-1;
                        break;
                    case Down:
                        cursor++;
                        if(cursor>Main_Menu_size-1)
                            cursor=0;
                        break;
                    case Home:
                    case Pg_Up:
                        cursor=0;
                        break;
                    case End:
                    case Pg_Dn:
                        cursor=Main_Menu_size-1;
                        break;
                }
                _flushall();
                break;
            case Enter:
                system("cls");
                _flushall();
                switch(cursor)
                {
                    case 0: //New menu
                        system("cls");
                        int emp_num;
                        do
                        {
                            system("cls");
                            gotoxy(15,15);
                            printf("Enter The Employee Number(1~%i): ",Employee_size);
                            emp_num = atoi(Line_Editor(5,48,15,Num_Start,Num_End));
                            //scanf("%i",&emp_num);
                            _flushall();
                        }while((emp_num<1)||(emp_num>Employee_size));
                        if(employees[emp_num-1].id!=0)
                        {
                            system("cls");
                            gotoxy(40,10);
                            printf("------------------------------------------");
                            gotoxy(40,11);
                            printf("| ");
                            textattr(LIGHTRED,BLACK);
                            printf("Failed To Save The Employee At place %i",emp_num);
                            textattr(WHITE,BLACK);
                            printf(" |");
                            gotoxy(40,12);
                            printf("| ");
                            textattr(LIGHTRED,BLACK);
                            printf("+++ The Saving Place is not Empty +++ ");
                            textattr(WHITE,BLACK);
                            printf(" |");
                            gotoxy(40,13);
                            printf("------------------------------------------");
                            break;
                        }
                        Employee_Screen(&employees[emp_num-1],emp_num);
                        system("cls");
                        gotoxy(40,10);
                        printf("---------------------------------");
                        gotoxy(40,11);
                        printf("| ");
                        textattr(YELLOW,BLACK);
                        printf("Employee_%i Saved Successfully",emp_num);
                        textattr(WHITE,BLACK);
                        printf(" |");
                        gotoxy(40,12);
                        printf("---------------------------------");
                        break;
                    case 1: //DisplayAllMenu
                        //printf("Display All Screen");
                        system("cls");
                        char Col=5,Row=5;
                        int flag=0;
                        for(int i=0;i<Employee_size;i++)
                        {
                            if(employees[i].id!=0)
                            {
                                for(int z=0;z<10;z++)
                                {
                                    gotoxy(Col+33,Row+z-4);
                                    printf("|");
                                }
                                gotoxy(Col+10,Row-3); //Title line
                                printf("Employee_%i",i+1);
                                print_Employee_at_xy(&employees[i],Col,Row);

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
                                flag=1;
                            }
                        }
                        if(!flag)
                        {
                            system("cls");
                            gotoxy(40,10);
                            printf("-----------------------------------------------------");
                            gotoxy(40,11);
                            printf("| ");
                            textattr(LIGHTRED,BLACK);
                            printf("Failed To Display Employees...No Employee Found!!",emp_num);
                            textattr(WHITE,BLACK);
                            printf(" |");
                            gotoxy(40,12);
                            printf("-----------------------------------------------------");
                        }
                        break;
                    case 2: //DisplayByIdMenu
                        //printf("Display By ID Screen");
                        system("cls");
                        int Temp_Id,_index;
                        flag=0;
                        gotoxy(15,15);
                        printf("Enter The Employee Id: ");
                        Temp_Id = atoi(Line_Editor(5,38,15,Num_Start,Num_End));
                        //scanf("%i",&Temp_Id);
                        _flushall();
                        for(_index=0;_index<Employee_size;_index++)
                        {
                            if(employees[_index].id==Temp_Id)
                                break;
                            if(_index==Employee_size-1)
                               flag=1;
                        }
                        if(flag)
                        {
                            system("cls");
                            gotoxy(40,10);
                            printf("------------------------");
                            gotoxy(40,11);
                            printf("| ");
                            textattr(LIGHTRED,BLACK);
                            printf("Faild To Find ID (%i)",Temp_Id);
                            textattr(WHITE,BLACK);
                            printf(" |");
                            gotoxy(40,12);
                            printf("------------------------");
                            break;
                        }
                        print_Employee_at_xy(&employees[_index],40,5);
                        break;
                    case 3: //DisplayByNameMenu
                        //printf("Display By Name Screen");
                        system("cls");
                        char Temp_Name[15];
                        _index=0;flag=0;
                        gotoxy(15,15);
                        printf("Enter The Employee Name: ");
                        strcpy(Temp_Name,(Line_Editor(20,40,15,Lower_Start,Lower_End)));
                        //gets(&Temp_Name);
                        _flushall();
                        for(_index=0;_index<Employee_size;_index++)
                        {
                            if(!strcmpi(employees[_index].name,Temp_Name))
                                break;
                            if(_index==Employee_size-1)
                               flag=1;
                        }
                        if(flag)
                        {
                            system("cls");
                            gotoxy(40,10);
                            printf("  -----------------------------------");
                            gotoxy(40,11);
                            printf("| ");
                            textattr(LIGHTRED,BLACK);
                            printf("Faild To Find Employee Name (%s)",Temp_Name);
                            textattr(WHITE,BLACK);
                            printf(" |");
                            gotoxy(40,12);
                            printf("  -----------------------------------");
                            break;
                        }
                        print_Employee_at_xy(&employees[_index],40,5);
                        break;
                    case 4: //DeleteAllMenu
                        //printf("Delete All Screen");
                        flag=0;
                        for(int i=0;i<Employee_size;i++)
                        {
                            if(employees[i].id!=0)
                            {
                                delete_Employee(&employees[i]);
                                flag=1;
                            }
                        }
                        system("cls");
                        gotoxy(40,10);
                        printf("-----------------------------------------------");
                        gotoxy(40,11);
                        printf("| ");
                        if(flag)
                        {
                            textattr(YELLOW,BLACK);
                            printf("All Employees Has Been Deleted Successfully",Temp_Name);
                        }
                        else
                        {
                            textattr(LIGHTRED,BLACK);
                            printf("Delete Failed...No Employee Found To Delete",Temp_Name);
                        }
                        textattr(WHITE,BLACK);
                        printf(" |");
                        gotoxy(40,12);
                        printf("-----------------------------------------------");
                        break;
                    case 5: //DeleteByIdMenu
                        //printf("Delete By Id Screen");
                        system("cls");
                        flag=0;Temp_Id=0;
                        gotoxy(15,15);
                        printf("Enter The Employee Id: ");
                        Temp_Id = atoi(Line_Editor(5,38,15,Num_Start,Num_End));
                        //scanf("%i",&Temp_Id);
                        _flushall();
                        for(_index=0;_index<Employee_size;_index++)
                        {
                            if(employees[_index].id==Temp_Id)
                                break;
                            if(_index==Employee_size-1)
                               flag=1;
                        }
                        system("cls");
                        gotoxy(40,10);
                        printf("----------------------------------");
                        gotoxy(40,11);
                        printf("| ");
                        if(flag)
                        {
                            textattr(LIGHTRED,BLACK);
                            printf("Failed To Find Employee ID (%i)",Temp_Id);
                        }
                        else
                        {
                            textattr(YELLOW,BLACK);
                            printf("Employee Is Deleted Successfully");
                        }
                        textattr(WHITE,BLACK);
                        printf(" |");
                        gotoxy(40,12);
                        printf("----------------------------------");
                        if(!flag)delete_Employee(&employees[_index]);
                        break;
                    case 6: //DeleteByNameMenu
                        //printf("Delete By Name Screen");
                        system("cls");
                        flag=0;Temp_Name;
                        gotoxy(15,15);
                        printf("Enter The Employee Name: ");
                        strcpy(Temp_Name,(Line_Editor(20,40,15,Lower_Start,Lower_End)));
                        //gets(Temp_Name);
                        _flushall();
                        for(_index=0;_index<Employee_size;_index++)
                        {
                            if(!strcmpi(employees[_index].name,Temp_Name))
                                break;
                            if(_index==Employee_size-1)
                                flag=1;
                        }
                        system("cls");
                        gotoxy(40,10);
                        printf("----------------------------------");
                        gotoxy(40,11);
                        printf("| ");
                        if(flag)
                        {
                            textattr(LIGHTRED,BLACK);
                            printf("Failed To Find Employee Name (%s)",Temp_Name);
                        }
                        else
                        {
                            textattr(YELLOW,BLACK);
                            printf("Employee Is Deleted Successfully");
                        }
                        textattr(WHITE,BLACK);
                        printf(" |");
                        gotoxy(40,12);
                        printf("----------------------------------");
                        if(!flag)delete_Employee(&employees[_index]);
                        break;
                    case 7: //Exit
                        q_flag = 100;
                        break;
                }
                //printf("Enter any key to continue: ");
                getch();
                break;
            case esc:
                q_flag=100;
                break;
        }

    }while(q_flag!=100);

    return 0;
}



/*void gotoxy( int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}*/

/*void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}*/

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

void Employee_Screen(struct Employee *p,int emp_i)
{
    system("cls");
    gotoxy(35,2);
    printf("Employee_%i",emp_i);
    Print_Employee_Screen();
    //Enter_Employee(p);
    Enter_Employee_V2(p);
    //auto_fill_Employee(p,emp_i);
    gotoxy(30,20);
    printf("Press Enter to continue...");
    getch();
    _flushall();
}

void delete_Employee(struct Employee *p)
{
    p->age=0;
    p->commission=0;
    p->deduction=0;
    p->id=0;
    strcpy(p->name,"");
    p->salary=0;
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

void Enter_Employee_V2(struct Employee *P)
{
    //Line 1
    P->id = atoi(Line_Editor(5,14,5,Num_Start,Num_End));
    strcpy(P->name,(Line_Editor(20,66,5,Lower_Start,Lower_End)));
    //Line 2
    P->age = atoi(Line_Editor(2,15,10,Num_Start,Num_End));
    P->salary = atoi(Line_Editor(5,68,10,Num_Start,Num_End));
    //Line 3
    P->commission = atoi(Line_Editor(5,22,15,Num_Start,Num_End));
    P->deduction = atoi(Line_Editor(5,71,15,Num_Start,Num_End));

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
