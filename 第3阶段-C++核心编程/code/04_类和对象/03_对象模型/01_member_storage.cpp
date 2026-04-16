// 成员变量和成员函数分开存储示例
// 展示C++中类内的成员变量和成员函数是分开存储的，只有非静态成员变量才属于类的对象
#include<iostream>
using namespace std;

class Person { 
public:
	Person() { 
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB; 
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() { 
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() { 
	}
};

int main() {

	cout << sizeof(Person) << endl; // 输出4，只计算非静态成员变量的大小

	system("pause");

	return 0;
}
