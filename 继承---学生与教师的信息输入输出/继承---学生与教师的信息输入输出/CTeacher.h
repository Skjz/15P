#pragma once
#include "CPerson.h"
class CTeacher :
    public CPerson
{
    private:
        char szTitle[20];
        char szDepartment[20];
public:
    CTeacher();
    void SetTitle();
    void GetTitle();
    void SetDepartment();
    void GetDepartment();
};

