#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Course
{
private:
	string name;
	static int count;
public:
	Course(string n="C++")
	{
		name=n;
		count++;
	}
	Course(Course &c)
	{
		name=c.name;
		count++;
	}
	~Course()
	{
		cout<<"Course---Destructor"<<endl;
		count--;
		cout<<"count:"<<count<<endl;
	}
	void print() const
	{
		cout<<"Course:"<<name<<endl;
	}
};
int Course::count=0;
int main()
{
	//Ï°Ìâ3-5.3£¬ÀàCourse
	Course c1;
	Course c2("PE");
	Course c3(c1);
	c1.print();
	c2.print();
	c3.print();

	return 0;
}