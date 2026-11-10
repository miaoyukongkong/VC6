#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//程序2-4，使用指针方式的驱动程序
	Student ss;
	int y,m,d;
	string name_;
	//指向ss的指针sp
	Student *sp=&ss;
	
	cout<<"请输入学生的姓名和生日，生日以\"年 月 日\"的次序输入：";
	cin>>name_>>y>>m>>d;
	sp->setStudent(name_,myDate(y,m,d));
	sp->printStudent();

	return 0;
}