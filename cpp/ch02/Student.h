#pragma once
#include "myDate.h"
#include <string>
using namespace std;

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