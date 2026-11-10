#include <iostream>
#include <string>
using namespace std;
class CEmployee
{
private:
	string szName;
	int salary;
public:
	void setName(string);
	string getName();
	void setSalary(int);
	int getSalary();
	int averageSalary(CEmployee);
};

void CEmployee::setName(string name)
{
	szName=name;
}
string CEmployee::getName()
{
	return szName;
}
void CEmployee::setSalary(int mon)
{
	salary=mon;
}
int CEmployee::getSalary()
{
	return salary;
}
int CEmployee::averageSalary(CEmployee el)
{
	return (salary+el.getSalary())/2;
}
int main()
{
	//程序2-7，类成员的访问示例2
	CEmployee eT,eY;
	eT.setName("Tom1234567");
	eT.setSalary(5000);
	cout<<eT.getName()<<endl;

	eY.setName("Yong7654321");
	eY.setSalary(3500);
	cout<<eY.getName()<<endl;
	cout<<"aver="<<eT.averageSalary(eY)<<endl;

	return 0;
}