#include <iostream>
using namespace std;

int main()
{
	// 程序1-8，常量指针
	//普通变量，a1=5是正确的
	int a1=3;

	//常量数据，a2=5是错误的
	const int a2=a1;

	//普通指针指向普通变量，*a3=5是正确的
	int * a3=&a1;

	//常量数据，普通指针*a4=5是错误的
	const int * a4=&a1;

	//常量指针，不能修改指针，但*a5=5是正确的
	int * const a5=&a1;

	//常量数据，常量指针
	int const * const a6=&a1;

	//常量数据，常量指针
	const int * const a7=&a1;

	return 0;
}
