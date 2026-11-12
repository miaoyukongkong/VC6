#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

int main()
{
	//程序3-5，变量生存期和作用域1
	//函数作用域
	int i=10;
	//函数作用域
	char ch='1';
	cout<<"在main中，i="<<i<<",\tch="<<ch<<endl;
	{
		//外层块作用域
		int i=20;
		char ch='2';
		cout<<"在外层块，i="<<i<<",\tch="<<ch<<endl;
		if(i>0)
		{
			//内层块作用域
			double i=30.3;
			int ch=33;
			cout<<"在内层块，i="<<i<<",\tch="<<ch<<endl;
		}
		cout<<"在外层块，i="<<i<<",\tch="<<ch<<endl;
	}
	cout<<"在main中，i="<<i<<",\tch="<<ch<<endl;

	return 0;
}