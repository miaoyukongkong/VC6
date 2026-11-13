#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//前向引用声明
class Pixel;
class Test
{
public:
	//用到了类Pixel
	void printX(Pixel p);
};
class Pixel
{
private:
	int x,y;
public:
	Pixel(int x0,int y0)
	{
		x=x0;
		y=y0;
	}
	void printxy()
	{
		cout<<"pixel:("<<x<<","<<y<<")"<<endl;
	}
	//友元函数（原型），全局函数
	friend double getDist(Pixel p1,Pixel p2);
	//友元函数，类Test的成员函数
	friend void Test::printX(Pixel p);
};
void Test::printX(Pixel p)
{
	cout<<"x="<<p.x<<"\ty="<<p.y<<endl;
	return;
}
double getDist(Pixel p1,Pixel p2)
{
	double xd=double(p1.x-p2.x);
	double yd=double(p1.y-p2.y);
	return sqrt(xd*xd+yd*yd);
}
int main()
{
	//程序3-14，友元函数的声明
	Pixel p1(0,0),p2(10,10);
	p1.printxy();
	p2.printxy();
	//直接调用全局函数
	cout<<"(p1,p2)间距离="<<getDist(p1,p2)<<endl;
	Test t;
	cout<<"从友元函数中输出 --"<<endl;
	//通过对象调用类的成员函数
	t.printX(p1);
	t.printX(p2);

	return 0;
}