#include <iostream>
using namespace std;

int main()
{
	//习题1-4.2，引用和指针
	int oneInt=1;
	int & ref=oneInt;
	ref=2;
	cout<<"oneInt="<<oneInt<<",ref="<<ref<<endl;

	int *p=&ref;
	*p=3;
	cout<<"ref="<<ref<<",p的地址："<<p<<",p的值："<<*p<<endl;

	return 0;
}