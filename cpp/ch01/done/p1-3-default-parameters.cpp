#include <iostream>
using namespace std;

//为参数abc分别设置默认值
void func(int a=11, int b=22, int c=33)
{
	cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
}

int main()
{
	// 程序1-3，定义带默认值的函数
	func();
	func(55);
	func(77,99);
	func(8,88,888);

	return 0;
}
