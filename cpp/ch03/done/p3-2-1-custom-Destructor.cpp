#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-2-1，自定义析构函数
	//myDate 构造函数
	//Student 构造函数
	//Student 析构函数
	//myDate 析构函数
	Student *stud=new Student();
	delete stud;

	return 0;
}