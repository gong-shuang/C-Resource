//
// Created by gongshuang on 2026/6/25.
//

#ifndef C_RESOURCE_PERSON_H
#define C_RESOURCE_PERSON_H


using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);

    void showPerson();

    T1 m_Name;
    T2 m_Age;
};

#endif //C_RESOURCE_PERSON_H
