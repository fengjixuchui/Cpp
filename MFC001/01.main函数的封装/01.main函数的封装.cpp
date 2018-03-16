// 01.main�����ķ�װ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


class CBase {
public:
	CBase() {
		printf("CBase::%p\n", this);
		m_pStatic = this;
	}
	virtual bool InitInstance()=0;
	static CBase* GetApp() {
		return m_pStatic;
	}
private:
	static CBase* m_pStatic;
};
CBase* CBase::m_pStatic = nullptr;

class CDerived :public CBase {
public:
	CDerived() {
		printf("CDerived::%p\n", this);
	}
	bool InitInstance() {
		printf("InitInstance\n");
		return true;
	}
};
CDerived g_app;

int main()
{
	//printf("main::%p\n", &g_app);
	CBase::GetApp()->InitInstance();
    return 0;
}

