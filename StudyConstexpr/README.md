# const 和 constexpr

## const

- const 修饰变量时，表示该变量【只读】，只能在运行时的初始化阶段赋值，const从语义上来说更像ReadOnly。

- const修饰的**局部变量**在运行阶段是一个实实在在的变量，只是被声明了【只读】，编译器在编译阶段会直接推断出变量的值，并对其进行优化。

- const修饰的**局部变量**虽然是const，但在运行阶段是可以修改的。通过取变量的地址，转为void*指针，再将要修改的值Copy到指针指向的内存即可。

  ````c++
  int _nConstVariable = 123;
  int _nTemp=0;
  int _nOutput = 0;
  cin>>_nTemp;
  memcpy((void*)&_nConstVariable,(void*)&_nTemp);
  //必须复制到另一个变量，再cout，否则_nConstVariable可能会被编译器优化，在编译阶段直接替换成123
  memcpy((void*)&_nOutput,(void*)_nConstVariable);
  cout<<_nOutput<<endl;
  ````

  

- const修饰的**全局变量**，编译器在编译阶段不会直接推断出具体的值。通过取变量的地址，复制内存的方式去修改const修饰的变量会造成运行错误（**段错误**）

    ````c++
    int g_nConstVariable = 123;
    .....
    ....
    ...
    ..
    .
    void Func()
    {
        int _nTemp=0;
    	int _nOutput = 0;
    	cin>>_nTemp;
        //会产生段错误
    	memcpy((void*)&g_nConstVariable,(void*)&_nTemp);
    	memcpy((void*)&_nOutput,(void*)g_nConstVariable);
    	cout<<_nOutput<<endl;
    }
    ````

## constexpr

- 被constexpr修饰的变量意味着编译阶段时，该变量的值就必须确定下来。其语义才是真正意义上的【常量】

- 被constexpr修饰的函数意味着，其**参数**和**依赖**在编译阶段可确定，返回的值在编译阶段也可推断出。

  ````c++
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
  
  int main()
  {
      Test00();
      return 0;
  }
  ````

  