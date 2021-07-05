#pragma once
#include"CPerson.h"
class CStudent :
    public CPerson
{
private:
    int m_nClassCode;
    int m_nScore;
public:
    CStudent(int nClassCode=0,int nScore= 0);
    void SetClassCode();
    void SetScore();

};

