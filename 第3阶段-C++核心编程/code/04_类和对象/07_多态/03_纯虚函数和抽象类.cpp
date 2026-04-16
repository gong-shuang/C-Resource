/**
 * ==================================================
 *  @file 01_多态的基本概念.cpp
 *  @brief TODO (这里描述文件的主要功能)
 *  @author gs
 *  @date 2026-04-14 22:04:42
 * ==================================================
 */

#include<iostream>
using namespace std;


class Base
{
public:
    //纯虚函数
    //类中只要有一个纯虚函数就称为抽象类
    //抽象类无法实例化对象
    //子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son :public Base
{
public:
    virtual void func()
    {
        cout << "func调用" << endl;
    };
};

void test01()
{
    Base * base = NULL;
    //base = new Base; // 错误，抽象类无法实例化对象
    base = new Son;
    base->func();
    delete base;//记得销毁
}

int main() {

    test01();

    system("pause");

    return 0;
}