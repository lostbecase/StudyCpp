#include"Dog.h"
#include"Food.h"

int main()
{
    CDog _Dog("Alice");
    CFood _Food("Beaf");
    _Dog.Eat(_Food);
    return 0;
}