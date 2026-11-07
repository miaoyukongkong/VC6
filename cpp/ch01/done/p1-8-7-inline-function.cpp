#include <iostream>
#include <windows.h>

using namespace std;

// 1. 目标普通函数
int normal_calc(int a, int b) {
    int x = a + b;
    int y = a - b;
    return x * 2 + y / 2;
}

// 2. 目标内联函数
__forceinline int inline_calc(int a, int b) {
    int x = a + b;
    int y = a - b;
    return x * 2 + y / 2;
}

int main() {
	// 程序1-8-7，内联函数
    const long ITERATIONS = 300000000; 
    int result1 = 0; 
    int result2 = 0; 

    // 核心黑科技：定义一个函数指针指向 normal_calc
    // 编译器在通过指针调用函数时，由于无法在编译期确定地址，绝对无法对其进行内联优化！
    int (*p_normal)(int, int) = normal_calc;

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    double elapsedTime;

    QueryPerformanceFrequency(&frequency);

    cout << "正在运行终极内联测试（函数指针防自动内联版），请稍候..." << endl << endl;

    // === 测试 1：真正的普通函数调用（有压栈、出栈开销） ===
    QueryPerformanceCounter(&start);
    for (long i = 0; i < ITERATIONS; ++i) {
        result1 += p_normal(i, 5); // 通过指针调用，强行保留调用开销
    }
    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    cout << "Real Normal function call cost: " << elapsedTime << " ms" << endl;

    // === 测试 2：纯正的内联函数展开 ===
    QueryPerformanceCounter(&start);
    for (long j = 0; j < ITERATIONS; ++j) {
        result2 += inline_calc(j, 5); // 真正的原地代码展开
    }
    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    cout << "Pure Inline function cost: " << elapsedTime << " ms" << endl;

    cout << "\n(验证数据: " << result1 << " , " << result2 << ")" << endl;

    return 0;
}
