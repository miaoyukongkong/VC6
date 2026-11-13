#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class constClass
{
	const int conMbr;
	int Mbr;
public:
	//初始化列表处给出初值
	constClass():conMbr(0),Mbr(100){}
	//初始化列表处给出初值
	constClass(int i):conMbr(i)
	{
		Mbr=200;
	}
	void printConst()
	{
		cout<<"conMbr="<<conMbr<<",Mbr="<<Mbr<<endl;
	}
	int getConst()
	{
		cout<<"调用非常量函数"<<endl;
		return conMbr;
	}
	int getConst() const
	{
		cout<<"调用常量函数"<<endl;
		return conMbr;
	}
	int getValue()
	{
		return Mbr;
	}
	void processConst()
	{
		cout<<"-- 在processConst函数中 非常量 --"<<endl;
		int x=2*conMbr+1;
		//可以读取conMbr
		cout<<"x=2*conMbr+1="<<x<<endl;
		//错误！不能更改常量成员变量conMbr的值
		//conMbr++;
		Mbr++;
		cout<<"Mbr="<<Mbr<<endl;
	}
	void processConst() const
	{
		cout<<"-- 在processConst函数中 常量 --"<<endl;
		int x=conMbr+1;
		//可以读取conMbr
		cout<<"x=conMbr+1="<<x<<endl;
		//错误！不能更改常量成员变量conMbr的值
		//conMbr++;
		//错误！常量函数中不可以修改成员变量的值
		//Mbr++;
		cout<<"Mbr="<<Mbr<<endl;
	}
};
int main()
{
	//程序3-9，常量成员变量和常量成员函数的使用
	constClass ob1(123),ob2;
	ob1.printConst();
	cout<<"ob2.getConst()="<<ob2.getConst()<<endl;
	ob2.processConst();
	const constClass ob3(20);
	cout<<"ob3.getConst()="<<ob3.getConst()<<endl;
	ob3.processConst();

	return 0;
}