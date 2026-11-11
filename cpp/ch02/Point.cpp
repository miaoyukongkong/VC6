#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

//构造函数
Point::Point(double xVal=0.0,double yVal=0.0)
	:x(xVal),y(yVal) {}
void Point::setX(double xVal){x=xVal;}
void Point::setY(double yVal){y=yVal;}
double Point::getX() const{return x;}
double Point::getY() const{return y;}

//计算给定点到原点（0，0）的距离
double Point::distanceToOrigin() const
{
	return sqrt(x*x+y*y);
}

//计算给定两点间的距离
double Point::distanceBetween(Point p1,Point p2) const
{
	double deltaX=p1.getX()-p2.getX();
	double deltaY=p1.getY()-p2.getY();
	return sqrt(deltaX*deltaX+deltaY*deltaY);
}

//判断给定的3个点能否构成一个三角形
bool Point::canFormTriangle(Point p1,Point p2,Point p3) const
{
	double a=distanceBetween(p1,p2);
	double b=distanceBetween(p1,p3);
	double c=distanceBetween(p2,p3);

	//引入极小误差值
	const double EPS=1e-6;

	return (a+b-c>EPS) && (a+c-b>EPS) && (b+c-a>EPS);
}

//辅助打印函数
void Point::display() const
{
	cout<<"("<<x<<","<<y<<")";
}