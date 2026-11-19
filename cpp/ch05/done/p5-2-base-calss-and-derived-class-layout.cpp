#include <iostream>
using namespace std;

class BaseClass
{
	int v1,v2;
	char v4;
public:
	int temp1(){}
};
class DerivedClass : public BaseClass
{
private:
	int v3;
	//32位系统中指针占4字节
	int *p;
public:
	int temp(){}
};

int main()
{
	//程序5-2，基类及子类占用空间及字节对齐
	cout<<"Base="<<sizeof(BaseClass)<<endl;
	cout<<"Derived="<<sizeof(DerivedClass)<<endl;
	int *pp=new int(1);
	cout<<"*pp="<<sizeof(pp)<<endl;
	delete pp;

	return 0;
}