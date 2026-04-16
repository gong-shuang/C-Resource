// new操作符开辟数组示例
// 展示如何使用new在堆区开辟数组，以及如何使用delete[]释放数组内存
#include<iostream>
using namespace std;

int main() {

	int* arr = new int[10]; // 在堆区开辟一个包含10个元素的整型数组

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100; // 给数组元素赋值
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl; // 输出数组元素
	}
	//释放数组 delete 后加 []
	delete[] arr;

	system("pause");

	return 0;
}
