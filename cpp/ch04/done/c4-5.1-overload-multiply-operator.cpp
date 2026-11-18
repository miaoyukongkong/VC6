#include <iostream>
#include <string>
using namespace std;

class myComplex
{
public:
	double real,imag;
	myComplex(double r=0,double i=0):real(r),imag(i){}
	friend myComplex operator*(const myComplex & m,const myComplex & n)
	{
		double r=m.real*n.real-m.imag*n.imag;
		double i=m.imag*n.real+m.real*n.imag;
		return myComplex(r,i);
	}
};

int main()
{
	//习题4-5.1，重载乘法运算符
	myComplex c1(1,2),c2(3,4),res;
	res=c1*c2;
	cout<<res.real<<"+"<<res.imag<<"i"<<endl;

	return 0;
}