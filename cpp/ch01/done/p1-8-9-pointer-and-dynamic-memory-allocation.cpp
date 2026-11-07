#include <iostream>
using namespace std;

int main()
{
	//程序1-8-9，指针和动态内存分配
	int *p=new int;
	*p=8;
	cout<<*p<<endl;
	delete p;
	p=0;

	int *q=new int[10];
	q[0]=10;
	q[9]=20;
	cout<<q[0]<<endl;
	cout<<q[9]<<endl;
	delete [] q;
	q=0;

	return 0;
}