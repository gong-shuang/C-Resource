// 函数占位参数示例
// 展示函数占位参数的语法：用于占位，调用函数时必须填补该位置
#include<iostream>
using namespace std;

//函数占位参数 ，占位参数也可以有默认参数
void func(int a, int) {
	cout << "this is func" << endl;
}

int main() {

	func(10, 10); // 占位参数必须填补

	system("pause");

	return 0;
}
