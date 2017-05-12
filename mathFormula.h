//
// Created by Peterson Xu on 27/04/2017.
//
#ifndef _MATH_FORMULA_H
#define _MATH_FORMULA_H

#include <string>
#include <stack>
#define SIZE 200    //处理源文件每行的长度

//字符集
#define LETTER 1001             //字母[a..zA..Z]
#define DIGIT 1002              //数字[0..9]
#define SYMBOL 1003             //特殊符号(、)、{、}、_、^、$
#define BACKSLASH 1004          //反斜杠
#define SPLITS 1005             //空格、换行
#define INT 1006                //表示\int
#define SUM 1007                //表示\sum
#define BLANK 1008              //表示\blank
#define ID 1009                 //表示标识符
#define NUMBER 1010             //表示无符号整型数
#define UNDERLINE 1011          //_
#define CARET 1012              //^
#define LBRACE 1023             //{
#define RBRACE 1024             //}
#define LBRACKET 1025           //(
#define RBRACKET 1026           //)
#define DOLLAR 1027             //$
#define S 1028                  //非终结符S
#define B 1029                  //非终结符B
#define INVALID_CHAR 1000       //其他非法字符

//标记action函数列名
#define A_ID 0              //id
#define A_NUM 1             //num
#define A_UNDERLINE 2       //_
#define A_CARET 3           //^
#define A_INT 4             //INT
#define A_SUM 5             //SUM
#define A_BLANK 6           //BLANK
#define A_LBRACE 7          //{
#define A_RBRACE 8          //}
#define A_LBRACKET 9        //(
#define A_RBRACKET 10       //)
#define A_DOLLAR 11         //$
#define A_END 12            //#

#define ACC 999    //表示接受

typedef struct{
    int tokens[SIZE];
    int top;
}Stack;

typedef struct node{
    char* key;
    int x, y, font_size, font_style, width, height;
    struct node *child, *parent, *bro;
}Node;
typedef Node *PNode;

//栈上的操作
void init(Stack *stack);
void push(Stack *stack, int x);
void pop(Stack *stack, int length);
int state(Stack stack);


class Compile {

    FILE* infile;                                         //源文件
    FILE* outfile;                                        //输出文件
    int line, column;                                     //标记当前正在分析的行、列号
    int len;                                              //指示当前id或number记号的长度
    int typeofchar(char c);                               //返回字符c的类型
    bool istxt(std::string filename);                     //判断输入文件名是否为.txt后缀
    int lexer(std::string textline);                      //词法分析器
    std::string getid(std::string textline);              //对标识符正规式的分析，id -> letter(letter|digit)*
    std::string getnumber(std::string textline);          //对无符号整型数正规式的分析，number -> digit+
    int getISB(std::string textline);                     //识别\int、\sum和\blank
    void parser();                                        //语法分析器
    Stack stack;                                          //语法分析栈
    PNode Tree;
    void receive(int n, PNode pnode);
    void completeTree();
    void initAttr();
    void fontSize(PNode pnode);
    void widthAndWeight(PNode pnode);
    void coordinates(PNode pnode);
    void html(PNode pnode);
    int max(int a, int b);
    int max(int a, int b, int c);
    std::stack<PNode> nodeStack;
    int normalFontSize;
    int initTop;
    int initLeft;
    void printStack();
    void printInupt(std::string textline);

public:

    void compile(std::string filename);            //编译

};

#endif /* _MATH_FORMULA_H */