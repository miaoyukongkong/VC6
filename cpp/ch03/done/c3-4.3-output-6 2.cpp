#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class exa
{
private:
	int a;
public:
	exa(int b=5)
	{
		a=b++;
	}
	void print()
	{
		a=a+1;
		cout<<a<<" ";
	}
	void print() const
	{
		cout<<a<<endl;
	}
};

int main()
{
	//Ï°Ìâ3-4.3£¬Êä³ö6 2
	exa x;
	const exa y(2);
	x.print();
	y.print();

	return 0;
}