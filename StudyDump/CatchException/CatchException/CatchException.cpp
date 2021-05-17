// CatchException.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<Windows.h>
#include<vector>
#include <iostream>
#include<DbgHelp.h>


int GenerateMiniDump(PEXCEPTION_POINTERS pExceptionPointers)
{
	printf("Enter GenerateMiniDump\r\n");
	// 定义函数指针
	typedef BOOL(WINAPI* MiniDumpWriteDumpT)(
		HANDLE,
		DWORD,
		HANDLE,
		MINIDUMP_TYPE,
		PMINIDUMP_EXCEPTION_INFORMATION,
		PMINIDUMP_USER_STREAM_INFORMATION,
		PMINIDUMP_CALLBACK_INFORMATION
		);
	// 从 "DbgHelp.dll" 库中获取 "MiniDumpWriteDump" 函数
	MiniDumpWriteDumpT pfnMiniDumpWriteDump = NULL;
	HMODULE hDbgHelp = LoadLibrary(L"DbgHelp.dll");
	if (NULL == hDbgHelp)
	{
		printf("LoadLibrary DbgHelp.dll Failed!!!\r\n");
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	pfnMiniDumpWriteDump = (MiniDumpWriteDumpT)GetProcAddress(hDbgHelp, "MiniDumpWriteDump");

	if (NULL == pfnMiniDumpWriteDump)
	{
		printf("Get Process Address Of MiniDumpWriteDump Failed!!!\r\n");
		FreeLibrary(hDbgHelp);
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	// 创建 dmp 文件件
	TCHAR szFileName[MAX_PATH] = { 0 };
	TCHAR* szVersion = (TCHAR*)L"DumpDemo_v1.0";
	SYSTEMTIME stLocalTime;
	GetLocalTime(&stLocalTime);
	wsprintf(szFileName, L"%s-%04d%02d%02d-%02d%02d%02d.dmp",
		szVersion, stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,
		stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond);
	HANDLE hDumpFile = CreateFileW(szFileName, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
	if (INVALID_HANDLE_VALUE == hDumpFile)
	{
		printf("Create Dump File Failed!!!\r\n");
		FreeLibrary(hDbgHelp);
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	// 写入 dmp 文件
	MINIDUMP_EXCEPTION_INFORMATION expParam;
	expParam.ThreadId = GetCurrentThreadId();
	expParam.ExceptionPointers = pExceptionPointers;
	expParam.ClientPointers = FALSE;
	pfnMiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
		hDumpFile, MiniDumpWithFullMemory, (pExceptionPointers ? &expParam : NULL), NULL, NULL);
	// 释放文件
	CloseHandle(hDumpFile);
	FreeLibrary(hDbgHelp);

	printf("Leave GenerateMiniDump\r\n");
	return EXCEPTION_EXECUTE_HANDLER;
}

LONG WINAPI ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo)
{
	// 这里做一些异常的过滤或提示
	//if (IsDebuggerPresent())
	//{
	//	return EXCEPTION_CONTINUE_SEARCH;
	//}
	return GenerateMiniDump(lpExceptionInfo);
}

void DisableSetUnhandledExceptionFilter()
{
	HMODULE _hModule = LoadLibraryW(L"kernel32.dll");
	void* addr = (void*)GetProcAddress(_hModule, "SetUnhandledExceptionFilter");
	BOOL _bRet = FALSE;
	if (addr)
	{
		unsigned char code[16];
		int size = 0;
		code[size++] = 0x33;
		code[size++] = 0xC0;
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;
		DWORD dwOldFlag, dwTempFlag;
		_bRet = VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
		_bRet = WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		_bRet = VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
	}
	FreeLibrary(_hModule);
}


void MakeException01();
void MakeException02();
void MakeException03();
void MakeException04();
void MakeException05();

int main(int nArgs_, char* pszArgs_[])
{
	if (nArgs_ < 2)
	{
		MakeException02();
		return -1;
	}
	// 加入崩溃dump文件功能
	SetUnhandledExceptionFilter(ExceptionFilter);
	//DisableSetUnhandledExceptionFilter();

	int _nSelection = atoi(pszArgs_[1]);
	switch (_nSelection)
	{
	case 1:
	{
		MakeException01();
		break;
	}
	case 2:
	{
		MakeException02();
		break;
	}
	case 3:
	{
		MakeException03();
		break;
	}
	case 4:
	{
		MakeException04();
		break;
	}
	case 5:
	{
		MakeException05();
	}
	default:
		break;
	}
	std::cout << "No Exception!" << std::endl;
	int i;
	std::cin >> i;
	return 0;
}

void MakeException01()
{
	//访问空指针
	int* _pInt = NULL;
	*_pInt = 1;
}

void MakeException02()
{
	int* _pInt = new int[1024];

	_pInt[0] = 1;
	_pInt[1] = 1;
	for (int i = 2; i < 1024; i++)
	{
		_pInt[i] = _pInt[i - 1] + _pInt[i - 2];
	}
	printf("%d\r\n", _pInt[1023]);
	delete[] _pInt;
	delete[] _pInt;
}

void MakeException03()
{
	int i = 0;
	byte* _pStart = new byte[1024];
	memcpy(_pStart - 512, _pStart, 1024);
	delete[] _pStart;
	std::cout << i << std::endl;
}

void MakeException04()
{
	printf(nullptr);
}

void MakeException05()
{
	std::vector<int> _Vec;
	_Vec.at(0);
}