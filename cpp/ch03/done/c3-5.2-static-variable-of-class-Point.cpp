#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Point
{
private:
	double x,y;
	//所有Point对象共享这个计数器
	static int count;
public:
	//构造函数
	Point():x(0.0),y(0.0){count++;}
	//构造函数
	Point(double xx,double yy)
	{
		x=xx;
		y=yy;
		count++;
	}
	//复制构造函数
	Point(Point &p)
	{
		x=p.x;
		y=p.y;
		//通过复制创建的对象，同样算作一个新对象
		count++;
	}
	//析构函数
	~Point()
	{
		cout<<"Point---Destructor"<<endl;
		//对象销毁时，个数减1
		count--;
		cout<<"count:"<<count<<endl;
	}
	void printPoint() const
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	static int getCount()
	{
		return count;
	}
};
//静态变量初始化
int Point::count=0;
int main()
{
	//习题3-5.2，类Point的静态变量
	cout << "初始点数: " << Point::getCount() << endl; // 输出 0
	Point p0;
	Point p1(2,3);
	Point p2(p0);
	cout << "创建3个对象后的点数: " << Point::getCount() << endl; // 输出 3

	p0.printPoint();
	p1.printPoint();
	p2.printPoint();

	return 0;
}