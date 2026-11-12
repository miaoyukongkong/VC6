#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class Demo
{
	int id;
public:
	//类型转换构造函数
	Demo(int i)
	{
		id=i;
		cout<<"id="<<id<<"构造函数，对象地址："<<this<<endl;
	}
	void printDemo();
	//析构函数
	~Demo()
	{
		cout<<"id="<<id<<"析构函数，对象地址："<<this<<endl;
	}
};
void Demo::printDemo()
{
	cout<<"id="<<id<<"，当前对象地址："<<this<<endl;
}
int main()
{
	//程序3-2，类型转换构造函数
	Demo d4(4);
	d4.printDemo();
	//可以看作是将整型数6转为Demo对象
	d4=6;
	d4.printDemo();

	return 0;
}