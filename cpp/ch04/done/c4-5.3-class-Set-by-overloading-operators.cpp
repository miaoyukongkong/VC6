#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Set
{
private:
	//<vector>头文件，能够自动调整大小的智能数组
	vector<int> elements;
public:
	Set(){}
	Set(const int arr[],int n)
	{
		for(int i=0;i<n;i++)
			insert(arr[i]);
	}
	//插入元素
	void insert(int val)
	{
		//<algorithm>头文件中的二分查找函数lower_bound，在有序序列中查找第一个“大于或等于”目标值的元素位置
		vector<int>::iterator it=lower_bound(elements.begin(),elements.end(),val);
		if(it == elements.end() || *it != val)
			elements.insert(it,val);
	}
	//重载加法运算符为集合的并
	Set operator+(const Set & other) const
	{
		Set result;
		//<algorithm>头文件，求两个已排序集合的并
		set_union(
			elements.begin(),elements.end(),
			other.elements.begin(),other.elements.end(),
			//<iterator> 头文件中的插入迭代器，自动调用result.elements.push_back() 把元素追加到容器末尾
			back_inserter(result.elements)
			);
		return result;
	}
	//重载减法运算符为集合的差
	Set operator-(const Set & other) const
	{
		Set result;
		//<algorithm>头文件，求两个已排序集合的差
		set_difference(
			elements.begin(),elements.end(),
			other.elements.begin(),other.elements.end(),
			back_inserter(result.elements)
			);
		return result;
	}
	//重载乘法运算符为集合的交
	Set operator*(const Set & other) const
	{
		Set result;
		//<algorithm>头文件，求两个已排序集合的交
		set_intersection(
			elements.begin(),elements.end(),
			other.elements.begin(),other.elements.end(),
			back_inserter(result.elements)
			);
		return result;
	}
	//重载<运算符，判断两个集合是否为真子集关系
	bool operator<(const Set & other) const
	{
		if(elements.size() >= other.elements.size())
		{
			return false;
		}
		//<algorithm>头文件，判断两个已排序集合是否为子集关系
		return includes(
			other.elements.begin(),other.elements.end(),
			elements.begin(),elements.end()
			);
	}
	//重载==运算符，判断两个集合是否相等
	bool operator==(const Set & other) const
	{
		return elements == other.elements;
	}
	//重载!=运算符，判断两个集合是否不相等
	bool operator!=(const Set & other) const
	{
		return !(*this == other);
	}
	//打印辅助函数
	void print() const
	{
		cout<<"{";
		//size_t 是 C/C++ 标准库中定义的一种无符号整数类型（只存储 0 和正整数），专门用来表示数组下标、元素个数或内存大小
		for(size_t j=0;j<elements.size();j++)
		{
			cout<<elements[j];
			if(j+1<elements.size()) cout<<",";
		}
		cout<<"}";
	}
};
//重载流插入运算符
ostream & operator<<(ostream & os,const Set & s)
{
	s.print();
	return os;
}
int main()
{
	//习题4-5.3，重载实现集合Set
	int arrA[] = {1, 2, 3, 4};
    int arrB[] = {3, 4, 5, 6};
    int arrC[] = {1, 2};

    Set A(arrA, 4);
    Set B(arrB, 4);
    Set C(arrC, 2);

    cout << "集合 A: " << A << endl;
    cout << "集合 B: " << B << endl;
    cout << "集合 C: " << C << endl;
    cout << "------------------------" << endl;

    cout << "并集 (A + B): " << (A + B) << endl;
    cout << "差集 (A - B): " << (A - B) << endl;
    cout << "交集 (A * B): " << (A * B) << endl;

    // VC6.0 推荐使用三目运算符输出 bool 值，部分版本对 boolalpha 支持不完善
    cout << "C 是 A 的真子集 (C < A): " << ((C < A) ? "true" : "false") << endl;
    cout << "A 是 A 的真子集 (A < A): " << ((A < A) ? "true" : "false") << endl;
    cout << "A 等于 B (A == B): " << ((A == B) ? "true" : "false") << endl;
    cout << "A 不等于 B (A != B): " << ((A != B) ? "true" : "false") << endl;

	return 0;
}