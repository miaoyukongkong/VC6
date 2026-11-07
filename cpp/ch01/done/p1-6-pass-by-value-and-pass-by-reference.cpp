#include <iostream>
using namespace std;

//传值交换ab的值
void SwapValue(int a, int b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
	cout<<"在SwapValue()函数中：\t\ta="<<a<<",b="<<b<<endl;
	return;
}

//传引用交换ab的值
void SwapRef(int& a, int& b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
	cout<<"在SwapRef()函数中：\t\ta="<<a<<",b="<<b<<endl;
	return;
}

int main()
{
	// 程序1-6，不同的参数传递方式：传值和传引用
	int a=10,b=20;
	cout<<"数据交换前：\t\ta="<<a<<",b="<<b<<endl;
	SwapValue(a,b);
	cout<<"调用SwapValue()后：\t\ta="<<a<<",b="<<b<<endl;

	a=10;
	b=20;
	SwapRef(a,b);
	cout<<"调用SwapRef()后：\t\ta="<<a<<",b="<<b<<endl;

	return 0;
}
