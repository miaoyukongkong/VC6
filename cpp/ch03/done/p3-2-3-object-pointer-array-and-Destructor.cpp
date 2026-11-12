#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-2-3，对象指针数组与析构函数
	//myDate 构造函数
	//Student 构造函数
	//myDate 构造函数
	//Student 构造函数
	//Student 析构函数
	//myDate 析构函数
	//Student 析构函数
	//myDate 析构函数
	Student *ss[2]={new Student(),new Student()};
	delete ss[0];
	delete ss[1];

	return 0;
}