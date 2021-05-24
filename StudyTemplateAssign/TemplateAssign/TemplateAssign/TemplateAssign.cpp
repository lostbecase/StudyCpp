// TemplateAssign.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Vector2D
{
public:
    double m_nX;
    double m_nY;

	Vector2D();
	~Vector2D();

    Vector2D operator+(Vector2D rightVector)
    {
        Vector2D _Result;
        _Result.m_nX = m_nX + rightVector.m_nX;
        _Result.m_nY = m_nY + rightVector.m_nY;
        return _Result;
    }
};

Vector2D::Vector2D():m_nX(0),m_nY(0)
{

}

Vector2D::~Vector2D()
{

}


template<class T>
T Add(T x, T y)
{
    T _Temp = x;
    T _Result = _Temp + y;
    return _Result;
}

int main()
{
    int _nFirstInt = 0;
    int _nSecondInt = 0;
    double _nFirstDouble = 0;
    double _nSecondDouble = 0;
    Vector2D _FirstVector;
    Vector2D _SecondVector;

    printf("Please input first integer:\r\n");
    cin >> _nFirstInt;
    printf("Please input second integer:\r\n");
    cin >> _nSecondInt;
    printf("When T is int:\r\n");
    int _nIntegerResult = Add<int>(_nFirstInt, _nSecondInt);
    cout << "The result is " << _nIntegerResult << endl;

    printf("Please input first double:\r\n");
    cin >> _nFirstDouble;
    printf("Please input second double:\r\n");
    cin >> _nSecondDouble;
    printf("When T is double:\r\n");
    double _nDoubleResult = Add<double>(_nFirstDouble, _nSecondDouble);
    cout << "The result is " << _nDoubleResult << endl;

    printf("Please input first Vector:\r\n");
    cin >> _FirstVector.m_nX >> _FirstVector.m_nY;
    printf("Please input second Vector:\r\n");
    cin >> _SecondVector.m_nX >> _SecondVector.m_nY;
    printf("When T is Vector:\r\n");
    Vector2D _VectorResult = Add<Vector2D>(_FirstVector, _SecondVector);
    cout << "The result is (" << _VectorResult.m_nX << "," << _VectorResult.m_nY << ")" << endl;
    return 0;
}
