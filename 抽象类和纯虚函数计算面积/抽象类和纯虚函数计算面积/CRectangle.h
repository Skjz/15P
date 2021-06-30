#pragma once
#include "CShape.h"
class CRectangle :
    public CShape
{
private:
    int m_nLenth;
    int m_nWidth;
    int m_nRectArea;
    char m_szName[20];
public:
    void Area();
    void SetLenth(int nLenth);
    void SetWidth(int nWidth);
    void GetName();
    void GetArea();
    CRectangle();
    ~CRectangle();
};

