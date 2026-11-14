#include <iostream>
using namespace std;
class myComplex
{
private:
	double real,imag;
public:
	myComplex();
	myComplex(double r,double i);
	void outCom();
	myComplex operator-(const myComplex &c);
	friend myComplex operator+(const myComplex &c1,const myComplex &c2);
	friend myComplex operator-(const myComplex &c1,const myComplex &c2);
	friend myComplex operator-(const myComplex &c1,double r);
	friend myComplex operator-(double r,const myComplex &c1);
};
myComplex::myComplex()
{
	real=0;
	imag=0;
}
myComplex::myComplex(double r,double i)
{
	real=r;
	imag=i;
}
void myComplex::outCom()
{
	cout<<"("<<real<<","<<imag<<")";
}
myComplex myComplex::operator-(const myComplex &c)
{
	return myComplex(real-c.real,imag-c.imag);
}
myComplex operator+(const myComplex &c1,const myComplex &c2)
{
	return myComplex(c1.real+c2.real,c1.imag+c2.imag);
}
myComplex operator-(const myComplex &c1,const myComplex &c2)
{
	return myComplex(c1.real-c2.real,c1.imag-c2.imag);
}
myComplex operator-(const myComplex &c1,double r)
{
	return myComplex(c1.real-r,c1.imag);
}
myComplex operator-(double r,const myComplex &c1)
{
	return myComplex(r-c1.real,-c1.imag);
}
int main()
{
	//程序4-1-1，重载为友元函数
	myComplex c1(1,2),c2(3,4),res;
	c1.outCom();
	cout<<"operator+";
	c2.outCom();
	cout<<"=";
	res=c1+c2;
	res.outCom();
	cout<<endl;

	c1.outCom();
	cout<<"operator-";
	c2.outCom();
	cout<<"=";
	res=c1-c2;
	res.outCom();
	cout<<endl;

	c1.outCom();
	cout<<"operator-";
	cout<<"  5";
	cout<<"=";
	res=c1-5;
	res.outCom();
	cout<<endl;

	cout<<"5  ";
	cout<<"operator-";
	c1.outCom();
	cout<<"=";
	res=5-c1;
	res.outCom();
	cout<<endl;

	return 0;
}