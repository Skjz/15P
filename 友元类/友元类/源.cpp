#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


class CTeacher
{
public:
    void Get_Stu_Info(CStudent obj);
    void Set_Stu_Id(unsigned short int nSid,CStudent obj);
};
class CStudent
{
    CStudent() :m_nSid(0),m_szName("0")
    {

    }
    friend CTeacher;
private:
    unsigned short int m_nSid;
    char m_szName[20];
};

void CTeacher::Get_Stu_Info(CStudent obj)
{
    printf("%s\n", obj.m_szName);
    printf("%d\n", obj.m_nSid);
}
void CTeacher::Set_Stu_Id(unsigned short int nSid,CStudent obj)
{
    obj.m_nSid = nSid;
}