#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//程序2-5，使用引用方式的驱动程序
	Student ss;
	int y,m,d;
	string name_;
	//ss的别名sy
	Student &sy=ss;
	
	cout<<"请输入学生的姓名和生日，生日以\"年 月 日\"的次序输入：";
	cin>>name_>>y>>m>>d;
	sy.setStudent(name_,myDate(y,m,d));
	sy.printStudent();

	return 0;
}