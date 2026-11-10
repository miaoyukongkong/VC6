#include <iostream>
#include <string>
using namespace std;
int main()
{
	//程序2-8，作用域隐藏规则
	int a=1;
	//输出1
	cout<<a<<endl;
	for(int i=1;i<2;i++)
	{
		int a=2;
		//输出2
		cout<<a<<endl;
	}
	//输出1
	cout<<a<<endl;
	for(int j=1;j<2;j++)
	{
		a=3;
		//输出3
		cout<<a<<endl;
	}
	//输出3
	cout<<a<<endl;
	return 0;
}