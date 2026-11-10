#include "Student.h"
#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//程序2-3，验证类功能的驱动程序
	Student ss;
	int y,m,d;
	string name_;
	cout<<"请输入学生的姓名和生日，生日以\"年 月 日\"的次序输入：";
	cin>>name_>>y>>m>>d;
	ss.setStudent(name_,myDate(y,m,d));
	ss.printStudent();

	return 0;
}