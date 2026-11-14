#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Point
{
private:
	double x,y;
public:
	//构造函数
	Point():x(0.0),y(0.0){}
	//构造函数
	Point(double xx,double yy)
	{
		x=xx;
		y=yy;
	}
	//复制构造函数
	Point(Point &p)
	{
		x=p.x;
		y=p.y;
	}
	//析构函数
	~Point()
	{
		cout<<"Point---Destructor"<<endl;
	}
	void printPoint() const
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};

int main()
{
	//习题3-5.1，类Point
	Point p0;
	Point p1(2,3);
	Point p2(p0);
	p0.printPoint();
	p1.printPoint();
	p2.printPoint();

	return 0;
}