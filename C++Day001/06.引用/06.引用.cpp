// 06.引用.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void  MySwap( int &nNumA, int &nNumB) {
	int temp = nNumA;
	nNumA = nNumB;
	nNumB = temp;
}

int main()
{
	int a = 10;
	int c = 20;
	// 定义a的引用b
	// 引用的定义和const一样，必须初始化
	// 初始化后对b的使用都是对a的操作
	// 引用是从一而终的，不能再引用别人
	int &b = a;
	// 下面这个是取地址，不是让b变为c的引用
	// &b = c;
	// 什么时候表示引用，什么时候表示取地址
	// 当&和类型在一起的时候表示引用
	// 当&和变量在一起的时候表示取地址

	// 引用的使用
	int nNumA = 10, nNumB = 20;
	MySwap(nNumA, nNumB);
	const int nNumC = 0;

	const int &a = nNumA;
	const int &b = nNumC;
	int &c = nNumC;
	c = 100;
    return 0;
}

