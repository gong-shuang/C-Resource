// 左移运算符重载示例
// 展示如何重载左移运算符以输出自定义数据类型
#include<iostream>
using namespace std;

class Person {
	// friend 声明让函数能访问 private 成员 m_A/m_B，
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
	// operator<< 无法用成员函数实现：cout << p1 的左操作数是 cout（ostream），不是 Person。成员函数方式会变成 p1 << cout，与期望效果相反。
	// void operator<<(Person& p){
	// }

private:
	int m_A;
	int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() { 

	Person p1(10, 20);

	cout << p1 << " hello world" << endl; // 链式编程
}

int main() { 

	test();

	system("pause");

	return 0;
}
