#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class base
{
private:
	int m;
public:
	base(){}
	base(int a):m(a){}
	int get()
	{
		return m;
	}
	void set(int a)
	{
		m=a;
	}
};

int main()
{
	//Ï°Ìâ3-4.1£¬Êä³ö1,9-50,30
	base *ptr=new base[2];
	ptr->set(30);
	ptr=ptr+1;
	ptr->set(50);
	base a[2]={1,9};
	cout<<a[0].get()<<","<<a[1].get()<<endl;
	cout<<ptr->get()<<",";
	ptr=ptr-1;
	cout<<ptr->get()<<endl;
	delete [] ptr;

	return 0;
}