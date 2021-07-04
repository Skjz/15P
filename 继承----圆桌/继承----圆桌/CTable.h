#pragma once
class CTable
{
private:
    double m_dblHeight;
    char m_szColor[20];

public:
    CTable(double dblHeight,const char *szColor);
    double GetHeight();
    void GetColor();
};

