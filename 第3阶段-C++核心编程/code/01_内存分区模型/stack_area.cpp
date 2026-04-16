// 栈区示例
// 展示栈区数据的特性：由编译器自动分配释放，不要返回局部变量的地址
#include<iostream>
using namespace std;

int * func()
{
	int a = 10; // 局部变量，存储在栈区，函数执行完毕后自动释放
	return &a; // 返回局部变量的地址，这是危险的
}

int main() {

	int *p = func(); // 接收局部变量的地址

	cout << *p << endl; // 第一次访问可能正确，因为内存还未被覆盖
	cout << *p << endl; // 第二次访问可能错误，因为内存已经被释放

	system("pause");

	return 0;
}
