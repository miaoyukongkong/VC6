#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Location
{
public:
	int x,y;
	void init(int initx,int inity);
	int Getx();
	int Gety();
};
void Location::init(int initx,int inity)
{
	x=initx;
	y=inity;
}
int Location::Getx()
{
	return x;
}
int Location::Gety()
{
	return y;
}
void display(Location &rL)
{
	cout<<rL.Getx()<<" "<<rL.Gety()<<endl;
}
int main()
{
	//习题3-4.4，对象数组
	Location A[5]={{5,5},{3,3},{1,1},{2,2},{4,4}};
	Location *rA=A;
	A[3].init(7,3);
	rA->init(7,8);
	for(int k=0;k<5;k++) display(*(rA++));

	return 0;
}