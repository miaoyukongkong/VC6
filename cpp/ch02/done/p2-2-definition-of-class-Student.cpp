//程序2-2，定义学生类Student
#include "myDate.h"
#include <string>
class Student
{
public:
	//设置学生信息
	void setStudent(string,myDate);
	//设置姓名
	void setName(string);
	//获取姓名
	string getName();
	//设置生日
	void setBirthday(myDate);
	//获取生日
	myDate getBirthday();
	//打印信息
	void printStudent() const;
private:
	//姓名
	string name;
	//生日
	myDate birthday;
};
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
	cont<<endl;
	return;
}