#pragma once
#include<stdio.h>
class CHuman
{
public:
    CHuman() :m_szName(NULL), m_nAge(0)
    {

    }
protected:
    char* m_szName;
    int m_nAge;
};

