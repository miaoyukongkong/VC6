#include <iostream>
using namespace std;
#include <cmath>
int f(int);
int main()
{
	//Ï°Ìâ1-4.3£¬º¯Êı345
	int i;
	for(i=0;i<3;i++)
		cout<<f(i)<<endl;

	
}
int f(int a)
{
	int b=0,c=1;
	b++;c++;
	return int(a+pow(double(b),2)+c);
}