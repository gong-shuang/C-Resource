// 初始化列表示例
// 展示如何使用初始化列表语法来初始化属性
// 语法：   构造函数()：属性1(值1),属性2（值2）... {}
#include<iostream>
using namespace std;

class Son {
public:
	Son(int c) {
		a=c;
		cout << "Son, a:" << a << endl;
	}
	int a;
};

class Person { 
public:

	//传统方式初始化
	// Person(int a, int b, int c) {
	// 	// 在进入函数体之前，编译器需要先默认构造所有成员对象，但 Son 没有无参构造，所以报错。
	// 	// 这正是初始化列表存在的意义——在构造成员的同时传参，而非先默认构造再赋值。
	// 	m_A = a;
	// 	m_B = b;
	// 	m_C = c + m_A.a;
	// }

	//初始化列表方式初始化，
	//其顺序是：完全由你在类中声明的顺序决定，与初始化列表中的书写顺序无关
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c+m_A.a) {
		cout << "Person, a:" << a << endl;
	}

	void PrintPerson() {
		cout << "mA:" << m_A.a << endl;
		cout << "mB:" << m_B.a << endl;
		cout << "mC:" << m_C.a << endl;
	}
private:
	Son m_C;
	Son m_A;
	Son m_B;

};

int main() {

	Person p(9, 2, 3);
	p.PrintPerson();


	system("pause");

	return 0;
}
