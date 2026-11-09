#include <iostream>
using namespace std;

int main()
{
	//Ï°Ìâ1-3.2£¬Êä³ö6
	const int x=5,y=6;
	const int * p=&x;
	p=&y;
	cout<<*p<<endl;

	return 0;
}