/**
 * ==================================================
 *  @file 01_文本写.cpp
 *  @brief TODO (这里描述文件的主要功能)
 *  @author gs
 *  @date 2026-04-14 22:08:07
 * ==================================================
 */

#include<iostream>
using namespace std;


#include <fstream>

void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);

    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

int main() {

    test01();

    system("pause");

    return 0;
}