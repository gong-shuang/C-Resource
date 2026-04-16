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

class Animal
{
public:
    int m_Age;
    Animal() {
        cout << "Animal 构造函数!" << endl;
        m_Age = 1;
    }
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {
public:
    Sheep() {
        cout << "Sheep 构造函数!" << endl;
        m_Age = 1;
    }
};
class Tuo   : virtual public Animal {
public:
    Tuo() {
        cout << "Tuo 构造函数!" << endl;
        m_Age = 1;
    }

};
class SheepTuo : public Sheep, public Tuo {
public:
    SheepTuo() {
        cout << "SheepTuo 构造函数!" << endl;
        m_Age = 1;
    }

};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;

    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {

    test01();

    system("pause");

    return 0;
}
