#include <iostream>
using namespace std;

int oneX=10;
int oneY=20;

//引用作为函数返回值
int & refValue(int & x)
{
	return x;
}

//指针作为函数返回值
int * pointValue(int * x)
{
	return x;
}

int main()
{
	// 程序1-7，引用函数和指针函数
	refValue(oneX)=30;
	cout<<"oneX="<<oneX<<endl;

	*pointValue(&oneY)=40;
	cout<<"oneY="<<oneY<<endl;

	return 0;
}
