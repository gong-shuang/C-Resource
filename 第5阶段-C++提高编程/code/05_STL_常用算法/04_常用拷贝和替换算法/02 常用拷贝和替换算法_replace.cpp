#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//常用拷贝和替换算法 replace
void test01()
{

	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;


	//将20 替换 2000
	replace(v.begin(), v.end(), 20, 2000);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person &p) const
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	string m_Name;
	int m_Age;
};

void myPrintPerson(const Person &p)
{
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

void test02()
{
	vector<Person> v;
	v.push_back(Person("张三", 20));
	v.push_back(Person("李四", 25));
	v.push_back(Person("王五", 30));
	v.push_back(Person("张三", 20));
	v.push_back(Person("赵六", 35));
	v.push_back(Person("张三", 20));

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrintPerson);
	cout << endl;

	// 将"张三 20岁"替换为"张三 99岁"
	replace(v.begin(), v.end(), Person("张三", 20), Person("张三", 99));

	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), myPrintPerson);
	cout << endl;
}

int main() {

	// test01();

	test02();

	system("pause");

	return 0;
}