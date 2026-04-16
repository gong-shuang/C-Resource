// 引用做函数返回值示例
// 展示引用作为函数返回值的用法：不要返回局部变量的引用，函数调用可以作为左值
#include<iostream>
using namespace std;

//返回局部变量引用
int& test01() {
	int a = 10; //局部变量，存储在栈区
	return a; // 返回局部变量的引用，这是危险的
}

//返回静态变量引用
int& test02() {
	static int a = 20; // 静态变量，存储在全局区
	return a; // 返回静态变量的引用，这是安全的
}

int main() {

	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl; // 第一次访问可能正确
	cout << "ref = " << ref << endl; // 第二次访问可能错误

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl; // 输出20
	cout << "ref2 = " << ref2 << endl; // 输出20

	test02() = 1000; // 函数调用作为左值

	cout << "ref2 = " << ref2 << endl; // 输出1000
	cout << "ref2 = " << ref2 << endl; // 输出1000

	system("pause");

	return 0;
}
