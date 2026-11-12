#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;
class Samp
{
public:
	void Setij(int a,int b)
	{
		i=a;
		j=b;
	}
	Samp()
	{
		cout<<"构造.."<<i<<endl;
	}
	~Samp()
	{
		cout<<"析构.."<<i<<endl;
	}
	int GetMuti()
	{
		return i*j;
	}
protected:
	int i;
	int j;
};
int main()
{
	//程序3-2-4，对象数组：后构造先析构，LIFO
	Samp *p;
	p=new Samp[5];
	if(!p)
	{
		cout<<"内存分配错误\n";
		return 1;
	}
	for(int j=0;j<5;j++)
		p[j].Setij(j,j);
	for(int k=0;k<5;k++)
		cout<<"Muti["<<k<<"]值是："<<p[k].GetMuti()<<endl;
	delete [] p;

	return 0;
}