//程序2-2，定义学生类Student
//2.3 类的初步知识：类声明放 .h，成员函数定义放 .cpp，main 只负责使用
#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//用带参构造函数造一个日期
	myDate oneD(1998,1,15);
	//定义学生对象
	Student oneS;
	//设置学生信息和生日
	oneS.setStudent("张三", oneD);
	//打印学生信息
	oneS.printStudent();
	//测试 getter
	cout<<"getName() = "<<oneS.getName()<<endl;

	return 0;
}