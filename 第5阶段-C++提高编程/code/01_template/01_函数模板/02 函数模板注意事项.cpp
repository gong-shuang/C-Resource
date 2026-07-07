#include<iostream>
using namespace std;

//函数模板注意事项:
// (1)自动类型推导,必须推导出一致的数据类型T,才可以使用
// (2)模板必须要确定出T的数据类型,才可以使用

template<class T> //typename可以替换成class
void mySwap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1、自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b); //正确！
	// mySwap<int>(a, (int)c); //语法错误， 参数是 T& a, T& b（非 const 引用），而 (int)c 是一个临时值（右值）。C++ 规定：非 const 引用只能绑定到左值（具名变量），不能绑定到临时值。
	// mySwap<int>(a, c); // 错误，推导不出一致的T类型
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func 调用" << endl;
}

void test02()
{
	func<int>();  // 必须写 <int>，无法自动推导
}

int main() {

	test01();
	// test02();

	system("pause");

	return 0;
}