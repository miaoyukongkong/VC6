#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class classA
{
public:
	double x,y;
	//公有静态成员变量
	static int num;
	classA()
	{
		x=0;
		y=0;
		//每生成一个对象，num加1
		num++;
	}
	classA(double x0,double y0)
	{
		x=x0;
		y=y0;
		num++;
	}
	//静态成员函数
	static void staticFun()
	{
		cout<<"current_num="<<num<<endl;
	}
};
//必须在类体外初始化静态成员变量
int classA::num=0;

int main()
{
	//程序3-4，静态成员
	//使用类名做限定符
	cout<<"classA::num="<<classA::num<<endl;
	classA::staticFun();
	cout<<endl;

	//调用1次构造函数
	classA obj(1.2,3.4),*p;
	//使用类名做限定符
	cout<<"classA::num="<<classA::num<<endl;
	classA::staticFun();
	//使用对象名做限定符
	cout<<"obj.num="<<obj.num<<endl;
	obj.staticFun();
	cout<<endl;

	//调用3次构造函数
	classA A[3];
	cout<<"classA::num="<<classA::num<<endl;
	classA::staticFun();
	cout<<endl;
	
	//调用1次构造函数
	p=new classA(5.6,7.8);
	cout<<"classA::num="<<classA::num<<endl;
	classA::staticFun();
	//使用对象指针做限定符
	cout<<"p->num="<<p->num<<endl;
	p->staticFun();
	cout<<endl;

	//sizeof运算符不计算静态成员
	cout<<"sizeof(obj)="<<sizeof(obj)<<endl;
	cout<<"sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(p)="<<sizeof(p)<<endl;

	return 0;
}