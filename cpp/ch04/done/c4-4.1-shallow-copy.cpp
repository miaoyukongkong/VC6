#include <iostream>
#include <string>
using namespace std;

class pointer
{
public:
	int a;
	int *p;
	pointer()
	{
		a=100;
		p=new int(10);
	}
	pointer(const pointer &tempp)
	{
		if(this !=&tempp)
		{
			a=tempp.a;
			p=tempp.p;
		}
	}
};

int main()
{
	//œ∞Ã‚4-4.1£¨«≥øΩ±¥
	pointer p1;
	pointer p2(p1);
	cout<<p1.a<<",\t"<<*p1.p<<",\t"<<(p1.p==p2.p)<<endl;
	*p1.p=20;
	p2.a=300;
	cout<<(p1.a==p2.a)<<",\t"<<*p1.p<<",\t"<<(p1.p==p2.p)<<endl;

	return 0;
}