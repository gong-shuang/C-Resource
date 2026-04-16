// 堆区示例
// 展示堆区数据的特性：由程序员分配释放，使用new关键字开辟内存
#include<iostream>
using namespace std;

int* func()
{
	int* a = new int(10); // 在堆区开辟内存
	return a; // 返回堆区数据的地址，这是安全的
}

int main() {

	int *p = func(); // 接收堆区数据的地址

	cout << *p << endl; // 可以正常访问
	cout << *p << endl; // 可以正常访问
    
	system("pause");

	return 0;
}
