#include "myDate.h"
#include <iostream>
using namespace std;

myDate::myDate()
{
	year=1970;
	month=1;
	day=1;
	cout<<"myDate 构造函数"<<endl;
}
myDate::myDate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}
//自定义析构函数
myDate::~myDate()
{
	cout<<"myDate 析构函数"<<endl;
}
void myDate::setDate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
	return;
}
void myDate::setDate(myDate oneD)
{
	year=oneD.year;
	month=oneD.month;
	day=oneD.day;
	return;
}
myDate myDate::getDate()
{
	return *this;
}
void myDate::setYear(int y)
{
	year=y;
	return;
}
int myDate::getMonth()
{
	return month;
}
void myDate::printDate() const
{
	cout<<year<<"/"<<month<<"/"<<day;
	return;
}