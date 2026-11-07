#include <iostream>
using namespace std;

int main()
{
	// 程序1-4，引用的定义与使用
	int oneInt=1;
	//引用
	int & ref=oneInt;
	//常引用
	const int & refc=oneInt;

	//修改引用可以同时修改变量的值
	ref=2;
	cout<<"oneInt="<<oneInt<<","<<"ref="<<ref<<endl;
	cout<<"refc="<<refc<<endl;

	//修改变量同时也修改了引用和常引用的值
	oneInt=3;
	cout<<"ref="<<ref<<endl;
	cout<<"refc="<<refc<<endl;
	//同一个变量可以有多个引用
	int & ref2 = oneInt;
	cout<<"ref2="<<ref2<<endl;
	//refc=5;错误，不能使用常引用对变量进行修改

	return 0;
}
