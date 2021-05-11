#include<iostream>
#include"Dog.h"

CDog::CDog(std::string strName_)
{
    m_strName = strName_;
}

void CDog::Eat(const CFood& Food_)
{
    std::cout<<"[Dog:"<<m_strName<<"] Eat "<<Food_.m_strName<<std::endl;
}

void CDog::Sleep()
{
    std::cout<<"[Dog:"<<m_strName<<"] Sleep"<<std::endl;
}
