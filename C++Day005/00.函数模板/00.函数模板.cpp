// 00.函数模板.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

template<typename T>
int Max(T a, T b) {
	return a > b ? a : b;
}

template<>
int Max<char*>(char* a, char* b) {
	return strcmp(a, b);
}

int Max(char* a, char* b) {
	return strcmp(a, b);
}

double Max(double a, double b) {
	return a > b ? a : b;
}

void WriteChar( int score) {
	printf("%d", score);
}
void WriteChar(char* score) {
	printf("%s", score);
}

int main()
{
	// 函数参数是int,int
	Max(10, 20);
	Max(100, 200);
	const char *p1 = "123";
	const char* p2 = "abc";
	Max(p1, p2);
    return 0;
}

