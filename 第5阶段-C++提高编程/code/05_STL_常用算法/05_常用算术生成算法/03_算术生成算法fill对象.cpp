#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class User
{
public:
    string m_Name;
    int m_Age;

    User() : m_Name(""), m_Age(0) {}

    User(string name, int age) : m_Name(name), m_Age(age) {}
};

int main()
{
    vector<User> users;
    users.resize(10);

    fill(users.begin(), users.end(), User("aaa", 18));

    // vector<User> users(10, User("aaa", 18));

    cout << "生成 " << users.size() << " 个用户" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        cout << "第 " << i + 1 << " 个用户 - 姓名: " << users[i].m_Name << ", 年龄: " << users[i].m_Age << endl;
    }

    return 0;
}