#include <iostream>
#include <string>
using namespace std;

class myComplex
{
public:
	int real,imag;
	myComplex(int r=0,int i=0):real(r),imag(i){}
};
myComplex operator+(myComplex &a,myComplex &b)
{
	int r=a.real+b.real;
	int i=a.imag+b.imag;
	return myComplex(r,i);
}
int main()
{
	//Ï°Ìâ4-3.2£¬ÖØÔØÔËËã·û+
	myComplex x(1,2),y(3,4),z;
	z=x+y;
	cout<<z.real<<"+"<<z.imag<<"i"<<endl;

	return 0;
}