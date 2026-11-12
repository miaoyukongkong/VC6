#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-2-2，对象数组与析构函数
	//myDate 构造函数
	//Student 构造函数
	//myDate 构造函数
	//Student 构造函数
	//Student 析构函数
	//myDate 析构函数
	//Student 析构函数
	//myDate 析构函数
	Student *ss=new Student[2];
	delete [] ss;

	return 0;
}