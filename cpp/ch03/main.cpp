#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Reverse
{
private:
	int num[10];
public:
	Reverse(){}
	void setNum()
	{
		cout<<"请依次输入10个整数："<<endl;
		for(int i=0;i<10;i++)
		{
			cout<<"第"<<i+1<<"个整数：";
			cin>>num[i];
		}
	}
	void print() const
	{
		cout<<"逆序输出10个整数："<<endl;
		for(int j=9;j>=0;j--)
			cout<<num[j]<<endl;
	}
};

int main()
{
	//习题3-5.6，类Reverse，倒序输出
	Reverse r;
	r.setNum();
	r.print();

	return 0;
}