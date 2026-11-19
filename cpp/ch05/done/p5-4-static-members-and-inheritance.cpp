#include <iostream>
using namespace std;

class Base
{
private:
	float x;
public:
	static int staV;
	Base(){
		staV++;
		cout<<"Base Constructor"<<endl;
	}
};
int Base::staV=0;
class Derived : public Base
{
private:
	float y;
public:
	Derived(){
		staV++;
	cout<<"Derived Constructor"<<endl;
	}
};

int main()
{
	//程序5-4，派生关系中的静态成员
	Base a;
	//1
	cout<<a.staV<<endl;
	Derived d;
	//3
	cout<<d.staV<<endl;

	return 0;
}