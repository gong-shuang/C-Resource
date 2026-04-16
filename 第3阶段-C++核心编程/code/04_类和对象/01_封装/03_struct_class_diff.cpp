// struct和class区别示例
// 展示struct和class的唯一区别：默认访问权限不同
#include<iostream>
using namespace std;

class C1
{
	int m_A; // 默认是私有权限
};

struct C2
{
	int m_A; // 默认是公共权限
};

int main() {

	C1 c1;
	//c1.m_A = 10; // 错误，访问权限是私有

	C2 c2;
	c2.m_A = 10; // 正确，访问权限是公共

	system("pause");

	return 0;
}
