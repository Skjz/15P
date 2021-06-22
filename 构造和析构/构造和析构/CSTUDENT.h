#pragma once
#include<string.h>
#include<stdio.h>
class CSTUDENT
{
private:
    char* m_szName;
    int m_nId;
    int m_nScore;

public:
    CSTUDENT();

    CSTUDENT(const char* szName, int nId, int nScore);

    ~CSTUDENT();

    CSTUDENT(CSTUDENT& other);

};

