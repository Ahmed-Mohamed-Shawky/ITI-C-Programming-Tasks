#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <conio.h>

#define Def_Col 40
#define Def_Row 15
#define Line_Def_Sympol "-"

enum Extended_Keys
{
    Pg_Up = 73,     //lines
    Pg_Dn = 81,     //lines
    End = 79,       //ch
    Del = 83,       //ch
    Home = 71,      //ch
    R_Arrow = 77,   //ch
    L_Arrow = 75,   //ch
    Up_Arrow = 72,  //lines
    Dn_Arrow = 80,  //lines
    Extended = -32
};

enum Normal_Keys
{
    Esc = 27,
    Enter = 13,
    B_Space = 8,    //ch
    Tab = 9,        //lines

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

struct Line
{
    char *line;
    char *PF,*PC,*PL;
    char FC,CC,LC;
};

void Delete_Ch(char *_ch);
void gotoxy( int column, int line );
void textattr(int ForgC, int BackC);
void LineCpy(struct Line *L1,struct Line *L2);
void print_line(struct Line *line_2_print,char _line_Size);
void creat_line(struct Line *Line_2_creat,char _line_Size);
void Delete_Line(struct Line *_Line,char Line_index,char Last_Line_index);

#define ASCII_Start Lower_Start
#define ASCII_End   Lower_End

#define line_size 30
#define lines_Number 5

int main()
{
    //char **Multi_Lines = malloc(lines_Number*sizeof(char*));

    struct Line *Lines = malloc(lines_Number*sizeof(struct Line));
    /*for (int i=0;i<lines_Number;i++)
    {
        creat_line(&Lines[i],line_size);
        //Lines[i].line = malloc(line_size*sizeof(char));
        //strcpy(Lines[i].line,""); // or Lines[i].line[0]='\0';
        //Lines[i].PF=Lines[i].PC=Lines[i].PL=Lines[i].line;
        //Lines[i].FC=Lines[i].CC=Lines[i].LC=Def_Col;
        gotoxy(Def_Col,Def_Row+i);
        print_line(Lines,line_size);
    }*/
    /*gotoxy(Def_Col,Def_Row);
    print_line(Lines,line_size);*/

    creat_line(Lines,line_size); //creat first line
    gotoxy(Def_Col,Def_Row);
    print_line(Lines,line_size); //print first line*/

    struct Line *PFL,*PCL,*PLL;
    PFL=PCL=PLL=Lines;
    char FL,CL,LL;
    FL=CL=LL=Def_Row;
    //LL = Def_Row+4;
    /*char *PF,*PC,*PL;
    PF=PC=PL=Multi_Lines[0][0];
    char FC,CC,LC;
    FC=CC=LC=Def_Col;*/

    char Flag=0;
    do
    {
        gotoxy(PCL->CC,CL);
        char CH=getch();
        switch(CH)
        {
            case Extended:
                CH=getch();
                switch(CH)
                {
                    case Pg_Up:
                        // Go to First line
                        CL=FL;
                        PCL=PFL;
                        PCL->CC=PCL->FC;
                        break;
                    case Pg_Dn:
                        CL=LL;
                        PCL=PLL;
                        PCL->CC=PCL->LC;
                        break;
                    case Up_Arrow:
                        if(CL>FL){CL--;PCL--;}
                        break;
                    case Dn_Arrow:
                        if(CL<LL){CL++;PCL++;}
                        break;
                    case Home:
                        // go to the line start point
                        PCL->CC=PCL->FC;
                        break;
                    case End:
                        // go to the line end point
                        PCL->CC=PCL->LC;
                        break;
                    case R_Arrow:
                        //Shift Cursor to right
                        if(PCL->CC<PCL->LC){PCL->CC++;PCL->PC++;}
                        break;
                    case L_Arrow:
                        //Shift Cursor to left
                        if(PCL->CC>PCL->FC){PCL->CC--;PCL->PC--;}
                        break;
                    case Del:
                        //delete current char
                        if(PCL->CC==PCL->LC)
                            break;
                        Delete_Ch(PCL->PC);
                        gotoxy(Def_Col,CL);
                        print_line(PCL,line_size);
                        PCL->LC--;PCL->PL--;
                        break;
                }
                break;
            case Tab:
                if(CL<LL){CL++;PCL++;}
                else if(CL<Def_Row+lines_Number-1)
                {
                    CL++;PCL++;LL++;PLL++;
                    creat_line(PCL,line_size);
                    gotoxy(Def_Col,CL);
                    print_line(PCL,line_size);
                }
                break;
            case Esc:
                Flag=100;
                break;
            case Enter:
                textattr(WHITE,BLACK);
                system("cls");
                //gotoxy(Def_Col+10,Def_Row-10);
                for(int i=0;i<=LL-Def_Row;i++)
                {
                    textattr(WHITE,BLACK);
                    gotoxy(Def_Col+10,Def_Row-10+i);
                    printf("Line %i: ",i+1);
                    textattr(YELLOW,BLACK);
                    puts(Lines[i].line);
                }
                Flag=100;
                break;
            case B_Space:
                //remove currnt char // remove curent line if the char 0 not found
                /*if(PCL->CC<=PCL->LC && PCL->CC>=PCL->FC)
                {
                    if(*PCL->PC=='\0')
                    {
                        //delete line
                        Delete_Line(PCL,CL-Def_Row,LL-Def_Row);
                        CL--;PCL--;
                        LL--;PLL--;
                        textattr(WHITE,BLACK);
                        system("cls");
                        for (int i=0;i<=LL-Def_Row;i++)
                        {
                            gotoxy(Def_Col,Def_Row+i);
                            print_line(&Lines[i],line_size);
                        }
                    }
                    else
                    {
                        Delete_Ch(PCL->PC);
                        gotoxy(Def_Col,CL);
                        print_line(PCL,line_size);
                        PCL->CC--;PCL->PC--;
                        PCL->LC--;PCL->PL--;
                    }
                }*/
                if(PCL->CC>=PCL->FC)
                {
                    if(*PCL->PC=='\0' && PCL->CC==PCL->FC)
                    {
                        //delete line
                        Delete_Line(PCL,CL-Def_Row,LL-Def_Row);
                        CL--;PCL--;
                        LL--;PLL--;
                        textattr(WHITE,BLACK);
                        system("cls");
                        for (int i=0;i<=LL-Def_Row;i++)
                        {
                            gotoxy(Def_Col,Def_Row+i);
                            print_line(&Lines[i],line_size);
                        }
                        //break;
                    }
                    else
                    {
                        Delete_Ch(PCL->PC);
                        gotoxy(Def_Col,CL);
                        print_line(PCL,line_size);
                        if(PCL->CC!=PCL->FC){PCL->CC--;PCL->PC--;}
                        PCL->LC--;PCL->PL--;
                    }
                }

                break;
            default:
                if((CH>=ASCII_Start&&CH<=ASCII_End)||(CH==32))
                {
                    *PCL->PC=CH;
                    if(PCL->CC<PCL->LC){PCL->CC++;PCL->PC++;}
                    else{PCL->CC++;PCL->PC++;PCL->LC++;PCL->PL++;}
                    *PCL->PL='\0';
                    gotoxy(Def_Col,CL);
                    print_line(PCL,line_size);
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

void print_line(struct Line *line_2_print,char _line_Size)
{
    //gotoxy(Def_Col,Def_Row);
    textattr(LIGHTGRAY,BLUE);
    int _i;
    for(_i=0;_i<_line_Size&line_2_print->line[_i]!='\0';_i++)
    {
        printf("%c",line_2_print->line[_i]);
    }
    textattr(LIGHTGRAY,LIGHTBLUE);
    for(_i;_i<_line_Size;_i++)
        printf(Line_Def_Sympol);
}

void creat_line(struct Line *Line_2_creat,char _line_Size)
{
    Line_2_creat->line = malloc(line_size*sizeof(char));
    strcpy(Line_2_creat->line,""); // or Lines[i].line[0]='\0';
    Line_2_creat->PF=Line_2_creat->PC=Line_2_creat->PL=Line_2_creat->line;
    Line_2_creat->FC=Line_2_creat->CC=Line_2_creat->LC=Def_Col;
}

void Delete_Ch(char *_ch)
{
    while(*_ch!='\0')
    {
        *_ch=*(_ch+1);
        _ch++;
    }
}

void LineCpy(struct Line *L1,struct Line *L2)
{
    strcpy(L1->line,L2->line);
    L1->CC=L2->CC;
    L1->FC=L2->FC;
    L1->LC=L2->LC;
    L1->PC=L2->PC;
    L1->PF=L2->PF;
    L1->PL=L2->PL;
}

void Delete_Line(struct Line *_Line,char Line_index,char Last_Line_index)
{
    for (int i=Line_index;i<Last_Line_index;i++)
    {
        LineCpy(_Line,_Line+1);
        _Line++;
    }
}
