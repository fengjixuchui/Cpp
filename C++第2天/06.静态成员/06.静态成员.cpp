// 06.静态成员.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int g_nCount = 0;

class 学生 {
public:
	学生() {
		m_nCount++;
	}
	~学生() {
		m_nCount--;
	}
	学生(const 学生& obj) {
		m_nCount++;
	}
	static int GetCount() {
		printf("%d\n", m_nCount);
		printf("%d\n", m_nNumA); //error,必须通过类对象访问
		return m_nCount;
	}
	int m_nNumA;
private:
	static int m_nCount;
};

int 学生::m_nCount = 0;

void GetCount() {
	// 只能访问类的public成员
	printf("%d\n", 学生::m_nCount);
}
int main()
{
	学生 obj1, obj2;
	学生::GetCount();
	obj2.GetCount();
	printf("sizeof(学生)= %d\n", sizeof(学生));
    return 0;
}

