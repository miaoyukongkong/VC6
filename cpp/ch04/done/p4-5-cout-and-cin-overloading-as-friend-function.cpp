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
	//流插入运算符重载为友元函数
	friend ostream & operator<<(ostream & os,const myComplex & c);
	//流提取运算符重载为友元函数
	friend istream & operator>>(istream & is,myComplex & c);
};
ostream & operator<<(ostream & os,const myComplex & c)
{
	//以a+bi方式输出
	if(c.imag>=0)
		os<<c.real<<"+"<<c.imag<<"i";
	else
		os<<c.real<<"-"<<(-c.imag)<<"i";
	return os;
}
istream & operator>>(istream & is,myComplex & c)
{
	string s;
	//将a+bi作为字符串读入，a+bi之间不能有空格
	is>>s;
	//查找虚部
	int pos=s.find("+",0);
	//虚部为负数时，从第二个字符开始查找，避开实部为负数的情况
	if(pos==-1) pos=s.find("-",1);
	//分离出代表实部的字符串
	string sReal=s.substr(0,pos);
	//atof函数将字符串转为浮点数
	c.real=atof(sReal.c_str());
	//分离出代表虚部的字符串
	sReal=s.substr(pos,s.length()-pos-1);
	c.imag=atof(sReal.c_str());
	return is;
}
int main()
{
	//程序4-5，流插入运算符和流提取运算符重载为友元函数
	myComplex c,c1;
	int n;
	cout<<"请输入两个复数（[-]a+bi）和一个整数，以空格分隔"<<endl;
	cin>>c>>c1>>n;
	cout<<c<<","<<n<<","<<c1<<endl;

	return 0;
}