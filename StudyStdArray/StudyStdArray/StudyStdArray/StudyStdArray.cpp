// StudyStdArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<array>
#include<string>
#include<Windows.h>

using namespace std;

void Test00()
{
	array<int, 16> _IntArray = { 1,1,2,3,5,8,13,21,34,55,89, 144 };
	for (auto x : _IntArray)
	{
		cout << x << endl;
	}
}

void Test01()
{
	int _nCount = 0;
	cin >> _nCount;

	//array是静态的，不支持动态分配
	//array<int, _nCount> _IntArray;
	array<int, 16> _IntArray;
	for (int i=0;i<_nCount;i++)
	{
		cin >> _IntArray[i];
	}

	for (auto x : _IntArray)
	{
		cout << x << endl;
	}
}


constexpr int g_nCount = 1024 * 1024;
bool IsContinuous(array<int, g_nCount>& array_)
{
	int* _IntBuffer = new int[g_nCount];
	for (int i = 0; i < g_nCount; i++)
	{
		_IntBuffer[i] = i;
	}

	memcpy(&array_[0], _IntBuffer, sizeof(int) * g_nCount);

	for (int i = 0; i < g_nCount; i++)
	{
		if (array_[i] != i)
		{
			delete[] _IntBuffer;
			return false;
		}
	}

	delete[] _IntBuffer;
	return true;
}
void Test02()
{
	for (int i = 0; i < 1024; i++)
	{
		array<int, g_nCount> _array;
		if (IsContinuous(_array) == false)
		{
			Beep(1000, 1000);
			cout << "Not Continuous!!!" << endl;
		}
	}
}



int main()
{
	Test02();
	return 0;
}