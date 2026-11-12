#pragma once
#include <string>
#include "myDate.h"

class Student
{
public:
	//构造函数，无参数
	Student();
	//构造函数，1个参数
	Student(std::string);
	//自定义复制构造函数
	Student(const Student &s);
	//自定义析构函数
	~Student();
	void setStudent(std::string,myDate);
	void setStudent(std::string);
	void setName(std::string);
	std::string getName() const;
	void setBirthday(myDate);
	myDate getBirthday() const;
	void printStudent() const;
private:
	std::string name;
	myDate birthday;
};