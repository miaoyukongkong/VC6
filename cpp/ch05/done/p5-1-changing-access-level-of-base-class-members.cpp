#include <iostream>
using namespace std;

class BaseClass
{
public:
	int v1,v2;
	BaseClass():v1(1),v2(1){}
	int temp1(){}
};
class DerivedClass : public BaseClass
{
private:
	//改为私有访问权限
	int v1;
	int temp1(){}
public:
	DerivedClass():v1(10){}
	void print()
	{
		cout<<"v1="<<v1<<endl;
		cout<<"Base.v1="<<BaseClass::v1<<endl;
	}
};

int main()
{
	//程序5-1，派生类改变基类成员的访问权限
	BaseClass bc;
	DerivedClass dc;
	dc.print();

	return 0;
}