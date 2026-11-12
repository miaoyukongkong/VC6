#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
//文件作用域
int x=11;
char ch='1';
//ipara1仅具有函数原型作用域
void fun1(int ipara1);
void fun2()
{
	//函数级i，和fun1中的i重名但是不相干
	int i=22222;
	//函数级ch，和文件级ch同名
	double ch=202.2;
	cout<<"在fun2中，--x="<<x<<",\tch="<<ch<<",\ti="<<i<<endl;
}
int main()
{
	//程序3-6，变量生存期和作用域1
	cout<<"在main中，--x="<<x<<",\tch="<<ch<<endl;
	fun1(x);
	fun2();

	return 0;
}
void fun1(int ii)
{
	//函数级i，和fun2中的i重名但是不相干
	int i=21111;
	int x=201;
	cout<<"在fun1中，--ii="<<ii<<",\tx="<<x<<",\tch="<<ch<<",\ti="<<i<<endl;
}