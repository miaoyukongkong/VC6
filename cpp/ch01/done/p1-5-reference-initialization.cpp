#include <iostream>
using namespace std;

int main()
{
	// 程序1-5，对引用进行初始化
	const int cInt=30;
	int oneInt=50;

	//T&←T
	int & ref=oneInt;
	cout<<"ref="<<ref<<endl;
	
	//CT&←CT,CT&表示类型T的常引用，CT表示类型T的常量
	const int & rc1=cInt;
	cout<<"rc1="<<rc1<<endl;

	//CT&←T
	const int & rc2=oneInt;
	cout<<"rc2="<<rc2<<endl;

	//CT&←T&
	const int & rc3=ref;
	cout<<"rc3="<<rc3<<endl;

	//T←T&
	int dInt=ref;
	cout<<"dInt="<<dInt<<endl;

	//T←CT
	int eInt=cInt;
	cout<<"eInt="<<eInt<<endl;

	//T←CT&
	int fInt=rc1;
	cout<<"fInt="<<fInt<<endl;

	//CT←T
	const int & gInt=oneInt;
	cout<<"gInt="<<gInt<<endl;

	//T&←T&
	int & ref1=ref;
	cout<<"ref1="<<ref1<<endl;

	//CT←T&
	const int hInt=ref;
	cout<<"hInt="<<hInt<<endl;

	//CT←CT
	const int jInt=cInt;
	cout<<"jInt="<<jInt<<endl;

	//CT&←CT&
	const int & mInt=rc1;
	cout<<"mInt="<<mInt<<endl;

	//CT←CT&
	const int nInt=rc2;
	cout<<"nInt="<<nInt<<endl;


	//T&←CT&强制类型转换
	int & r2=(int &)rc1;
	cout<<"r2="<<r2<<endl;

	//T&←CT强制类型转换
	int & r3=const_cast<int &>(cInt);
	cout<<"r3="<<r3<<endl;


	return 0;
}
