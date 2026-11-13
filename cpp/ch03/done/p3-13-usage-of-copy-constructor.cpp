#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

class A{
public:
	A()
	{
		cout<<"default"<<endl;
	}
	A(A &a)
	{
		cout<<"copy"<<endl;
	}
};
class B
{
	A a;
};
int main()
{
	//程序3-13，复制构造函数的使用
	//default
	//copy
	B b1,b2(b1);
	return 0;
}