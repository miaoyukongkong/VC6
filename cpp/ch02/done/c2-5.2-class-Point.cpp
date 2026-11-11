#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	double x,y;
public:
	//构造函数
	Point(double xVal=0.0,double yVal=0.0)
		:x(xVal),y(yVal) {}
	void setX(double xVal){x=xVal;}
	void setY(double yVal){y=yVal;}
	double getX() const{return x;}
	double getY() const{return y;}

	//计算给定点到原点（0，0）的距离
	double distanceToOrigin() const
	{
		return sqrt(x*x+y*y);
	}

	//计算给定两点间的距离
	double distanceBetween(Point p1,Point p2) const
	{
		double deltaX=p1.getX()-p2.getX();
		double deltaY=p1.getY()-p2.getY();
		return sqrt(deltaX*deltaX+deltaY*deltaY);
	}

	//判断给定的3个点能否构成一个三角形
	bool canFormTriangle(Point p1,Point p2,Point p3) const
	{
		double a=distanceBetween(p1,p2);
		double b=distanceBetween(p1,p3);
		double c=distanceBetween(p2,p3);

		//引入极小误差值
		const double EPS=1e-6;

		return (a+b-c>EPS) && (a+c-b>EPS) && (b+c-a>EPS);
	}

	//辅助打印函数
	void display() const
	{
		cout<<"("<<x<<","<<y<<")";
	}
};

int main() {
	//习题5.2，设计并实现类Point
	Point p1(0,0);
	Point p2(3,4);
	Point p3(6,8);
	Point p4(0,4);

	cout<<"点p2";
	p2.display();
	cout<<"到原点的距离为："<<p2.distanceToOrigin()<<endl;
    
	cout<<"点p2";
	p2.display();
	cout<<"到点p3";
	p3.display();
	cout<<"的距离为："<<p2.distanceBetween(p2,p3)<<endl;

	if(p2.canFormTriangle(p1,p2,p3))
	{
		cout<<"点p1";
		p1.display();
		cout<<",点p2";
		p2.display();
		cout<<"和点p3";
		p3.display();
		cout<<"可以构成三角形"<<endl;
	}
	else
	{
		cout<<"点p1";
		p1.display();
		cout<<",点p2";
		p2.display();
		cout<<"和点p3";
		p3.display();
		cout<<"不能构成三角形"<<endl;
	}

	if(p2.canFormTriangle(p1,p2,p4))
	{
		cout<<"点p1";
		p1.display();
		cout<<",点p2";
		p2.display();
		cout<<"和点p4";
		p4.display();
		cout<<"可以构成三角形"<<endl;
	}
	else
	{
		cout<<"点p1";
		p1.display();
		cout<<",点p2";
		p2.display();
		cout<<"和点p4";
		p4.display();
		cout<<"不能构成三角形"<<endl;
	}


    return 0;
}
