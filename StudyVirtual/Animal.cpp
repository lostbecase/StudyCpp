#include<iostream>
#include"Animal.h"
CAnimal::CAnimal()
{
    m_strName = "";
}

CAnimal::CAnimal(std::string strName_)
{
    m_strName = strName_;
}

void CAnimal::Eat(const CFood& Food_)
{
    std::cout<<m_strName<<"Eat"<<Food_.m_strName<<std::endl;
}

void CAnimal::Sleep()
{
    std::cout<<"Sleep"<<std::endl;
}