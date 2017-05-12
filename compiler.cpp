//
// Created by Peterson Xu on 27/04/2017.
//
#include "mathFormula.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Compile test;

    string filename;
    cout << "输入文件名：" << endl;
    cin >> filename;
    test.compile(filename);
}
