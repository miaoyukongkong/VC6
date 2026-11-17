#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class myComplex
{
private:
	double real,imag;
public:
	myComplex():real(0),imag(0){}
	myComplex(double r,double i):real(r),imag(i){}
	//强制类型转换运算符重载为成员函数	
	operator double()
	{
		return real;
	}
};

int main()
{
	//程序4-7，强制类型转换运算符重载为成员函数
	myComplex c(1.2,-3.4);
	cout<<double(c)<<endl;
	double m=12+c;
	cout<<m<<endl;
	double n=12+c.operator double();
	cout<<n<<endl;

	return 0;
}