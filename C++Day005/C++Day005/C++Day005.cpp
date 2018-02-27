// C++Day005.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CBase1 {
public:
	CBase1() { m_nNum1 = 10; }
	int m_nNum1;
	virtual ~CBase1() {}
};
class CBase2 {
public:
	CBase2() { m_nNum2 = 20; }
	int m_nNum2;
	virtual ~CBase2() {}
};
class CDerived :public CBase1, public CBase2 {
public:
	virtual ~CDerived() {}
};

int main()
{
	CDerived obj;
	CBase1 *objBase1 = &obj;
	CBase2 *objBase2 =dynamic_cast<CBase2*>(objBase1);
    return 0;
}

