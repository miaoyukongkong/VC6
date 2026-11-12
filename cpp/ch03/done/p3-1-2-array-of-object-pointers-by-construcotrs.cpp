#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-1-2，使用构造函数生成对象指针数组
	Student stud;
	stud.printStudent();
	stud.setName("111");
	stud.printStudent();

	Student *spointer[2]={new Student(),&stud};
	Student sy[2]={Student(),stud};

	for(int i=0;i<2;i++)
		spointer[i]->printStudent();
	
	for(i=0;i<2;i++)
		sy[i].printStudent();

	stud.setName("222");
	for(i=0;i<2;i++)
		spointer[i]->printStudent();

	spointer[0]->setName("333");
	spointer[1]->setName("444");
	for(i=0;i<2;i++)
		spointer[i]->printStudent();

	stud.printStudent();
	for(i=0;i<2;i++)
		sy[i].printStudent();

	return 0;
}