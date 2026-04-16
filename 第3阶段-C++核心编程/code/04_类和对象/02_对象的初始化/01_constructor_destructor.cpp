// 构造函数和析构函数示例
// 展示构造函数和析构函数的基本用法：自动调用，完成对象的初始化和清理工作
#include<iostream>
using namespace std;

class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}
	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

};

void test01()
{
	Person p;
}

int main() {
	
	test01();

	system("pause");

	return 0;
}
