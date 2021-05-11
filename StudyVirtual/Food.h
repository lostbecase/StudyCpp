#ifndef FOOD_DEFINITION
#define FOOD_DEFINITION
#include"Object.h"
#include<string>

class CFood:public CObject 
{
public:
    CFood();
    CFood(std::string);
};
#endif