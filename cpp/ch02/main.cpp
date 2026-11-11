#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.1415926;
class Cylinder
{
private:
	double r,h;
public:
	Cylinder(double rVal=0.0,double hVal=0.0): r(rVal), h(hVal)
	{
		if(rVal<0) r=0.0;
		if(hVal<0) h=0.0;
	}

	//计算底圆周长
	double getCircleLen() const
	{
		return 2*pi*r;
	}

	//计算底圆面积
	double getBaseArea() const
	{
		return pi*r*r;
	}

	//计算圆柱体积
	double getVolume() const
	{
		return getBaseArea()*h;
	}

	//计算圆柱表面积
	double getSurfaceArea() const
	{
		return getCircleLen()*h+getBaseArea()*2;
	}
};
int main() {
	//习题5.4，设计并实现类Cylinder
	Cylinder cy(3,5);

	cout<<"底圆周长："<<cy.getCircleLen()<<endl;
	cout<<"底圆面积："<<cy.getBaseArea()<<endl;
	cout<<"圆柱体积："<<cy.getVolume()<<endl;
	cout<<"圆柱表面积："<<cy.getSurfaceArea()<<endl;

    return 0;
}
