#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Point.h"
using namespace std;
//浮点数比较的误差容忍度
#define EPS 1e-9
class MyLine
{
private:
	double A;
	double B;
	double C;
	
public:
	//构造函数1：通过系数构造一般式Ax+By+C=0
	MyLine(double a,double b,double c): A(a),B(b),C(c)
	{
		if(abs(A)<EPS && abs(B)<EPS)
		{
			throw invalid_argument("A和B不能同时为0！");
		}
	}

	//构造函数2：通过两点构造直线
	MyLine(Point p1,Point p2)
	{
		if(p1.distanceBetween(p1,p2)<EPS)
		{
			throw invalid_argument("两点不能重合，无法确定一条直线！");
		}
		A=p2.getY()-p1.getY();
		B=p1.getX()-p2.getX();
		C=p2.getX()*p1.getY()-p1.getX()*p2.getY();
	}

	//求直线斜率
	double getSlope() const
	{
		if(abs(B)<EPS)
		{
			throw runtime_error("直线垂直于x轴，斜率不存在（无穷大）！");
		}
		return -A/B;
	}

	//判断点是否在直线上
	bool isPointOnLine(Point p) const
	{
		return abs(A*p.getX()+B*p.getY()+C)<EPS;
	}

	//求点到直线的距离
	double distanceToPoint(Point p) const
	{
		double numerator=abs(A*p.getX()+B*p.getY()+C);
		double denominator=sqrt(A*A+B*B);
		return numerator/denominator;
	}

	void display() const
	{
		cout<<A<<"x+"<<B<<"y+"<<C<<"=0";
	}
};

int main() {
	//习题5.3，设计并实现类MyLine
	Point p1(0,0);
	Point p2(2,2);
	Point p3(1,1);
	Point p4(0,2);
	//直线y=x
	MyLine line1(p1,p2);
	//直线y=-x
	MyLine line2(1,1,0);

	try
	{
		cout<<"直线";
		line1.display();
		cout<<"的斜率："<<line1.getSlope()<<endl;
	} catch(exception e)
	{
		cout<<e.what()<<endl;
	}

	cout<<"点(1,1)是否在直线";
	line1.display();
	cout<<"上："<<(line1.isPointOnLine(p3) ? "Yes" : "No")<<endl;

	cout<<"点(0,2)到直线";
	line2.display();
	cout<<"的距离为："<<line2.distanceToPoint(p4)<<endl;

    return 0;
}
