#include <iostream>
using namespace std;
class Test
{
private:
	int x,y;
public:
	Test(int i,int j)
	{
		x=i;
		y=j;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};
int main()
{
	//Ï°Ìâ3.1£¬Êä³ö1020
	Test mt(10,20);
	cout<<mt.getx();
	cout<<mt.gety()<<endl;

	return 0;
}