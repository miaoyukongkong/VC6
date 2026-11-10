#include <iostream>
using namespace std;
class Test
{
	int x,y;
public:
	fun(int i,int j)
	{
		x=i;
		y=j;
	}
	show()
	{
		cout<<"x="<<x;
		if(y>0) cout<<",y="<<y;
		cout<<endl;
	}
};
int main()
{
	//Ï°Ìâ3.2£¬Êä³ö1-10-2
	Test a;
	a.fun(1,10);
	a.show();
	a.fun(2,0);
	a.show();

	return 0;
}