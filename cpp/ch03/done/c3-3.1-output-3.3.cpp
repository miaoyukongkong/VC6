#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class point
{
private:
	float x;
public:
	void f(float a)
	{
		x=a;
	}
	void f()
	{
		x=0;
	}
	friend float max(point &a,point &b);
};
float max(point &a,point &b)
{
	return (a.x>b.x) ? a.x : b.x;
}
int main()
{
	//Ï°Ìâ3-3.1£¬Êä³ö3.3
	point a,b;
	a.f(2.2);
	b.f(3.3);
	cout<<max(a,b)<<endl;

	return 0;
}