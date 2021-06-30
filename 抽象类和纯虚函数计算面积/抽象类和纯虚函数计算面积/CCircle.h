#pragma once
#include "CShape.h"
class CCircle :
    public CShape
{
private:
    int m_nR;
    float m_nArea;
    char m_szName[20];
public:
    CCircle();
    void Area();
    void SetR();
    void GetArea();
    void GetName();
    ~CCircle();
  
    
};

