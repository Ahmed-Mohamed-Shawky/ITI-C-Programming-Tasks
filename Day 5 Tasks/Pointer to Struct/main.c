#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    int age;
    int salary;
    char name[15];
};

int main()
{
    struct Employee Employee_1;
    struct Employee *Emp_ptr = &Employee_1;

    Emp_ptr->age = 25;
    Emp_ptr->id = 123;
    Emp_ptr->salary = 5600;
    strcpy(Emp_ptr->name,"Ahmed Shawky");

    printf("Name %s\n",Emp_ptr->name);
    printf("Id %i\n",Emp_ptr->id);
    printf("age %i\n",Emp_ptr->age);
    printf("Salary %i\n",Emp_ptr->salary);

    //printf("Hello world!\n");
    return 0;
}
