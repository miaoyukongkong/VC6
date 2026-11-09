#include <iostream>
using namespace std;

void func(int a,int b,int c=0)
{
	cout<<a<<b<<c<<endl;
}

int main()
{
	//Ï°Ìâ1-3.1£¬Êä³ö590
	func(5,9);

	return 0;
}