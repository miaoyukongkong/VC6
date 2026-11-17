#include <iostream>
#include <string>
using namespace std;

class myComplex
{
private:
	double real,imag;
public:
	myComplex();
	myComplex(double r,double i);
	~myComplex(){}
	myComplex addCom(myComplex c1);
	void outCom();
	void outCom(string s);
	void changeReal(double r);
	//c1+c2
	friend myComplex operator+(const myComplex &c1,const myComplex &c2);
	//c1+r
	friend myComplex operator+(const myComplex &c1,double r);
	//r+c1
	friend myComplex operator+(double r,const myComplex &c1);
	//c1-c2
	friend myComplex operator-(const myComplex &c1,const myComplex &c2);
	//c1-r
	friend myComplex operator-(const myComplex &c1,double r);
	//r-c1
	friend myComplex operator-(double r,const myComplex &c1);
	myComplex & operator=(const myComplex & c);
	myComplex & operator=(double r);
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
myComplex myComplex::addCom(myComplex c1)
{
	return myComplex(real+c1.real,imag+c1.imag);
}
void myComplex::outCom()
{
	cout<<"("<<real<<","<<imag<<")";
}
void myComplex::outCom(string s)
{
	cout<<s<<"=("<<real<<","<<imag<<")"<<endl;
}
void myComplex::changeReal(double r)
{
	real=r;
}
myComplex operator+(const myComplex &c1,const myComplex &c2)
{
	return myComplex(c1.real+c2.real,c1.imag+c2.imag);
}
myComplex operator+(const myComplex &c1,double r)
{
	return myComplex(c1.real+r,c1.imag);
}
myComplex operator+(double r,const myComplex &c1)
{
	return myComplex(r+c1.real,c1.imag);
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
myComplex &myComplex::operator =(const myComplex &c1)
{
	real=c1.real;
	imag=c1.imag;
	return *this;
}
myComplex &myComplex::operator =(double r)
{
	real=r;
	imag=0;
	return *this;
}

int main()
{
	//程序4-2，重载赋值运算符
	myComplex c1(1,2),c2(3,4),res;
	c1.outCom("\t\t\tc1");
	c2.outCom("\t\t\tc2");
	res=c1+c2;
	res.outCom("执行res=c1+c2→\tres");

	res=c1.addCom(c2);
	res.outCom("执行res=c1.addCom(c2)→\tres");

	res=c1+5;
	res.outCom("执行res=c1+5→\tres");

	res=5+c1;
	res.outCom("执行res=5+c1→\tres");

	res=c1;
	c1.outCom("\t\t\tc1");
	res.outCom("执行res=c1→\tres");

	c1.changeReal(-3);
	c1.outCom("执行c1.changeReal(-3)→\tc1");

	res.outCom("\t\t\tres");
	res=c1;
	res.outCom("执行res=c1→\tres");

	res=7;
	res.outCom("执行res=7→\tres");

	res=7+8;
	res.outCom("执行res=(7+8)→\tres");

	res=c1=c2;
	c1.outCom("\t\t\tc1");
	c2.outCom("\t\t\tc2");
	res.outCom("执行res=c1=c2→\tres");

	return 0;
}