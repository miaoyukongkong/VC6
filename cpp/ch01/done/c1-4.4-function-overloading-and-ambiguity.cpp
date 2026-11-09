#include <iostream>
using namespace std;
int bigger(int x,int y)
{
	if(x>y) return x;
	else return y;
}
float bigger(float x,float y)
{
	if(x>y) return x;
	else return y;
}
double bigger(int x,float y)
{
	if(x>y) return (double)x;
	else return (double)y;
}

int main()
{
	//习题1-4.4，函数重载和二义性
	int xI=10,yI=20;
	float xF=30,yF=40;
	double xD=50,yD=60;
	cout<<bigger(xI,yF)<<endl;

	return 0;
}
