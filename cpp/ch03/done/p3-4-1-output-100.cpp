#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class Test
{
public:
	static int x;
	Test(int i=10)
	{
		x=i+x;
	}
	int Getnum()
	{
		return Test::x+7;
	}
};
//必须在类体外初始化静态成员变量
int Test::x=83;

int main()
{
	//程序3-4-1，输出100
	Test test;
	cout<<test.x<<endl;
	cout<<test.Getnum()<<endl;

	return 0;
}