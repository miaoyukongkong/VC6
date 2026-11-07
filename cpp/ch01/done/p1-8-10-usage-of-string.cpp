#include <iostream>
#include <string>
using namespace std;

int main()
{
	//程序1-8-10，string的使用
	string s1,s2;
	s1="C++程序";
	s2=s1;
	string s3;
	cout<<"s3="<<s3<<endl;

	s3=s1+s2;
	cout<<s1+s2<<endl;
	cout<<"s3="<<s3<<endl;

	s3+="de";
	cout<<"s3="<<s3<<endl;


	bool b=s1<s3;
	cout<<"bool="<<b<<endl;

	char c=s1[2];
	cout<<"c="<<c<<endl;
	cout<<s1[2]<<endl;

	//汉字“程”的第一个字节
	cout<<s1[3]<<endl;
	//汉字“程”的第二个字节
	cout<<s1[4]<<endl;
	//汉字“程”的第三个字节
	cout<<s1[5]<<endl;
	//汉字“程”，UTF-8编码下，一个中文字符占据三个字节
	cout<<s1[3]<<s1[4]<<s1[5]<<endl;

	char arrstr[]="Hello";
	s3=s1+arrstr;
	cout<<s3<<endl;

	return 0;
}