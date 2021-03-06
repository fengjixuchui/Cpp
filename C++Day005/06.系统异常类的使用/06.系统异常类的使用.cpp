// 06.系统异常类的使用.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
using std::exception;

class CMyError :public exception {
public:
	CMyError(int nPos) :exception("下标越界\n"), m_nPos(nPos) {
	}
	virtual const char *what() const {
		printf("数组下标：%d\n", m_nPos);
		return exception::what();
	}
	int m_nPos;
};

template<class T>
class CVector {
public:
	CVector() {
		m_nCount = 0;
		m_p = new T[10]{};
	}
	void Push(T nEle);
	void Pop() {
		m_nCount--;
	}
	T& operator[](int nPos) {
		if (nPos >= m_nCount) {
			throw CMyError(nPos);
		}
		return m_p[nPos];
	}
	int m_nCount;
	T *m_p;
};
// 模板类成员函数的类外实现
template<class T>
void CVector<T>::Push(T nEle) {
	m_p[m_nCount++] = nEle;
}

int main() {
	CVector<int> obj;
	for (int i = 0; i < 10; i++) {
		obj.Push(i);
	}
	for (int i = 0; i < 100; i++) {
		try {
			//obj.operator[](i) = i+10;
			obj[i] = i + 10;
			//printf("%d\n", i);
		}
		catch (const std::exception& e) {
			printf("%s\n", e.what());
			break;
		}
	}
	return 0;
}