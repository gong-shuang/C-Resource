// 引用的基本使用示例
// 展示引用的语法和基本用法：给变量起别名
#include<iostream>
using namespace std;

int main() {

	int a = 10;
	int &b = a; // 声明引用，b是a的别名

	cout << "a = " << a << endl; // 输出10
	cout << "b = " << b << endl; // 输出10

	b = 100; // 修改引用的值，会影响原变量

	cout << "a = " << a << endl; // 输出100
	cout << "b = " << b << endl; // 输出100

	system("pause");

	return 0;
}
