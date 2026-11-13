#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class Sample
{
public:
	Sample();
	void getValue() const;
	void getValue();
	void priValue();
	void priVcon() const;
};
Sample::Sample(){}
void Sample::getValue() const
{
	cout<<"常量成员函数"<<endl;
}
void Sample::getValue()
{
	cout<<"非常量成员函数"<<endl;
}
void Sample::priValue()
{
	cout<<"非常量成员函数"<<endl;
}
void Sample::priVcon() const
{
	cout<<"常量成员函数"<<endl;
}
int main()
{
	//程序3-8，常量成员函数
	const Sample cono;
	Sample o;
	cout<<"cono\t";
	cono.getValue();
	//错误！常量对象不能调用非常量成员函数
	//cono.priValue();
	cout<<"o\t";
	o.getValue();
	cout<<"o\t";
	o.priValue();
	cout<<"o\t";
	o.priVcon();

	return 0;
}