#include <iostream>
#include <string>
using namespace std;
class Box
{
public:
	double length;
	void setWidth(double wid);
	double getWidth();
private:
	double width;
};
double Box::getWidth()
{
	return width;
}
void Box::setWidth(double wid)
{
	width=wid;
}
int main()
{
	//程序2-6，类成员的访问示例1
	Box box;
	box.length=10.0;
	cout<<"Length 0f box:"<<box.length<<endl;
	box.setWidth(10.0);
	cout<<"Width of box:"<<box.getWidth()<<endl;

	return 0;
}