#include <iostream>
#include <string>
#include "myDate.h"
using namespace std;

class Student
{
public:
	//构造函数，无参数
	Student();
	//构造函数，1个参数
	Student(string);
	void setStudent(string,myDate);
	void setStudent(string);
	void setName(string);
	string getName() const;
	void setBirthday(myDate);
	myDate getBirthday() const;
	void printStudent() const;
private:
	string name;
	myDate birthday;
};
Student::Student():name("Noname"),birthday(myDate()){}
Student::Student(string n):name(n),birthday(myDate()){}
void Student::setStudent(string s,myDate d)
{
	name=s;
	birthday.setDate(d);
	return;
}
void Student::setStudent(string s)
{
	name=s;
	myDate d;
	birthday.setDate(d);
	return;
}
void Student::setName(string n)
{
	name=n;
	return;
}
string Student::getName() const
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
	cout<<"姓名："<<name<<"\t 生日：";
	//调用类myDate的成员函数
	birthday.printDate();
	cout<<endl;
	return;
}

int main()
{
	//程序3-1-1，类Student+两个构造函数
	Student stud;
	Student ss[2];
	int y,m,d,i;
	string name_;
	stud.printStudent();

	for(i=0;i<2;i++)
		ss[i].printStudent();
	for(i=0;i<2;i++)
	{
		cout<<"请输入学生的姓名和生日，生日以\"年 月 日\"的次序输入：";
		cin>>name_>>y>>m>>d;
		ss[i].setStudent(name_,myDate(y,m,d));
	}
	for(i=0;i<2;i++)
		ss[i].printStudent();

	return 0;
}