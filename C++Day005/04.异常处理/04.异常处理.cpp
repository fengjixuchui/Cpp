// 04.异常处理.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void Fun()throw(int,char) {
	throw 12;
}

int main()
{
	//int a = 10, b = 0;
	//try
	//{
	//	// 把有可能发生异常的地方用try包起来
	//	if (b == 0)
	//	{
	//		throw "除数不能为0";
	//	}
	//	int c = a / b;
	//	throw 1.2;
	//}
	//catch (const char* e)
	//{
	//	printf("异常:%s\n",e);
	//}
	//catch (int) {
	//	printf("正常\n");
	//}
	//catch (...) {
	//	printf("未知类型\n");
	//}
	try {
		Fun();
	}
	catch (...) {
		printf("111\n");
	}
    return 0;
}

