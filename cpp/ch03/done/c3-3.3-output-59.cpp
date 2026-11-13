#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Aton
{
public:
	int X,Y;
	int zx,zy;
	void init(int i,int j)
	{
		zx=i;
		zy=j;
	}
	Aton(int i,int j,int n=0,int m=0)
	{
		X=i;
		Y=j;
		zx=m;
		zy=n;
	}
};

int main()
{
	//Ï°Ìâ3-3.3£¬Êä³ö59
	Aton A(25,20,3,5);
	A.init(5,9);
	cout<<A.zx<<A.zy<<endl;

	return 0;
}