#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class CDemo
{
private:
	int n;
public:
	CDemo(int i=0):n(i){}
	operator int() {return n;}
	//前置形式
	friend CDemo & operator++(CDemo &);
	//后置形式
	friend CDemo operator++(CDemo &,int);
	//前置形式
	friend CDemo & operator--(CDemo &);
	//后置形式
	friend CDemo operator--(CDemo &,int);
};
CDemo & operator++(CDemo & d)
{
	d.n++;
	return d;
}
CDemo operator++(CDemo & d,int k)
{
	//记录修改前的对象
	CDemo tmp(d);
	d.n++;
	//返回修改前的对象
	return tmp;
}
CDemo & operator--(CDemo & d)
{
	d.n--;
	return d;
}
CDemo operator--(CDemo & d,int k)
{
	//记录修改前的对象
	CDemo tmp(d);
	d.n--;
	//返回修改前的对象
	return tmp;
}
int main()
{
	//程序4-8，自增自减运算符重载为友元函数
	CDemo d(10);
	cout<<(d++)<<",";
	cout<<d<<endl;
	cout<<(++d)<<",";
	cout<<d<<endl;
	cout<<(d--)<<",";
	cout<<d<<endl;
	cout<<(--d)<<",";
	cout<<d<<endl;

	return 0;
}