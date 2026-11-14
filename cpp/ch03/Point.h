#pragma once

class Point
{
private:
	double x,y;
	//所有Point对象共享这个计数器
	static int count;
public:
	//构造函数
	Point();
	//构造函数
	Point(double xx,double yy);
	//复制构造函数
	Point(Point &p);
	//析构函数
	~Point();
	void printPoint() const;
	static int getCount();
};