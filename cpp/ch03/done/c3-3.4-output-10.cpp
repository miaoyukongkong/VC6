#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Test
{
private:
	static int num;
public:
	Test(int);
	void show();
};
//给静态成员变量赋初值
int Test::num=5;
Test::Test(int n)
{
	num=n;
}
void Test::show()
{
	cout<<num<<endl;
}
int main()
{
	//习题3-3.4，输出10
	Test t(10);
	t.show();

	return 0;
}