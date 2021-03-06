// 01.enum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

enum SEASON {
	// 默认从0开始，后面的值是前面的值+1
	spring=9,summer=10,autumn,winter
};

#define SPRING 9
#define SUMMER 10
#define AUTUMN 11
#define WINTER 12

// 我这个FUN的参数a 只能是9~12
void FunTest(SEASON a) {
	switch (a) {
	case SPRING:
		printf("春\n");
		break;
	case SUMMER:
		printf("夏\n");
		break;
	case AUTUMN:
		printf("秋\n");
		break;
	case WINTER:
		printf("冬\n");
		break;
	default:
		break;
	}
}

int main()
{
	// 只占4个字节
	printf("sizeof(SEASON) = %d\n", sizeof(SEASON));
	FunTest(spring);
	// error
	//FunTest(9);
    return 0;
}

