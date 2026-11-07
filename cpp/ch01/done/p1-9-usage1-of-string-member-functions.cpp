#include <iostream>
#include <string>
using namespace std;

int main()
{
	//程序1-9，string成员函数的使用1
	string str;
	if(str.empty())
		cout<<"str is NULL."<<",length="<<str.length()<<endl;
	else
		cout<<"str is not NULL."<<endl;

	str=str.append("abcdefg");
	cout<<"str is "<<str<<",size="<<str.size()<<endl;

	const char *p=str.c_str();
	cout<<"p="<<p<<endl;
	//查找成功，3
	cout<<"find:"<<str.find("de",0)<<endl;
	//查找失败
	cout<<"find:"<<str.find("de",4)<<endl;

	string str1=str.insert(4,"123");
	cout<<str1<<endl;

	return 0;
}