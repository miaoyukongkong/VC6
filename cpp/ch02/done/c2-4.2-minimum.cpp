#include <iostream>
using namespace std;
class Test
{
	int a,b;
	int getmin()
	{
		return (a<b ? a : b);
	}
public:
	int c;
	void setValue(int x1,int x2,int x3)
	{
		a=x1;
		b=x2;
		c=x3;
	}
	int GetMin();
};
int Test::GetMin()
{
	int d=getmin();
	return (d = d<c ? d : c);
}
int main() {
	//习题4.2，求最小值
    Test t1;
	t1.setValue(34,6,2);
	cout<<t1.GetMin()<<endl;

    return 0;
}
