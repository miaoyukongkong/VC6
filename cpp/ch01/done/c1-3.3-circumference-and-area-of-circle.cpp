#include <iostream>
using namespace std;
const double pi=3.14159;
int main()
{
	//习题1-3.3，计算圆的周长和面积
	double r;
	cout<<"输入r：";
	cin>>r;
	double l=2.0*pi*r;
	double s=pi*r*r;
	cout<<"\n 周长是："<<l<<endl;
	cout<<"面积是："<<s<<endl;

	return 0;
}