#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"

Student::Student():name("Noname"),birthday(myDate())
{
	std::cout<<"Student 构造函数"<<std::endl;
}
Student::Student(std::string n):name(n),birthday(myDate()){}
//自定义复制构造函数
Student::Student(const Student &s)
{
	name="COPY"+s.name;
	birthday=s.birthday;
}
//自定义析构函数
Student::~Student()
{
	std::cout<<"Student 析构函数"<<std::endl;
}
void Student::setStudent(std::string s,myDate d)
{
	name=s;
	birthday.setDate(d);
	return;
}
void Student::setStudent(std::string s)
{
	name=s;
	myDate d;
	birthday.setDate(d);
	return;
}
void Student::setName(std::string n)
{
	name=n;
	return;
}
std::string Student::getName() const
{
	return name;
}
void Student::setBirthday(myDate d)
{
	birthday.setDate(d);
	return;
}
myDate Student::getBirthday() const
{
	return birthday;
}
void Student::printStudent() const
{
	std::cout<<"姓名："<<name<<"\t 生日：";
	//调用类myDate的成员函数
	birthday.printDate();
	std::cout<<std::endl;
	return;
}