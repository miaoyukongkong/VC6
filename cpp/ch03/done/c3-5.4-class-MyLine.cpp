#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
using namespace std;
class MyLine
{
private:
	Point p1,p2;
public:
	MyLine(Point pa=Point(),Point pb=Point())
	{
		p1=pa;
		p2=pb;
	}
	MyLine(MyLine &line)
	{
		p1=line.p1;
		p2=line.p2;
	}
	~MyLine()
	{
		cout<<"MyLine---Destructor"<<endl;
	}
	void printLine() const
	{
		p1.printPoint();
		p2.printPoint();
	}
};

int main()
{
	//Ï°Ìâ3-5.4£¬ÀàMyLine
	Point p0;
	Point p1(2,3);
	Point p2(p0);

	MyLine l0;
	MyLine l1(p1,p2);
	MyLine l2(l0);
	l0.printLine();
	l1.printLine();
	l2.printLine();

	return 0;
}