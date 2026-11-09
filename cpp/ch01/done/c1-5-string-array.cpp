#include <iostream>
#include <string>
using namespace std;

int main()
{
	//习题1-5，string的综合应用
	//创建一维string数组，并接收键盘输入
	int n;
	cout<<"请输入一个正整数n：";
	cin>>n;
	string *p=new string[n];
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\n 请输入第"<<i+1<<"个字符串：";
		cin>>p[i];
	}


	//找出最长字符串和最短字符串，并计算n个字符串的平均长度
	string mLong=p[0];
	string mShort=p[0];
	double totalLength=0;
	int j;
	for(j=0;j<n;j++)
	{
		if(p[j].size()>mLong.size()) mLong=p[j];
		if(p[j].size()<mShort.size()) mShort=p[j];
		totalLength+=p[j].size();
	}
	cout<<"最长字符串为："<<mLong<<endl;
	cout<<"最短字符串为："<<mShort<<endl;
	cout<<"字符串的平均长度为："<<totalLength/n<<endl;

	//释放动态内存
	delete [] p;
	p=0;

	return 0;
}
