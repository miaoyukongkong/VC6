#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-1-3，自定义复制构造函数
	Student stud;
	stud.setName("111");
	stud.printStudent();
	Student sy[2]={Student(),stud};
	stud.setName("222");
	stud.printStudent();
	//调用复制构造函数
	sy[1]=Student(stud);
	for(int i=0;i<2;i++)
		sy[i].printStudent();

	return 0;
}