#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef void (*TestFunction)(int x_);

void Test00()
{
    vector<int> _Vector;
    _Vector.push_back(1);
    _Vector.push_back(2);
    _Vector.push_back(3);
    _Vector.push_back(4);
    _Vector.push_back(5);

    sort(_Vector.begin(), _Vector.end(), [](int a,int b){ return a<b;});
    for(auto x:_Vector)
    {
        cout<<x<<endl;
    }
}

void Test01()
{
        vector<int> _Vector;
    _Vector.push_back(1);
    _Vector.push_back(2);
    _Vector.push_back(3);
    _Vector.push_back(4);
    _Vector.push_back(5);

    cout<<"未捕获"<<endl;
    TestFunction func = [](int x_){ cout<<x_<<endl;};
    for(auto x:_Vector)
    {
        func(x);
    }
}

void Test02()
{
    int _nRandom=123;
    auto func = [_nRandom](int input_){cout<<_nRandom+input_<<endl;};
    func(321);
}

void Test03()
{
    int _nRandom=123;
    auto func = [=](int input_){cout<<_nRandom+input_<<endl;};
    func(321);
    cout<<_nRandom<<endl;
}

void Test04()
{
    int _nRandom=123;
    auto func = [&](int input_){_nRandom = 222;};
    func(321);
    cout<<_nRandom<<endl;
}

int main()
{
    Test03();
    return 0;
}