#include"Animal.h"
class CDog:public CAnimal
{
public:
    CDog(std::string strName_);
    void Eat(const CFood&)override;
    void Sleep();
};