#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> _Vector;
    _Vector.push_back(3);
    _Vector.push_back(5);
    _Vector.push_back(1);
    _Vector.push_back(2);
    _Vector.push_back(4);

    sort(_Vector.begin(), _Vector.end(), [](int a,int b){ return a<b;});
    for(auto x:_Vector)
    {
        cout<<x<<endl;
    }

    return 0;
}