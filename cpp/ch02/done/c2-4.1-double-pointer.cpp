#include <iostream>
using namespace std;

int main() {
	//习题4.1，双重指针
    int a = 10;
    int* p = &a;     // 一级指针：指向 int 变量 a
    int** pp = &p;   // 双重指针：指向 int* 指针 p

    cout << "a 的值: " << a << endl;         // 输出: 10
    cout << "*p 的值: " << *p << endl;       // 输出: 10
    cout << "**pp 的值: " << **pp << endl;   // 输出: 10

    // 通过双重指针修改最底层变量 a 的值
    **pp = 99;
    cout << "修改后 a 的值: " << a << endl;  // 输出: 99

    return 0;
}
