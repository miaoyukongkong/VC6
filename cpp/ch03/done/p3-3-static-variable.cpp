#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
//静态全局变量glos
static int glos=100;
void f()
{
	//局部变量a
	int a=1;
	//静态局部变量fs
	static int fs=1;
	cout<<"在f中：a（自动）="<<a<<",fs（静态）="<<fs<<
		",glos（静态）="<<glos<<endl;
	a+=2;
	fs+=2;
	glos+=10;
	cout<<"在f中：a（自动）="<<a<<",fs（静态）="<<fs<<
		",glos（静态）="<<glos<<endl;
}

int main()
{
	//程序3-3，静态变量
	//静态局部变量ms
	static int ms=10;
	for(int i=0;i<3;i++) f();
	cout<<"ms="<<ms<<endl;
	cout<<"glos="<<glos<<endl;

	return 0;
}