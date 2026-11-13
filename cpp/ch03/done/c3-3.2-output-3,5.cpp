#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class point
{
private:
	float x,y;
public:
	f1(float a,float b)
	{
		x=a;
		y=b;
	}
	point()
	{
		x=0;
		y=0;
	}
	void getx()
	{
		cout<<x<<endl;
	}
	void gety()
	{
		cout<<y<<endl;
	}
	friend void print(point a);
};
void print(point a)
{
	cout<<a.x<<","<<a.y<<endl;
}
int main()
{
	//Ï°Ìâ3-3.2£¬Êä³ö3,5
	point a;
	a.f1(3.0,5.0);
	print(a);

	return 0;
}