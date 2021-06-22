#include "CSTUDENT.h"
CSTUDENT::CSTUDENT() :
    m_nId(0), m_nScore(0), m_szName(NULL)
{
    ;
}
CSTUDENT::CSTUDENT(const char* szName, int nId, int nScore)
{
    int lenth = strlen(szName) + 1;
    m_szName = new char[lenth];
    strcpy_s(m_szName, lenth, szName);
    m_nId = nId;
    m_nScore = nScore;
}
CSTUDENT::~CSTUDENT()
{
    if (m_szName != NULL)
    {
        delete[]m_szName;
    }
    m_nId = 0;
    m_nScore = 0;
}
CSTUDENT::CSTUDENT(CSTUDENT& other)
{
    int lenth = strlen(other.m_szName) + 1;
    m_szName = new char[lenth] {0};
    strcpy_s(m_szName, lenth, other.m_szName);
    m_nId = other.m_nId;
    m_nScore = other.m_nScore;
}