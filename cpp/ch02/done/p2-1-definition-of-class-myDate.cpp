//程序2-1，定义日期类myDate
class myDate
{
public:
	//构造函数
	myDate();
	//构造函数
	myDate(int,int,int);
	//设置日期
	void setDate(int,int,int);
	//设置日期
	void setDate(myDate);
	//获取日期
	myDate getDate();
	//设置年
	void setYear(int);
	//获取月
	int getMonth();
	//打印日期
	void printDate() const;
private:
	//成员变量，年月日
	int year,month,day;
};
//在类体外定义成员函数
myDate::myDate()
{
	year=1970;
	month=1;
	day=1;
}
myDate::myDate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}
void myDate::setDate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
	return;
}
void myDate::setDate(myDate oneD)
{
	year=oneD.year;
	month=oneD.month;
	day=oneD.day;
	return;
}
myDate myDate::getDate()
{
	return *this;
}
void myDate::setYear(int y)
{
	year=y;
	return;
}
int myDate::getMonth()
{
	return month;
}
void myDate::printDate() const
{
	cout<<year<<"/""<<month<<"/"<<day;
	return;
}