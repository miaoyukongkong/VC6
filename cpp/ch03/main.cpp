#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class Demo
{
	int id;
	string position;
public:
	//构造函数
	Demo(int i,string pos)
	{
		id=i;
		position=pos;
		cout<<"生成对象"<<this<<",id="<<id<<",position:"<<position<<endl;
	}
	//类型转换构造函数
	Demo(int i):position("temp")
	{
		id=i;
		cout<<"生成对象"<<this<<",id="<<id<<",position:"<<position<<endl;
	}
	//析构函数
	~Demo()
	{
		cout<<"消亡对象"<<this<<",id="<<id<<",position:"<<position<<endl;
	}
};
//类外定义，全局
Demo d1(1,"全局");
void Func()
{
	cout<<"enter func"<<endl;
	//函数内定义，静态局部
	static Demo d2(2,"函数Func内，静态");
	//函数内定义，局部
	Demo d3(3,"函数Func内");
	cout<<"exit func"<<endl;
}
int main()
{
	//程序3-7，类对象的生存期和作用域
	cout<<"enter main"<<endl;
	//主函数内定义
	Demo d4(4,"主函数内");
	d4=7;
	cout<<"enter block"<<endl;
	{
		//主函数块内定义
		Demo d5(5,"主函数块内");
	}
	cout<<"exit block"<<endl;
	//全局和静态对象遵循：后创建先销毁
	Func();
	//主函数内定义，静态
	static Demo d6(6,"主函数内，静态");		
	cout<<"exit main"<<endl;

	return 0;
}