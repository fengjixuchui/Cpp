// 01.友元成员函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CStu;
class CTeacher {
public:
	void Change(CStu& obj);
	void Show(CStu obj);
};

class CStu {
private:
	friend void CTeacher::Change(CStu& obj);
	int m_nScore;
};

void CTeacher::Change(CStu& obj) {
	obj.m_nScore += 100;
}

void CTeacher::Show(CStu obj) {
	printf("%d\n", obj.m_nScore);
}

int main() {
	return 0;
}

