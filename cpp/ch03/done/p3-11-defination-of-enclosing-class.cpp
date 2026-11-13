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
	CTyre():radius(16),width(185){}
	CTyre(int r,int w):radius(r),width(w){}
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
	int getPrice() const
	{
		return price;
	}
	CTyre getCTyre() const
	{
		return tyre;
	}
};
CCar::CCar()
{
	price=50010;
	CTyre();
}
//使用初始化列表
CCar::CCar(int p,int tr,int tw):price(p),tyre(tr,tw){}
int main()
{
	//程序3-11，封闭类的定义
	CCar car(48900,17,225);
	cout<<"price="<<car.getPrice();
	cout<<",CTyre.Radius="<<car.getCTyre().getRadius()
		<<",CTyre.Width="<<car.getCTyre().getWidth()<<endl;

	CCar car1;
	cout<<"price="<<car1.getPrice();
	cout<<",CTyre.Radius="<<car1.getCTyre().getRadius()
		<<",CTyre.Width="<<car1.getCTyre().getWidth()<<endl;
	return 0;
}