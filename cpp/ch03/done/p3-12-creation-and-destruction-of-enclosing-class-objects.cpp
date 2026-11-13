#include <iostream>
#include <string>
#include "myDate.h"
#include "Student.h"
using namespace std;

//轮胎类
class CTyre
{
private:
	int radius;
	int width;
public:
	CTyre():radius(16),width(185)
	{
		cout<<radius<<",CTyre Constructor"<<endl;
	}
	CTyre(int r,int w):radius(r),width(w)
	{
		cout<<radius<<",CTyre Constructor"<<endl;
	}
	//复制构造函数
	CTyre(const CTyre & tyre)
	{
		radius=tyre.radius;
		width=tyre.width;
		cout<<"copy CTyre"<<endl;
	}
	~CTyre()
	{
		cout<<radius<<",CTyre Destructor"<<endl;
	}
	int getRadius() const
	{
		return radius;
	}
	int getWidth() const
	{
		return width;
	}
};
//汽车类，封闭类
class CCar
{
private:
	int price;
	CTyre tyre;
public:
	CCar();
	CCar(int p,int tr,int tw);
	~CCar();
	int getPrice() const
	{
		return price;
	}
	CTyre getCTyre() const
	{
		//使用CTyre的复制构造函数创建临时的tyre对象，之后调用CTyre的析构函数销毁这个临时对象
		return tyre;
	}
};
CCar::CCar()
{
	price=50010;
	//不需要写这一行，成员对象tyre在进入该构造函数前就已经初始化
	//如果写了，会多创建一个全新的、没有名字的临时tyre对象
	//由于没有任何变量接收它，执行到末尾的分号，就会立刻调用CTyre的析构函数销毁这个临时对象
	//CTyre();
	cout<<price<<",CCar Constructor"<<endl;
}
//使用初始化列表
CCar::CCar(int p,int tr,int tw):price(p),tyre(tr,tw)
{
	cout<<price<<",CCar Constructor"<<endl;
}
CCar::~CCar()
{
	cout<<price<<",CCar Destructor"<<endl;
}
int main()
{
	//程序3-12，封闭类对象的创建与消亡
	CCar car(48900,17,225);
	cout<<"price="<<car.getPrice()<<endl;
	cout<<",CTyre.Radius="<<car.getCTyre().getRadius()
		<<",CTyre.Width="<<car.getCTyre().getWidth()<<endl;

	CCar car1;
	cout<<"price="<<car1.getPrice()<<endl;
	cout<<",CTyre.Radius="<<car1.getCTyre().getRadius()
		<<",CTyre.Width="<<car1.getCTyre().getWidth()<<endl;
	return 0;
}