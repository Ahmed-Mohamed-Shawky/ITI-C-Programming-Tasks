#ifndef LINE_EDITOR_H_INCLUDED
#define LINE_EDITOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <conio.h>

//#define Def_Col 40
//#define Def_Row 15
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

    Num_Start = 48, //Zero '0' ASCII
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

#define Line_Text_Color
#define Line_Back_Color

//#define ASCII_Start Lower_Start
//#define ASCII_End   Lower_End

void Add_Ch (char *_ch);
void Delete_Ch(char *_ch);
void print_Str(char *Str_2_print);
void textattr(int ForgC, int BackC);
void gotoxy( int column, int line );
void print_line(char *line_2_print,char _line_Size);
char* Line_Editor(int line_size,char Def_Col,char Def_Row,char ASCII_Start,char ASCII_End);

#endif // LINE_EDITOR_H_INCLUDED
