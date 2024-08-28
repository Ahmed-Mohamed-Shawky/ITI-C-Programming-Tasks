#include "Line_Editor.h"

char Def_Col,Def_Row;

char* Line_Editor(int line_size,char def_Col,char def_Row,char ASCII_Start,char ASCII_End)
{
    Def_Col = def_Col;
    Def_Row = def_Row;
    //int line_size=30;
    char *line = malloc((line_size+1)*sizeof(char));
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
                //textattr(WHITE,BLACK);
                //system("cls");
                //textattr(YELLOW,BLACK);
                //gotoxy(Def_Col+10,Def_Row-10);
                //puts(line);
                //Flag=100;
                textattr(WHITE,BLACK);
                return line;
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
                if((LC-Def_Col)<line_size)
                {
                    if((CH>=ASCII_Start&&CH<=ASCII_End)||(CH==32))
                    {
                        //*PC=CH;
                        //if(CC<LC){CC++;PC++;}
                        //else{CC++;PC++;LC++;PL++;}
                        *PL=0;
                        LC++;PL++;
                        *PL='\0';
                        Add_Ch(PC);
                        *PC=CH;
                        CC++;PC++;
                        print_line(line,line_size);
                    }
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
void Add_Ch(char *_ch)
{
    while(*(_ch+1)!='\0')
    {
        *(_ch+1)=*_ch;
        _ch++;
    }
    *(_ch+1)=*_ch;
}
