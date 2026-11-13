#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
int fvalue=10;
class CDemo
{
public:
	const int num;
	const int& ref;
	int value;
public:
	CDemo(int n):num(n),ref(value),value(4){}
};
int main()
{
	//程序3-10，常引用成员变量
	cout<<sizeof(CDemo)<<endl;
	CDemo f(100);
	//错误！不能修改常引用成员变量的值
	//f.ref=f.value;
	cout<<"f.num="<<f.num<<",f.ref="<<f.ref<<",f.value="<<f.value<<endl;

	return 0;
}