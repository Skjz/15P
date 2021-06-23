#pragma once
#include"CHuman.h"
#include"CSpider.h"
class CStudent :public CHuman,public CSpider
{
    
private:
    int m_nScore;
public:
    void Test();
    void SetName(char * str);
    void SetAge(int nAge);
    void SetScore(int nScore);
    CStudent() :m_nScore(0)
    {

    }
    ~CStudent()
    {
        if (m_szName != NULL)
        {
            delete[]m_szName;
            m_szName = NULL;
        }
    }
};

