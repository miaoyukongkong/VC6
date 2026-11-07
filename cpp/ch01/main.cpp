#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	//程序1-10，string成员函数的使用2
	string s1="C++语言";
	string s2="程序设计";
	string s3=s1+s2;
	string s4;

	s4=s1.append(s2);
	cout<<"s1="<<s1<<endl;
	if(s3==s4) cout<<"结果相同"<<endl;
	else cout<<"结果不相同"<<endl;

	int size=s1.size();
	int length=s1.length();
	cout<<"size="<<size<<"  ,length="<<length<<endl;

	s1[0]='J';
	cout<<"s1="<<s1<<endl;

	//求s1从下标3开始，长度为4的字符串：语言
	string s5=s1.substr(3,4);
	cout<<s5<<endl;

	char str[20];
	//将s5中的字符串复制到str
	strcpy(str,s5.c_str());
	cout<<"str="<<str<<endl;

	cout<<"s1="<<s1<<",s2="<<s2<<endl;
	//交换s1和s2
	s1.swap(s2);
	cout<<"s1="<<s1<<",s2="<<s2<<endl;
	cout<<s2.find(str)<<endl;

	return 0;
}