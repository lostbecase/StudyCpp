# Virtual-Override-final 关键字

## Virtual 

​    被标记为virtual的函数为虚函数，可被其他派生类改写。

## Override

​	被标记为Override的函数表示，应该重写基类中的虚函数，如果实际没有重写（如：函数其实不是虚函数的时候），则在编译阶段会报错

### Final

​	被标记为Final的函数表示，该虚函数是最终的实现，派生类的虚函数中不能再去Override，如果尝试override，则会在编译阶段报错。