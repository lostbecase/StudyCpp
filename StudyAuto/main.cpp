#include<iostream>
#include"Calculator.h"
using namespace std;

int main()
{
    int _nFirst = 0;
    int _nSecond = 0;
    CCalculator _Calculator;
    
    cout<<"Please input first number"<<endl;
    cin>>_nFirst;
    cout<<"Please input second number"<<endl;
    cin>>_nSecond;

    //cout<<"The multi of two number is "<<_Calculator.Multiple(_nFirst,_nSecond);
    cout<<"The sum of two number is "<<_Calculator.Add(_nFirst,_nSecond)<<endl;

}