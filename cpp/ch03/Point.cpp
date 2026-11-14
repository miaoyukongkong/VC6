#include <iostream>
#include "Point.h"
using namespace std;

Point::Point():x(0.0),y(0.0){count++;}

Point::Point(double xx,double yy)
{
	x=xx;
	y=yy;
	count++;
}

Point::Point(Point &p)
{
	x=p.x;
	y=p.y;
	//通过复制创建的对象，同样算作一个新对象
	count++;
}

Point::~Point()
{
	cout<<"Point---Destructor"<<endl;
	//对象销毁时，个数减1
	count--;
	cout<<"count:"<<count<<endl;
}

void Point::printPoint() const
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}

int Point::getCount()
{
	return count;
}

//静态变量初始化
int Point::count=0;