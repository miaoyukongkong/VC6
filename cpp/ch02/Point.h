#pragma once

class Point
{
private:
	double x,y;
public:
	//构造函数
	Point(double xVal,double yVal);
	void setX(double xVal);
	void setY(double yVal);
	double getX() const;
	double getY() const;

	//计算给定点到原点（0，0）的距离
	double distanceToOrigin() const;

	//计算给定两点间的距离
	double distanceBetween(Point p1,Point p2) const;

	//判断给定的3个点能否构成一个三角形
	bool canFormTriangle(Point p1,Point p2,Point p3) const;

	//辅助打印函数
	void display() const;
};