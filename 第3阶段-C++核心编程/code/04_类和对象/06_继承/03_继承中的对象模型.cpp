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
    int m_A;

protected:
    int m_B;

private:
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son : public Base {
public:
    int m_D;
};

void test01() {
    cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {
    test01();

    system("pause");

    return 0;
}
