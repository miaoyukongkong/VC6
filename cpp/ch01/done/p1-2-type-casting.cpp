#include <iostream>
using namespace std;
int main()
{
	// 程序1-2，强制类型转换示例
	int a=10;
	// 不能使用常量指针p修改a的值
	const int *p=&a;
	const int ca=30;
	int *q;

	cout<<"a的地址为：\t"<<&a<<"\ta的值为：\t"<<a<<endl;
	cout<<"*p指向的地址为："<<p<<"\t*p的值为：\t"<<*p<<endl;
	
	//去除p的常量性赋给q，如果写q=p;会报错
	q=const_cast<int *>(p);
	//如果写*p=20;是错误的
	*q=20;
	cout<<"a的地址为：\t"<<&a<<"\ta的值为：\t"<<a<<endl;
	cout<<"*p指向的地址为："<<p<<"\t*p的值为：\t"<<*p<<endl;
	cout<<"*q指向的地址为："<<q<<"\t*q的值为：\t"<<*q<<endl;
	cout<<"分界线"<<endl;

	//ca的值不能修改
	p=&ca;
	//去除p的常量性赋给q，如果写q=p;会报错
	q=const_cast<int * >(p);
	//如果写*p=40;是错误的
	*q=40;
	cout<<"ca的地址为：\t"<<&ca<<"\tca的值为：\t"<<ca<<endl;
	cout<<"*p指向的地址为："<<p<<"\t*p的值为：\t"<<*p<<endl;
	cout<<"*q指向的地址为："<<q<<"\t*q的值为：\t"<<*q<<endl;

	return 0;
}