#pragma once
class CPerson
{
private:
    int m_nCode;
    char m_szName[20];
public:
    CPerson();
    void SetCode();
    void SetName();
    void GetCode();
    void GetName();
};

