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
		cout << "mB:" << mB << endl;
	}
};

// 如果后面的代码使用了Person::mB变量，那么这里必须要初始化，否则编译不通过；
int Person::mB = 0;

int main() {
	Person A;
	cout << sizeof(A) << endl; // 输出4，只计算非静态成员变量的大小
	A.sfunc();

	system("pause");

	return 0;
}
