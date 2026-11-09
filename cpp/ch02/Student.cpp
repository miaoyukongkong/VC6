#include "Student.h"
#include "myDate.h"
#include <string>
#include <iostream>
using namespace std;

//在类体外定义成员函数
void Student::setStudent(string s,myDate d)
{
	name=s;
	birthday.setDate(d);
	return;
}
void Student::setName(string n)
{
	name=n;
	return;
}
string Student::getName()
{
	return name;
}
void Student::setBirthday(myDate d)
{
	birthday.setDate(d);
	return;
}
myDate Student::getBirthday()
{
	return birthday;
}
void Student::printStudent() const
{
	cout<<"姓名："<<name<<"\t 生日：";
	//调用类myDate的成员函数
	birthday.printDate();
	cout<<endl;
	return;
}