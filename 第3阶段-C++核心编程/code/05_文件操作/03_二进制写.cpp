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
#include <string>

class Person {
public:
    char m_Name[64];
    int m_Age;
};

//二进制文件  写文件
void test01() {
    //1、包含头文件

    //2、创建输出流对象
    ofstream ofs("person.txt", ios::out | ios::binary);

    //3、打开文件
    //ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};

    //4、写文件
    ofs.write((const char *) &p, sizeof(p));

    //5、关闭文件
    ofs.close();
}

int main() {
    test01();

    system("pause");

    return 0;
}
