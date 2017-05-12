//
// Created by Peterson Xu on 27/04/2017.
//
#include "mathFormula.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//产生式
std::string r[] = { /*  R1  */  "S -> $B$",
        /*  R2  */  "B -> BB",
        /*  R3  */  "B -> B_^{B}{B}",
        /*  R4  */  "B -> B^{B}",
        /*  R5  */  "B -> B_{B}",
        /*  R6  */  "B -> \\int{B}{B}{B}",
        /*  R7  */  "B -> \\sum{B}{B}{B}",
        /*  R8  */  "B -> id",
        /*  R9  */  "B -> num",
        /*  R10 */  "B -> \\blank",
        /*  R11 */  "B -> (B)"
};

int rlen[] = {3, 2, 9, 5, 5, 10, 10, 1, 1, 1, 3};

//action函数，s数组记录状态，a数组记录状态


int st[48][13] = {

        /*      id   num     _     ^   INT   SUM  BLANK     {     }     (     )     $     #     */
        {     0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    1,    0},             //I0
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I1
        {     0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,  ACC},             //I2
        {     9,    9,    9,    9,    9,    9,     9,    9,    9,    9,    9,    9,    9},             //I3
        {     8,    8,    8,    8,    8,    8,     8,    8,    8,    8,    8,    8,    8},             //I4
        {     0,    0,    0,    0,    0,    0,     0,   11,    0,    0,    0,    0,    0},             //I5
        {     0,    0,    0,    0,    0,    0,     0,   12,    0,    0,    0,    0,    0},             //I6
        {    10,   10,   10,   10,   10,   10,    10,   10,   10,   10,   10,   10,   10},             //I7
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I8
        {     4,    3,   15,   16,    5,    6,     7,    0,    0,    8,    0,   14,    0},             //I9
        {     0,    0,    0,    0,    0,    0,     0,    0,    0,    0,    0,    0,    0},             //I10
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I11
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I12
        {     4,    3,   15,   16,    5,    6,     7,    0,    0,    8,   20,    0,    0},             //I13
        {     1,    1,    1,    1,    1,    1,     1,    1,    1,    1,    1,    1,    1},             //I14
        {     0,    0,    0,   21,    0,    0,     0,   22,    0,    0,    0,    0,    0},             //I15
        {     0,    0,    0,    0,    0,    0,     0,   23,    0,    0,    0,    0,    0},             //I16
        {     2,    2,    2,    2,    2,    2,     2,    2,    2,    2,    2,    2,    2},             //I17
        {     4,    3,   15,   16,    5,    6,     7,    0,   24,    8,    0,    0,    0},             //I18
        {     4,    3,   15,   16,    5,    6,     7,    0,   25,    8,    0,    0,    0},             //I19
        {    11,   11,   11,   11,   11,   11,    11,   11,   11,   11,   11,   11,   11},             //I20
        {     0,    0,    0,    0,    0,    0,     0,   26,    0,    0,    0,    0,    0},             //I21
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I22
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I23
        {     0,    0,    0,    0,    0,    0,     0,   29,    0,    0,    0,    0,    0},             //I24
        {     0,    0,    0,    0,    0,    0,     0,   30,    0,    0,    0,    0,    0},             //I25
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I26
        {     4,    3,   15,   16,    5,    6,     7,    0,   32,    8,    0,    0,    0},             //I27
        {     4,    3,   15,   16,    5,    6,     7,    0,   33,    8,    0,    0,    0},             //I28
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I29
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I30
        {     4,    3,   15,   16,    5,    6,     7,    0,   36,    8,    0,    0,    0},             //I31
        {     5,    5,    5,    5,    5,    5,     5,    5,    5,    5,    5,    5,    5},             //I32
        {     4,    4,    4,    4,    4,    4,     4,    4,    4,    4,    4,    4,    4},             //I33
        {     4,    3,   15,   16,    5,    6,     7,    0,   37,    8,    0,    0,    0},             //I34
        {     4,    3,   15,   16,    5,    6,     7,    0,   38,    8,    0,    0,    0},             //I35
        {     0,    0,    0,    0,    0,    0,     0,   39,    0,    8,    0,    0,    0},             //I36
        {     0,    0,    0,    0,    0,    0,     0,   40,    0,    0,    0,    0,    0},             //I37
        {     0,    0,    0,    0,    0,    0,     0,   41,    0,    0,    0,    0,    0},             //I38
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I39
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I40
        {     4,    3,    0,    0,    5,    6,     7,    0,    0,    8,    0,    0,    0},             //I41
        {     4,    3,   15,   16,    5,    6,     7,    0,   45,    8,    0,    0,    0},             //I42
        {     4,    3,   15,   16,    5,    6,     7,    0,   46,    8,    0,    0,    0},             //I43
        {     4,    3,   15,   16,    5,    6,     7,    0,   47,    8,    0,    0,    0},             //I44
        {     3,    3,    3,    3,    3,    3,     3,    3,    3,    3,    3,    3,    3},             //I45
        {     6,    6,    6,    6,    6,    6,     6,    6,    6,    6,    6,    6,    6},             //I46
        {     7,    7,    7,    7,    7,    7,     7,    7,    7,    7,    7,    7,    7}              //I47

};

//e错误，s移进，r归约，a接受

char a[48][13] = {

        /*      id   num     _     ^    INT   SUM  BLANK    {     }     (     )     $     #     */
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   'e',  'e',  'e',  'e',  's',  'e'},             //I0
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I1
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   'e',  'e',  'e',  'e',  'e',  'a'},             //I2
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I3
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I4
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I5
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I6
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I7
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I8
        {   's',  's',   's',  's',  's',  's',  's',   'e',  'e',  's',  'e',  's',  'e'},             //I9
        {   'a',  'a',   'a',  'a',  'a',  'a',  'a',   'a',  'a',  'a',  'a',  'a',  'a'},             //I10
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I11
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I12
        {   's',  's',   's',  's',  's',  's',  's',   'e',  'e',  's',  's',  'e',  'e'},             //I13
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I14
        {   'e',  'e',   'e',  's',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I15
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I16
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I17
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I18
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I19
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I20
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I21
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I22
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I23
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I24
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I25
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I26
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I27
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I28
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I29
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I30
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I31
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I32
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I33
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I34
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I35
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I36
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I37
        {   'e',  'e',   'e',  'e',  'e',  'e',  'e',   's',  'e',  'e',  'e',  'e',  'e'},             //I38
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I39
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I40
        {   's',  's',   'e',  'e',  's',  's',  's',   'e',  'e',  's',  'e',  'e',  'e'},             //I41
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I42
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I43
        {   's',  's',   's',  's',  's',  's',  's',   'e',  's',  's',  'e',  'e',  'e'},             //I44
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I45
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'},             //I46
        {   'r',  'r',   'r',  'r',  'r',  'r',  'r',   'r',  'r',  'r',  'r',  'r',  'r'}              //I47
};

//标记goto函数列名
#define G_S 0
#define G_B 1

//goto函数
int gotof[48][13] = {
        /*    S     B    */
        {    2,   -1},       //I0
        {   -1,    9},       //I1
        {   -1,   -1},       //I2
        {   -1,   -1},       //I3
        {   -1,   -1},       //I4
        {   -1,   -1},       //I5
        {   -1,   -1},       //I6
        {   -1,   -1},       //I7
        {   -1,   13},       //I8
        {   -1,   17},       //I9
        {   -1,   -1},       //I10
        {   -1,   18},       //I11
        {   -1,   19},       //I12
        {   -1,   17},       //I13
        {   -1,   -1},       //I14
        {   -1,   -1},       //I15
        {   -1,   -1},       //I16
        {   -1,   17},       //I17
        {   -1,   17},       //I18
        {   -1,   17},       //I19
        {   -1,   -1},       //I20
        {   -1,   -1},       //I21
        {   -1,   27},       //I22
        {   -1,   28},       //I23
        {   -1,   -1},       //I24
        {   -1,   -1},       //I25
        {   -1,   31},       //I26
        {   -1,   17},       //I27
        {   -1,   17},       //I28
        {   -1,   34},       //I29
        {   -1,   35},       //I30
        {   -1,   17},       //I31
        {   -1,   -1},       //I32
        {   -1,   -1},       //I33
        {   -1,   17},       //I34
        {   -1,   17},       //I35
        {   -1,   -1},       //I36
        {   -1,   -1},       //I37
        {   -1,   -1},       //I38
        {   -1,   42},       //I39
        {   -1,   43},       //I40
        {   -1,   44},       //I41
        {   -1,   17},       //I42
        {   -1,   17},       //I43
        {   -1,   17},       //I44
        {   -1,   -1},       //I45
        {   -1,   -1},       //I46
        {   -1,   -1}        //I47

};

void init(Stack *stack)
{
    stack->top = 0;
}

void push(Stack *stack, int x)
{
    stack->tokens[stack->top] = x;
    stack->top++;
}

void pop(Stack *stack, int length)
{
    stack->top -= length;
}

//返回栈顶状态
int state(Stack stack)
{
    return stack.tokens[stack.top-1];
}


//编译
void Compile::compile(string filename)
{
    //打开源文件
    if(istxt(filename)){
        infile = fopen(filename.c_str(), "r");
        if(infile == NULL){
            cout << "无法打开" << filename << endl;
            return;
        }
    }else{
        cout << "不是txt文件" << endl;
        return;
    }

    //创建输出文件
    outfile = fopen(filename.substr(0, filename.size() - 4).append(".yy.txt").c_str(), "w");
    if(outfile == NULL){
        cout << "创建文件" << filename.substr(0, filename.size() - 4) << ".yy.txt失败！" << endl;
        fclose(infile);
        return;
    }

    parser();

    fclose(infile);
    fclose(outfile);

    completeTree();

    outfile = fopen(filename.substr(0, filename.size() - 4).append(".html").c_str(), "w");
    if(outfile == NULL){
        cout << "创建文件" << filename.substr(0, filename.size() - 4) << ".yy.txt失败！" << endl;
        fclose(infile);
        return;
    }
    fprintf(outfile, "<html>\n<head>\n<META content=\"text/html; charset=gb2312\">\n</head>\n<body>\n");
    html(Tree);
    fprintf(outfile, "</body>\n</html>");
    fclose(outfile);
}

//返回字符c的类型
int Compile::typeofchar(char c)
{
    if((c <= 'z' && c >= 'a') || (c <='Z' && c >= 'A')){
        return LETTER;
    }else if(c >= '0' && c <'9'){
        return DIGIT;
    }else if(c == '(' || c == ')' || c == '{'
             || c == '}' || c == '_' || c == '^' || c == '$'){
        return SYMBOL;
    }else if(c == ' ' || c == '\n'){
        return SPLITS;
    }else if(c== '\\'){
        return BACKSLASH;
    }else{
        return INVALID_CHAR;
    }
}

//判断输入文件名是否为.txt后缀
bool Compile::istxt(string filename)
{
    if(filename.substr(filename.size() - 4, 4) == ".txt"){
        return true;
    }else{
        return false;
    }
}

//词法分析
int Compile::lexer(string textline)
{
    int i = column - 1;
    while(i < textline.size()){
        switch(typeofchar(textline[i]))
        {
            case LETTER : len = getid(textline).size(); column++; return ID;
            case DIGIT : len = getnumber(textline).size(); column++; return NUMBER;
            case BACKSLASH : return getISB(textline);
            case INVALID_CHAR : column++; return INVALID_CHAR;
            case SPLITS : break;
            case SYMBOL : column++; return SYMBOL;
        }
        column++;
        i++;
    }
    return SPLITS;
}


//对标识符正规式的分析，id -> letter(letter|digit)*
string Compile::getid(string textline)
{
    int i = column;
    string id;
    id.append(1, textline[i-1]);

    while(i < textline.size()){
        switch(typeofchar(textline[i]))
        {
            case LETTER :
            case DIGIT : id.append(1, textline[i]); column++; i++; break;
            case BACKSLASH :
            case INVALID_CHAR :
            case SPLITS :
            case SYMBOL : i = textline.size(); break;
        }
    }
    return id;
}

//对无符号整型数正规式的分析，number -> digit+
string Compile::getnumber(string textline)
{
    int i = column;
    string number;
    number.append(1, textline[i-1]);

    while(i < textline.size()){
        switch(typeofchar(textline[i]))
        {
            case DIGIT : number.append(1, textline[i]); column++; i++; break;
            case BACKSLASH :
            case LETTER :
            case INVALID_CHAR :
            case SPLITS :
            case SYMBOL : column; i = textline.size(); break;
        }
    }
    return number;
}


//识别\int、\sum和\blank
int Compile::getISB(string textline)
{
    int i = column;

    if(textline.substr(i, 3) == "int"){
        column = column + 4;
        return INT;
    }else if(textline.substr(i, 3) == "sum"){
        column = column + 4;
        return SUM;
    }else if(textline.substr(i, 5) == "BLANK"){
        column = column + 6;
        return BLANK;
    }else{
        column++;
        return INVALID_CHAR;
    }
}

//语法分析器
void Compile::parser()
{
    line = 1;
    init(&stack);
    push(&stack, 0);
    printf("\t\t\t\t栈\t\t\t\t\t\t\t输入\t\t\t\t\t\t\t\t\t动作\n");
    fprintf(outfile, "\t\t\t栈\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t输入\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t动作\n");

    while(1){
        char tline[SIZE];
        if(fscanf(infile, "%s", tline) == EOF || strlen(tline) == 0){     //读取文件一行内容
            int exit = 0;
            while(!exit){
                printStack();
                printf("%-75s", "#");
                fprintf(outfile, "%-75s", "#");
                int s = state(stack);     //栈顶状态
                if(a[s][A_END] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_END] - 1]);
                    int t = state(stack);
                    if(st[s][A_END] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    Tree = nodeStack.top();
                    Tree->parent = nullptr;
                    nodeStack.pop();
                    printf( "按%s归约\n", r[st[s][A_ID] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_ID] - 1].c_str());
                }else if(a[s][A_END] == 'a'){
                    printf("接受\n");
                    fprintf(outfile, "接受\n");
                    exit = 1;
                }else{
                    printf("接受失败\n");
                    fprintf(outfile, "接受失败\n");
                    exit = 1;
                }
            }
            break;
        }
        int i = 0;
        column = 1;
        string textline = tline;
        while(i < textline.size()){
            printStack();
            printInupt(textline);
            int token = lexer(textline);
            int s = state(stack);     //栈顶状态
            if(token == ID){
                if(a[s][A_ID] == 's'){
                    push(&stack, ID);
                    push(&stack, st[s][A_ID]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][A_ID] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_ID] - 1]);
                    int t = state(stack);
                    if(st[s][A_ID] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }

                    printf("按%s归约\n", r[st[s][A_ID] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_ID] - 1].c_str());
                    column -= len;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else if(token == NUMBER){
                if(a[s][A_NUM] == 's'){
                    push(&stack, NUMBER);
                    push(&stack, st[s][A_NUM]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][A_SUM] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_SUM] - 1]);
                    int t = state(stack);
                    if(st[s][A_NUM] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    printf("按%s归约\n", r[st[s][A_NUM] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_NUM] - 1].c_str());
                    column -= len;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else if(token == INT){
                if(a[s][A_INT] == 's'){
                    push(&stack, INT);
                    push(&stack, st[s][A_INT]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][A_INT] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_INT] - 1]);
                    int t = state(stack);
                    if(st[s][A_INT] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    PNode idNode = (PNode)malloc(sizeof(Node));
                    idNode->key = new char[5];
                    *idNode->key = tline[column - 6];
                    nodeStack.push(idNode);
                    printf("按%s归约\n", r[st[s][A_INT] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_INT] - 1].c_str());
                    column -= 4;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else if(token == SUM){
                if(a[s][A_SUM] == 's'){
                    push(&stack, SUM);
                    push(&stack, st[s][A_SUM]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][A_SUM] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_SUM] - 1]);
                    int t = state(stack);
                    if(st[s][A_SUM] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    printf("按%s归约\n", r[st[s][A_SUM] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_SUM] - 1].c_str());
                    column -= 4;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else if(token == BLANK){
                if(a[s][A_BLANK] == 's'){
                    push(&stack, BLANK);
                    push(&stack, st[s][A_BLANK]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][A_BLANK] == 'r'){
                    pop(&stack, 2 * rlen[st[s][A_BLANK] - 1]);
                    int t = state(stack);
                    if(st[s][A_BLANK] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    printf("按%s归约\n", r[st[s][A_BLANK] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][A_BLANK] - 1].c_str());
                    column -= 6;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else if(token == SYMBOL){
                int symbol, a_symbol;
                PNode symbolNode = (PNode)malloc(sizeof(Node));
                switch(textline[column - 2])
                {
                    case '(' : symbol = LBRACKET; a_symbol = A_LBRACKET; break;
                    case ')' : symbol = RBRACKET; a_symbol = A_RBRACKET; break;
                    case '{' : symbol = LBRACE; a_symbol = A_LBRACE; break;
                    case '}' : symbol = RBRACE; a_symbol = A_RBRACE; break;
                    case '_' : symbol = UNDERLINE; a_symbol = A_UNDERLINE; break;
                    case '^' : symbol = CARET; a_symbol = A_CARET; break;
                    case '$' : symbol = DOLLAR; a_symbol = A_DOLLAR; break;
                }
                if(a[s][a_symbol] == 's'){
                    push(&stack, symbol);
                    push(&stack, st[s][a_symbol]);
                    printf("移进\n");
                    fprintf(outfile, "移进\n");
                }else if(a[s][a_symbol] == 'r'){
                    pop(&stack, 2 * rlen[st[s][a_symbol] - 1]);
                    int t = state(stack);
                    if(st[s][a_symbol] == 1){
                        push(&stack, S);
                        push(&stack, gotof[t][G_S]);
                    }else{
                        push(&stack, B);
                        push(&stack, gotof[t][G_B]);
                    }
                    PNode idNode = (PNode)malloc(sizeof(Node));
                    if (st[s][a_symbol] != 4 && st[s][a_symbol] != 6 && st[s][a_symbol] != 2 && st[s][a_symbol] != 11 && st[s][a_symbol] != 7) {
                        idNode->key = new char[5];
                        for (int i = 0; i < len; i ++) {
                            idNode->key[i] = textline[column - len + i - 2];
                            idNode->child = nullptr;
                        }
                        nodeStack.push(idNode);
                        if (a_symbol != A_LBRACE && a_symbol != A_RBRACE) {
                            symbolNode->key = new char[5];
                            *symbolNode->key = textline[column - 2];
                            nodeStack.push(symbolNode);
                        }
                    } else if (st[s][a_symbol] == 4) {    //B -> B^{B}
                        PNode idNode1 = (PNode)malloc(sizeof(Node));
                        PNode idNode2 = (PNode)malloc(sizeof(Node));
                        idNode1 = nodeStack.top();
                        nodeStack.pop();
                        idNode = nodeStack.top();
                        nodeStack.pop();
                        idNode2 = nodeStack.top();
                        nodeStack.pop();
                        idNode->child = idNode2;
                        idNode2->bro = idNode1;
                        idNode2->child = nullptr;
                        idNode2->parent = idNode;
                        idNode1->parent = idNode;
                        idNode1->child = nullptr;
                        idNode1->bro = nullptr;
                        nodeStack.push(idNode);
                    } else if (st[s][a_symbol] == 6) {
                        PNode idNode1 = (PNode)malloc(sizeof(Node));
                        PNode idNode2 = (PNode)malloc(sizeof(Node));
                        idNode1 = nodeStack.top();  // id
                        nodeStack.pop();
                        idNode = nodeStack.top();   // num2
                        nodeStack.pop();
                        idNode2 = nodeStack.top();  // num1
                        nodeStack.pop();
                        PNode intNode = (PNode)malloc(sizeof(Node));
                        intNode->key = new char[5];
                        intNode->key[0] = '\\'; intNode->key[1] = 'i'; intNode->key[2] = 'n'; intNode->key[3] = 't';
                        intNode->child = idNode1;
                        idNode1->bro = idNode2;
                        idNode1->parent = intNode;
                        idNode1->child = nullptr;
                        idNode2->bro = idNode;
                        idNode2->parent = intNode;
                        idNode->bro = nullptr;
                        idNode->parent = intNode;
                        nodeStack.push(intNode);
                    } else if (st[s][a_symbol] == 2) {
                        PNode idNode1 = (PNode)malloc(sizeof(Node));
                        PNode idNode2 = (PNode)malloc(sizeof(Node));
                        idNode1 = nodeStack.top();  // B2
                        nodeStack.pop();
                        idNode2 = nodeStack.top();   // B1
                        nodeStack.pop();
                        PNode bbNode = (PNode)malloc(sizeof(Node));
                        bbNode->key = new char[5];
                        bbNode->key[0] = 'B'; bbNode->key[1] = 'B';
                        bbNode->child = idNode2;
                        idNode2->bro = idNode1;
                        idNode2->parent = bbNode;
                        idNode1->bro = nullptr;
                        idNode1->parent = bbNode;
                        nodeStack.push(bbNode);
                    } else if (st[s][a_symbol] == 11) {
                        PNode idNode1 = (PNode)malloc(sizeof(Node)); // '('
                        PNode idNode2 = (PNode)malloc(sizeof(Node)); // ')'
                        idNode1->key = new char[1];
                        *idNode1->key = '(';
                        idNode2->key = new char[1];
                        *idNode2->key = ')';
                        idNode = nodeStack.top();
                        nodeStack.pop();
                        PNode bracketNode = (PNode)malloc(sizeof(Node));
                        bracketNode->key = new char[3];
                        bracketNode->key[0] = '('; bracketNode->key[1] = 'B'; bracketNode->key[2] = ')';
                        bracketNode->child = idNode1;
                        idNode1->parent = bracketNode;
                        idNode1->bro = idNode;
                        idNode->parent = bracketNode;
                        idNode->bro = idNode2;
                        idNode2->bro = nullptr;
                        idNode2->parent = bracketNode;
                        nodeStack.push(bracketNode);
                    } else if (st[s][a_symbol == 7]) {
                        PNode idNode1 = (PNode)malloc(sizeof(Node));
                        PNode idNode2 = (PNode)malloc(sizeof(Node));
                        idNode1 = nodeStack.top();  // B1
                        nodeStack.pop();
                        idNode2 = nodeStack.top();   // B3
                        nodeStack.pop();
                        idNode = nodeStack.top();  // B2
                        nodeStack.pop();
                        PNode sumNode = (PNode)malloc(sizeof(Node));
                        sumNode->key = new char[4];
                        sumNode->key[0] = '\\'; sumNode->key[1] = 's'; sumNode->key[2] = 'u'; sumNode->key[3] = 'm';
                        sumNode->child = idNode1;
                        idNode1->bro = idNode;
                        idNode1->parent = sumNode;
                        idNode->bro = idNode2;
                        idNode->parent = sumNode;
                        idNode2->bro = nullptr;
                        idNode2->parent = sumNode;
                        nodeStack.push(sumNode);
                    }
                    printf("按%s归约\n", r[st[s][a_symbol] - 1].c_str());
                    fprintf(outfile, "按%s归约\n", r[st[s][a_symbol] - 1].c_str());
                    column -= 1;
                }else{
                    fprintf(outfile, "   error at line %d, column %d \n", line, column);
                }
            }else{
                fprintf(outfile, "   error at line %d, column %d \n", line, column);
            }
            i = column - 1;
        }
        line++;
    }
}

void Compile::initAttr() {
    normalFontSize = 100;
    initTop = 200;
    initLeft = 500;
}

void Compile::fontSize(PNode pnode) {
    if (pnode->child != nullptr) {
        std::string temp(pnode->key);
        if(temp == "\\sum") {
            pnode->font_size = (int)(normalFontSize * 1.6); fontSize(pnode->child); fontSize(pnode->child->bro);
            fontSize(pnode->child->bro->bro);
        } else if (temp == "(B)") {
            pnode->font_size = normalFontSize; pnode->child->font_size = pnode->font_size;
            pnode->child->bro->font_size = pnode->font_size; pnode->child->bro->bro->font_size = pnode->font_size;
            fontSize(pnode->child->bro);
        } else if (temp == "BB") {
            pnode->child->font_size = pnode->font_size; pnode->child->bro->font_size = pnode->font_size;
            fontSize(pnode->child); fontSize(pnode->child->bro);
        } else if (temp == "\\int") {
            pnode->font_size = (int)(normalFontSize * 1.6); pnode->child->font_size = normalFontSize;
            pnode->child->bro->font_size = normalFontSize / 2; pnode->child->bro->bro->font_size = normalFontSize / 2;
        } else if (temp == "^") {
            pnode->font_size = normalFontSize; pnode->child->font_size = normalFontSize / 2; pnode->child->bro->font_size = \
                      normalFontSize / 4;
        }
    }
    else {
        pnode->font_size = normalFontSize;
    }
}

void Compile::widthAndWeight(PNode pnode) {
    if (pnode->child != nullptr) {
        std::string temp(pnode->key);
        if (temp == "\\sum") {
            pnode->height = pnode->font_size;
            widthAndWeight(pnode->child);
            widthAndWeight(pnode->child->bro);
            widthAndWeight(pnode->child->bro->bro);
            pnode->width = pnode->font_size * 67 / 80 + \
                    pnode->child->width + pnode->child->bro->width + pnode->child->bro->bro->width;
        } else if (temp == "(B)") {
            pnode->height = pnode->parent->height;
            widthAndWeight(pnode->child);
            widthAndWeight(pnode->child->bro);
            widthAndWeight(pnode->child->bro->bro);
            pnode->width = pnode->child->width + pnode->child->bro->width + pnode->child->bro->bro->width;
        } else if (temp == "BB") {
            pnode->height = pnode->parent->height;
            widthAndWeight(pnode->child);
            widthAndWeight(pnode->child->bro);
            pnode->width = pnode->child->width + pnode->child->bro->width;
        } else if (temp == "\\int") {
            pnode->height = pnode->parent->height;
            widthAndWeight(pnode->child);
            widthAndWeight(pnode->child->bro);
            widthAndWeight(pnode->child->bro->bro);
            pnode->width = pnode->font_size * 3 / 4 + \
                pnode->child->width + pnode->child->bro->width + pnode->child->bro->bro->width;
        } else if (temp == "^") {
            pnode->height = pnode->parent->height;
            widthAndWeight(pnode->child);
            widthAndWeight(pnode->child->bro);
            pnode->width = pnode->child->width + pnode->child->bro->width;
        }
    }else if (pnode->child == nullptr) {
        if (typeofchar(*pnode->key) == DIGIT || typeofchar(*pnode->key) == LETTER) {
            int len = strlen(pnode->key);
            pnode->width = len * (pnode->font_size) / 2;
        }
        else if(typeofchar(*pnode->key) == SYMBOL) {
            pnode->width = pnode->font_size;
        }
    }
}

void Compile::coordinates(PNode pnode) {
    std::string temp(pnode->key);
    if (pnode->child != nullptr) {
        if(pnode->parent == nullptr) {  //root
            pnode->x = initLeft;
            pnode->y = initTop;
            coordinates(pnode->child);
        }
        if (temp == "\\sum") {
            pnode->child->x = pnode->x + pnode->font_size + 11;
            pnode->child->y = pnode->y + 30;
            coordinates(pnode->child);
            pnode->child->bro->x = pnode->x + pnode->font_size / 2 + 54;
            pnode->child->bro->y = pnode->y + 110;
            coordinates(pnode->child->bro);
            pnode->child->bro->bro->x = pnode->child->bro->x;
            pnode->child->bro->bro->y = pnode->y - pnode->child->bro->bro->font_size / 2;
            coordinates(pnode->child->bro->bro);
        } else if (temp == "(B)") {
            pnode->child->x = pnode->x;
            pnode->child->y = pnode->y;
            pnode->child->bro->x = pnode->child->x + pnode->child->font_size / 2;
            pnode->child->bro->y = pnode->y;
            coordinates(pnode->child->bro);
            pnode->child->bro->bro->x = 2*pnode->child->width + pnode->child->bro->x + normalFontSize;
            pnode->child->bro->bro->y = pnode->y;
        } else if (temp == "BB") {
            pnode->child->x = pnode->x;
            pnode->child->y = pnode->y;
            coordinates(pnode->child);
            pnode->child->bro->x = pnode->x + pnode->child->font_size / 2;
            pnode->child->bro->y = pnode->y;
            coordinates(pnode->child->bro);
        } else if (temp == "\\int") {
            pnode->y = initTop;
            pnode->child->x = pnode->x + 145;
            pnode->child->y = pnode->y + 30;
            coordinates(pnode->child);
            pnode->child->bro->x = pnode->x + 120;
            pnode->child->bro->y = pnode->y + 110;
            coordinates(pnode->child->bro);
            pnode->child->bro->bro->x = pnode->child->bro->x;
            pnode->child->bro->bro->y = pnode->y - pnode->child->bro->bro->font_size / 2;
            coordinates(pnode->child->bro->bro);
        } else if (temp == "^") {
            pnode->child->x = pnode->x;
            pnode->child->y = pnode->y;
            coordinates(pnode->child);
            pnode->child->bro->x = pnode->x + pnode->child->width;
            pnode->child->bro->y = pnode->y - 12;
            coordinates(pnode->child->bro);
        }
    } else {
        // do nothing
    }
}

void Compile::completeTree() {
    initAttr();
    fontSize(Tree);
    widthAndWeight(Tree);
    coordinates(Tree);
}

void Compile::html(PNode pnode) {
    if (pnode->child != nullptr) {  //非终结符
        std::string temp(pnode->key);
        if (temp == "\\sum") {
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:normal; line−height:100%%;\">∑</span></div>\n",
                                pnode->y, pnode->x, pnode->font_size);
            html(pnode->child);
            html(pnode->child->bro);
            html(pnode->child->bro->bro);
        } else if (temp == "(B)") {
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:normal; line−height:100%%;\">(</span></div>\n",
                    pnode->y, pnode->child->x, pnode->font_size);
            html(pnode->child->bro);
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:normal; line−height:100%%;\">)</span></div>\n",
                    pnode->y, pnode->child->bro->bro->x, pnode->font_size);
        } else if (temp == "BB") {
            html(pnode->child);
            html(pnode->child->bro);
        } else if (temp == "\\int") {
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:normal; line−height:100%%;\">∫</span></div>\n",
                    pnode->y, pnode->x, pnode->font_size);
            html(pnode->child);
            html(pnode->child->bro);
            html(pnode->child->bro->bro);
        } else if (temp == "^") {
            html(pnode->child);
            html(pnode->child->bro);
        }
    } else {    //终结符
        std::string termSym(pnode->key);
        if (typeofchar(*pnode->key) == LETTER) {
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:oblique; line−height:100%%;\">%s</span></div>\n",
                    pnode->y, pnode->x, pnode->font_size, termSym.c_str());
        } else {
            fprintf(outfile, "<div style=\"position: absolute; top:%dpx; left :%dpx;\"><span style=\"font−size:%dpx; font−style:normal; line−height:100%%;\">%s</span></div>\n",
                    pnode->y, pnode->x, pnode->font_size, termSym.c_str());
        }
    }
}

void Compile::printStack()
{
    string s;
    int i;

    for(i = 0; i < stack.top; i++){
        if(stack.tokens[i] < 100){
            char str[10];
            sprintf(str, "%d", stack.tokens[i]);
            s.append(str);
        }else{
            switch(stack.tokens[i])
            {
                case ID : s.append("id"); break;
                case NUMBER : s.append("num"); break;
                case UNDERLINE : s.append("_"); break;
                case CARET : s.append("^"); break;
                case INT : s.append("\\int"); break;
                case SUM : s.append("\\sum"); break;
                case BLANK : s.append("\\blank"); break;
                case LBRACE : s.append("{"); break;
                case RBRACE : s.append("}"); break;
                case LBRACKET : s.append("("); break;
                case RBRACKET : s.append(")"); break;
                case DOLLAR : s.append("$"); break;
                case S : s.append("S"); break;
                case B : s.append("B"); break;
            }
        }
    }
    printf("%s", s.c_str());
    fprintf(outfile, "%-75s", s.c_str());
}

void Compile::printInupt(string textline)
{
    textline.append(1, '#');
    printf("%-75s", textline.substr(column-1, textline.size()-column+1).c_str());
    fprintf(outfile, "%-75s", textline.substr(column-1, textline.size()-column+1).c_str());
}