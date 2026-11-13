#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class CTest
{
private:
	int n;
public:
	CTest() {n=1;}
	int GetValue() const
	{
		return n;
	}
	int GetValue()
	{
		return 2*n;
	}
};

int main()
{
	//Ï°Ìâ3-4.1£¬Êä³ö1,2
	const CTest objTest1;
	CTest objTest2;
	cout<<objTest1.GetValue()<<","<<objTest2.GetValue()<<endl;

	return 0;
}