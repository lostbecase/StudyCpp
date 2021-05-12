#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


constexpr const int MakeMap(const int x, const int y)
{
    if(x==0)
    {
        return 0;
    }
    else if(x <0)
    {
        return -y;
    }
    else
    {
        return (x*y)%1024;
    }
}

int Test01()
{
    const int _nConstNumber = cin.get();
    int _nArraySize = MakeMap(_nConstNumber,1);
    cout<<"_nArraySize="<<_nArraySize<<endl;
    int _IntArray[_nArraySize]={0};
    for(int i=0;i<_nArraySize;i++)
    {
        _IntArray[i] = i;
    }

    int _nTemp = 0;
    for(int i=0;i<_nArraySize;i++)
    {
        cout<<"Please input "<<i<<"th number:"<<endl;
        cin>> _IntArray[i];
    }

    for(int i=0;i<_nArraySize;i++)
    {
        cout<<_IntArray[i]<<endl;
    }
    return 0;
}

int Test00()
{
    constexpr int _nArraySize = MakeMap(2,3);
    cout<<"_nArraySize="<<_nArraySize<<endl;
    int _IntArray[_nArraySize]={0};
    for(int i=0;i<_nArraySize;i++)
    {
        _IntArray[i] = i;
    }

    int _nTemp = 0;
    for(int i=0;i<_nArraySize;i++)
    {
        cout<<"Please input "<<i<<"th number:"<<endl;
        cin>> _IntArray[i];
    }

    for(int i=0;i<_nArraySize;i++)
    {
        cout<<_IntArray[i]<<endl;
    }
    return 0;
}

int Test02()
{
    cout<<"Start Test \"const modify local variable"<<endl;
    const int _nConstVariable = 123;
    cout<<"Now, _nConstVariable = "<<_nConstVariable<<endl;
    int _nTemp = 0;
    int _nTemp2 = 0;
    cout<<"Please input a int to _nConstVariable"<<endl;
    cin>>_nTemp;
    memcpy((void*)&_nConstVariable,&_nTemp,sizeof(int));
    memcpy((void*)&_nTemp2,&_nConstVariable,sizeof(int));
    cout<<"Now, _nConstVariable = "<<_nTemp2<<endl;
    return 0;
}

const int g_nConstVariable = 456;
int Test03()
{
    cout<<"Start Test \"const modify global variable"<<endl;
    cout<<"Now, g_nConstVariable = "<<g_nConstVariable<<endl;
    int _nTemp = 0;
    int _nTemp2 = 0;
    cout<<"Please input a int to g_nConstVariable"<<endl;
    cin>>_nTemp;
    memcpy((void*)&g_nConstVariable,&_nTemp,sizeof(int));
    memcpy((void*)&_nTemp2,&g_nConstVariable,sizeof(int));
    cout<<"Now, g_nConstVariable = "<<g_nConstVariable<<endl;
    return 0;
}

int main()
{
    Test02();
    Test03();
    return 0;
}