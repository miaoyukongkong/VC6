#pragma once	//防止头文件被重复包含

//定义日期类myDate
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