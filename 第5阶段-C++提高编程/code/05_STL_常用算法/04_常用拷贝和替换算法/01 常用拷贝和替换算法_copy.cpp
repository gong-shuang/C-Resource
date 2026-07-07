#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用拷贝和替换算法 copy
void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}

class Person
{
public:
	Person() : m_Name(""), m_Age(0) {}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
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
	vector<Person> v1;
	v1.push_back(Person("张三", 20));
	v1.push_back(Person("李四", 25));
	v1.push_back(Person("王五", 30));
	v1.push_back(Person("赵六", 35));

	vector<Person> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrintPerson);
}

int main() {

	// test01();

	test02();

	system("pause");

	return 0;
}