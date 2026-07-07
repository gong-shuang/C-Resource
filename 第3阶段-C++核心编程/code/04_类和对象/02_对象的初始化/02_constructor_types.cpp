// 构造函数的分类及调用示例
// 展示构造函数的不同分类：按参数分为有参和无参构造，按类型分为普通和拷贝构造
// 展示构造函数的三种调用方式：括号法、显示法、隐式转换法
#include<iostream>
#include<string>
using namespace std;

//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

class Son {
	public:
	Son() {
		age = 0;
		cout << " Son 无参构造函数! " << endl;
	};
	Son(int a) {
		age = a;
		cout << " Son 有参构造函数! a: " << a << endl;
	};
	//拷贝构造函数
	Son(const Son& s) {
		age = s.age;
		cout << " Son 拷贝构造函数! age: " << age << endl;
	};
	// 重载 运算符 =
	Son& operator=(const Son& s) {
		cout << " Son 赋值运算符! age: " << s.age << endl;
		if (this != &s) {
			age = s.age;
		}
		return *this;
	}
	int age;
};

class Person {
public:
	// 无参（默认）构造函数
	 Person() {
		cout << "无参构造函数!" << endl;
	}

	// 有参构造函数
	Person(const int a){
	 	age = a;
	 	cout << "有参构造函数! 1111, a: " << a << endl;
	 }
	 Person(int a, string n, Son s) : son(2){
		age = a;
		name = n;
	 	son = s;
		cout << "有参构造函数! a: " << a << endl;
	}

	//拷贝构造函数
	Person(const Person& p) {   // 这里的 const 必须加上
		age = p.age;
		cout << "拷贝构造函数! age:" << age << endl;
	}

	//析构函数
	~Person() {
		cout << "析构函数! age:" << age << endl;
	}
	void print() {
		 cout << "age: " << age << ", name:" << name  << ", son.age:" << son.age << endl;
	}
public:
	int age;
	string name;
	Son son;
};

//2、构造函数的调用
//调用无参构造函数
void test01() {
	Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02() {

	//2.1  括号法，常用
	Person p1;
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p2();

	//2.2 显式法
	Son ss = Son(1);
	cout << "----1---" << endl;
	Person p2 = Person(2, "ss", ss);
	Person p3 = Person(p2);
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	p1.print();
	p2.print();
	p3.print();

	cout << "----2---" << endl;

	//2.3 隐式转换法
	Person p4 = 3; // Person p4 = Person(10);
	Person p5 = p4; // Person p5 = Person(p4);

	cout << "----3---" << endl;

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	Person p6(p4);
	// Person p6 = Person(p4);

	// 注意： gs： 如果拷贝构造函数的参数 不加 const， 那么下面的代码会报错
	// const Person p7;
	// Person p8 = p7;   // 报错！因为 p1 是 const，不能绑定到非const引用
	// Person p9 = Person(20);   // 报错！临时对象不能传给 Person(Person&)
}

int main() {

	// test01();
	test02();

	system("pause");

	return 0;
}
