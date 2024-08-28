#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Def_Col 40
#define Def_Row 15
#define Line_Def_Sympol "-"

enum Extended_Keys
{
    End = 79,
    Del = 83,
    Home = 71,
    R_Arrow = 77,
    L_Arrow = 75,
    Extended = -32
};

enum Normal_Keys
{
    Esc = 27,
    Enter = 13,
    B_Space = 8,

    Num_start = 48, //Zero '0' ASCII
    Num_End = 57, // nine '9' ASCII
    Upper_Start = 65,   // 'A' ASCII
    Upper_End = 90,     // 'Z' ASCII
    Lower_Start = 97,   // 'a' ASCII
    Lower_End = 122,     // 'z' ASCII
};

enum Text_Color
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENT,
    YELLOW,
    WHITE,
};

void Delete_Ch(char *_ch);
void print_Str(char *Str_2_print);
void textattr(int ForgC, int BackC);
void gotoxy( int column, int line );

#define ASCII_Start Lower_Start
#define ASCII_End   Lower_End

int main()
{
    int line_size=30;
    char *line = malloc(line_size*sizeof(char));
    strcpy(line,"");
    gotoxy(Def_Col,Def_Row);
    textattr(LIGHTGRAY,LIGHTBLUE);
    for(int i=0;i<line_size;i++)
        printf(Line_Def_Sympol);
    char *PF,*PC,*PL;
    PF=PC=PL=line;
    char FC,CC,LC;
    FC=CC=LC=Def_Col;
    char Flag=0;
    do
    {
        gotoxy(CC,Def_Row);
        char CH=getch();
        switch(CH)
        {
            case Extended:
                CH=getch();
                switch(CH)
                {
                    case Home:
                        // go to the line start point
                        CC=FC;
                        PC=PF;
                        break;
                    case End:
                        // go to the line end point
                        CC=LC;
                        PC=PL;
                        break;
                    case R_Arrow:
                        //Shift Cursor to right
                        if(CC<LC){CC++;PC++;}
                        break;
                    case L_Arrow:
                        //Shift Cursor to left
                        if(CC>FC){CC--;PC--;}
                        break;
                    case Del:
                        //delete current char
                        if(CC==LC)
                            break;
                        Delete_Ch(PC);
                        print_line(line,line_size);
                        LC--;PL--;
                        break;
                }
                break;
            case Esc:
                Flag=100;
                break;
            case Enter:
                textattr(WHITE,BLACK);
                system("cls");
                textattr(YELLOW,BLACK);
                gotoxy(Def_Col+10,Def_Row-10);
                puts(line);
                Flag=100;
                break;
            case B_Space:
                if(CC<=LC && CC>=FC)
                {
                    if(CC!=FC)
                        {CC--;PC--;}
                    if(*PC=='\0')
                        break;
                    Delete_Ch(PC);
                    print_line(line,line_size);
                    LC--;PL--;
                    break;
                }
            default:
                if((CH>=ASCII_Start&&CH<=ASCII_End)||(CH==32))
                {
                    *PC=CH;
                    if(CC<LC){CC++;PC++;}
                    else{CC++;PC++;LC++;PL++;}
                    *PL='\0';
                    print_line(line,line_size);
                }
        }
    }while(Flag!=100);
    textattr(WHITE,BLACK);
    return 0;
}

void textattr(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void print_line(char *line_2_print,char _line_Size)
{
    gotoxy(Def_Col,Def_Row);
    textattr(LIGHTGRAY,BLUE);
    int _i;
    for(_i=0;_i<_line_Size&line_2_print[_i]!='\0';_i++)
    {
        printf("%c",line_2_print[_i]);
    }
    textattr(LIGHTGRAY,LIGHTBLUE);
    for(_i;_i<_line_Size;_i++)
        printf(Line_Def_Sympol);
}

void Delete_Ch(char *_ch)
{
    while(*_ch!='\0')
    {
        *_ch=*(_ch+1);
        _ch++;
    }
}
