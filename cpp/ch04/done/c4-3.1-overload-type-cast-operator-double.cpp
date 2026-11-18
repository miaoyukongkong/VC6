#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class myComplex
{
private:
	double real,imag;
public:
	myComplex(double r=0,double i=0):real(r),imag(i){}
	operator double();
};
myComplex::operator double()
{
	return real;
}
int main()
{
	//习题4-3.1，重载强制类型转换运算符double
	myComplex c(1.2,-3.4);
	cout<<(double)c<<endl;
	double n=12+c;
	cout<<n;

	return 0;
}