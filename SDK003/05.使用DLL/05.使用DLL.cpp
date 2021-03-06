// 05.使用DLL.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include "..\04.DLL\04.DLL.h"
#pragma comment(lib,"..\\Debug\\04.DLL.lib")
//1. dll函数使用方式
// 在函数声明前加_declspec(dllexport)
// 隐式调用的时候 加头文件包含
// 加库目录(lib文件)
/*
#include "..\04.DLL\04.DLL.h"
#pragma comment(lib,"..\\Debug\\04.DLL.lib")
*/


int main()
{
	//FunTest();
	// 显式调用
	// loadlibrary
	// getprocaddr
	HMODULE hMod = LoadLibrary(L"..\\Debug\\04.DLL.dll");
	DWORD dwAddr = (DWORD)GetProcAddress(hMod, "FunTest");
	typedef void(*PFUN)();
	PFUN MyFun = (PFUN)dwAddr;
	MyFun();
    return 0;
}

