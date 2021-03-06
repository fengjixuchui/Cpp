// 02.内联函数和define.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 有参宏
#define MAX(a,b) a>b?a:b
// 内联函数
inline int Max(int a, int b) {
	return a > b ? a : b;
}
int main()
{
	int a = 10, b = 20;
	int c = MAX(a, b);
	// 编译时替换成：
	int c1 = a > b ? a : b;
	// 结果不确定
	int d = MAX(a++, b);
	// 编译时替换成
	int d1 = a++ > b ?  a++ : b;
	int d2 = Max(a++, b);
    return 0;
}

