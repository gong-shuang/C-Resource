// new操作符示例
// 展示如何使用new在堆区开辟内存，以及如何使用delete释放内存
#include<iostream>
using namespace std;

int* func()
{
	int* a = new int(10); // 在堆区开辟内存，存储值10
	return a;
}

int main() {

	int *p = func();

	cout << *p << endl; // 输出10
	cout << *p << endl; // 输出10

	//利用delete释放堆区数据
	delete p;

	//cout << *p << endl; // 报错，释放的空间不可访问

	system("pause");

	return 0;
}
