#include <iostream>
using namespace std;
class A
{
public:
	int a,b;
private:
	int c,d;
public:
	//getc是标准库中用来从文件流读取字符的宏定义（Macro）（其原形类似 #define getc(_stream) ...），需要改名
	//int getc();
	int getC();
	A() : a(0), b(0), c(0), d(0) {}
};
int A::getC()
{return c;
}
int main()
{
	//习题3.3
	A onea;
	cout<<onea.a<<","<<onea.getC()<<endl;

	return 0;
}