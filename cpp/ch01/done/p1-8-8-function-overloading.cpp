#include <iostream>
using namespace std;

int bigger(int x,float y)
{
	if(x>y) return x;
	return y;
}

float bigger(float x,float y)
{
	if(x>y) return x;
	return y;
}

double bigger(double x,double y)
{
	if(x>y) return x;
	return y;
}

int main()
{
	//程序1-8-8，重载函数
	int xI=10,yI=20;
	float xF=30,yF=40;
	double xB=50,yB=60;
	cout<<bigger(xI,yI)<<endl;
	cout<<bigger(xF,yF)<<endl;
	cout<<bigger(xB,yB)<<endl;
	//进行类型转换时，调用重载函数的二义性
	cout<<bigger(xI,yF)<<endl;

	return 0;
}