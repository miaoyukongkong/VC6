#include <iostream>
using namespace std;

class CB
{
public:
	int a;
	CB(int x){a=x;}
	void showa()
	{
		cout<<"Class CB -- a="<<a<<endl;
	}
};

class CD : public CB
{
public:
	//与基类a同名
	int a;
	//x用来初始化基类的成员变量a
	CD(int x,int y): CB(x)
	{
		a=y;
	}
	//与基类showa同名
	void showa()
	{
		cout<<"Class CD -- a="<<a<<endl;
	}
	void print2a()
	{
		cout<<"CD.a="<<a<<endl;
		cout<<"CB::a="<<CB::a<<endl;
	}
};

int main()
{
	//程序5-5，访问基类和派生类的同名成员
	CB CBobj(12);
	CBobj.showa();
	CD CDobj(48,999);
	CDobj.showa();
	CDobj.CB::showa();
	CDobj.print2a();

	return 0;
}