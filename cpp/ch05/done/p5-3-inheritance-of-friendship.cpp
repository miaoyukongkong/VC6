#include <iostream>
using namespace std;
//前向引用生声明
class another;
class Base
{
private:
	float x;
public:
	void print(const another &K);
};
class Derived : public Base
{
private:
	float y;
};
class another
{
private:
	int aaa;
public:
	another():aaa(100){}
	friend void Base::print(const another &K);
};
void Base::print(const another &K)
{
	cout<<"Base:"<<K.aaa<<endl;
}
int main()
{
	//程序5-3，派生类继承了友元函数
	Base a;
	Derived d;
	another ano;
	a.print(ano);
	d.print(ano);

	return 0;
}