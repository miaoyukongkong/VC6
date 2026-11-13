#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class A
{
private:
	int a,b;
public:
	A(int x=0,int y=0):a(x),b(y){}
	void print() const
	{
		cout<<a<<","<<b<<endl;
	}
};

int main()
{
	//习题3-3.6，构造函数
	A *p;
	p=new A(4,5);
	p->print();
	delete p;

	return 0;
}