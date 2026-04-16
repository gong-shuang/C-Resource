// 引用做函数参数示例
// 展示引用作为函数参数的优势：可以直接修改实参，语法更简洁
#include<iostream>
using namespace std;

//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl; // 输出a:10 b:20，值传递不会修改实参

	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl; // 输出a:20 b:10，地址传递会修改实参

	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl; // 输出a:10 b:20，引用传递会修改实参

	system("pause");

	return 0;
}
