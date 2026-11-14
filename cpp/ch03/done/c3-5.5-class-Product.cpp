#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Product
{
private:
	//商品名称
	char * name;
	//商品数量
	int count;
	//商品单价
	double price;
	//商品总价
	double total_price;
	//类对象的个数
	static int num;
public:
	Product(char * name_="book",int count_=1,double price_=10,double total_price_=10)
	{
		name=name_;
		count=count_;
		price=price_;
		total_price=total_price_;
		num++;
	}
	Product(Product &p)
	{
		name=p.name;
		count=p.count;
		price=p.price;
		total_price=p.total_price;
		num++;
	}
	~Product()
	{
		cout<<"Product---Destructor"<<endl;
		num--;
		cout<<"num:"<<num<<endl;
	}
	void print() const
	{
		cout<<"name:"<<name;
		cout<<"\tcount:"<<count;
		cout<<"\tprice:"<<price;
		cout<<"\ttotal_price:"<<total_price<<endl;
	}
};
int Product::num=0;
int main()
{
	//习题3-5.5，类Product
	Product p1;
	Product p2("pen",3,1,3);
	Product p3(p1);
	p1.print();
	p2.print();
	p3.print();

	return 0;
}