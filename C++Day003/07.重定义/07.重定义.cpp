// 07.重定义.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Base {
public:
	Base():m_nNumA(10){}
	int m_nNumA;
	void Fun() {
		printf("Base\n");
	}
};
class Derived :public Base {
public:
	Derived():m_nNumA(20){}
	int m_nNumA;
	// 成员函数的重定义
	// 要求：作用域不同，函数名相同，其他不做要求
	void Fun(int a) {
		printf("Derived\n");
	}
	// 子类的两个Fun重载
	// 子类的两个Fun和基类的Fun是重定义
	void Fun() {
		printf("Derived\n");
	}
};


int main()
{
	Derived obj;
	printf("%d\n", obj.Base::m_nNumA);
	obj.Fun();
    return 0;
}

