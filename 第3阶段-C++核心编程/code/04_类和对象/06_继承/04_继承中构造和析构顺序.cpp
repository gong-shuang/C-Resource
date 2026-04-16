/**
 * ==================================================
 *  @file 01_继承的基本语法.cpp
 *  @brief TODO (这里描述文件的主要功能)
 *  @author gs
 *  @date 2026-04-14 22:00:59
 * ==================================================
*/
#include<iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base构造函数!" << endl;
    }

    ~Base() {
        cout << "Base析构函数!" << endl;
    }
};

class Son : public Base {
public:
    Son() {
        cout << "Son构造函数!" << endl;
    }

    ~Son() {
        cout << "Son析构函数!" << endl;
    }
};


void test01() {
    //继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
    Son s;
}

int main() {
    test01();

    system("pause");

    return 0;
}
