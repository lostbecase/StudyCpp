#include<string>
#include"Food.h"

class CAnimal:public CObject
{
public:
    CAnimal();
    CAnimal(std::string);
    virtual void Eat(const CFood&);
    void Sleep();
};